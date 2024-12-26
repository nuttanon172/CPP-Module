#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	(void)obj;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
	(void)obj;
	return *this;
}

PmergeMe::~PmergeMe()
{
}

bool PmergeMe::initPmerge(char **av)
{
	size_t i = 1;
	std::stringstream ss;
	std::string str;

	while (av[i])
	{
		ss << av[i];
		while (ss >> str)
		{
			if (!strToSizeTVect(str) || !strToSizeTList(str))
				return false;
		}
		ss.clear();
		i++;
	}
	if (isSort())
		return false;
	return true;
}

bool PmergeMe::isSort()
{
	if (vectContainer.size() < 1)
	{
		std::cerr << "Error: container empty." << std::endl;
		return true;
	}
	std::vector<int>::const_iterator it = vectContainer.begin();
	std::vector<int>::const_iterator next_it = it;
	++next_it;
	for (; next_it != vectContainer.end(); ++it, ++next_it)
	{
		if (*it > *next_it)
			return false;
	}
	std::cout << "numbers are sorted." << std::endl;
	return true;
}

clock_t PmergeMe::sortVect()
{
	std::vector<std::pair<int, int> > vector;
	std::vector<int> main_chain;
	clock_t end;
	struggler = -1;
	// 1. Group the elements of X into ⌊ n / 2 ⌋ pairs of elements, arbitrarily, leaving one element unpaired if there is an odd number of elements.
	makePairVect(vector);
	// 3. Recursively sort the ⌊ n / 2 ⌋ larger elements from each pair, creating a sorted sequence S of ⌊ n / 2 ⌋ of the input elements, 
	// in ascending order, using the merge-insertion sort.
	mergeSortVect(vector.begin(), vector.end());
	std::vector<std::pair<int, int> >::iterator it_pair = vector.begin();
	// 4.Insert at the start of S the element that was paired with the first and smallest element of S.
	main_chain.push_back(it_pair->second); // < --- (4) cause vector slow when insert at front
	for (it_pair = vector.begin(); it_pair != vector.end(); it_pair++)
	{
		main_chain.push_back(it_pair->first); // < -- (3) creating a sorted sequence S of ⌊ n / 2 ⌋
	}
	// 5. Insert the remaining ⌈ n / 2 ⌉ − 1 elements of X ∖ S into S, one at a time, with a specially chosen insertion ordering described below. 
	// Use binary search in subsequences of S (as described below) to determine the position at which each element should be inserted.
	for (it_pair = ++vector.begin(); it_pair != vector.end(); it_pair++)
	{
		std::vector<int>::iterator it = binary_serch_vect(main_chain.begin(), main_chain.end(), it_pair->second);
		main_chain.insert(it, it_pair->second);
	}
	if (struggler != -1)
	{
		std::vector<int>::iterator it = binary_serch_vect(main_chain.begin(), main_chain.end(), struggler);
		main_chain.insert(it, struggler);
	}
	end = clock();
	std::cout << "after:  ";printContainer(main_chain);
	vectContainer = main_chain;
	return end;
}


void PmergeMe::makePairVect(std::vector<std::pair<int, int> > &vector)
{
	if (vectContainer.size() % 2 != 0)
	{
		struggler = vectContainer.back();
		vectContainer.pop_back();
	}
	// 2. Perform ⌊ n / 2 ⌋ comparisons, one per pair, to determine the larger of the two elements in each pair.
	std::vector<int>::iterator it = vectContainer.begin();
	while (it != vectContainer.end())
	{
		int first = *it++;
		if (it == vectContainer.end())
			break;
		int second = *it++;
		if (first < second)
			std::swap(first, second);
		vector.push_back(std::make_pair(first, second));
	}
}

void PmergeMe::mergeSortVect(std::vector<std::pair<int, int> >::iterator begin, std::vector<std::pair<int, int> >::iterator end)
{
	if (std::distance(begin, end) <= 1)
		return;
	std::vector<std::pair<int, int> >::iterator mid = begin;
	std::advance(mid, std::distance(begin, end) / 2);
	mergeSortVect(begin, mid);
	mergeSortVect(mid, end);
	mergeVect(begin, mid, end);
}

void PmergeMe::mergeVect(std::vector<std::pair<int, int> >::iterator begin, std::vector<std::pair<int, int> >::iterator mid, std::vector<std::pair<int, int> >::iterator end)
{
	std::vector<std::pair<int, int> > firstPair(begin, mid);
	std::vector<std::pair<int, int> > secondPair(mid, end);
	std::vector<std::pair<int, int> >::iterator first_it = firstPair.begin();
	std::vector<std::pair<int, int> >::iterator second_it = secondPair.begin();
	std::vector<std::pair<int, int> >::iterator it = begin;

	while (first_it != firstPair.end() && second_it != secondPair.end())
	{
		if (first_it->first < second_it->first)
			*it++ = *first_it++;
		else
			*it++ = *second_it++;
	}
	while (first_it != firstPair.end())
		*it++ = *first_it++;
	while (second_it != secondPair.end())
		*it++ = *second_it++;
}

std::vector<int>::iterator PmergeMe::binary_serch_vect(std::vector<int>::iterator begin, std::vector<int>::iterator end, int nbr)
{
	std::vector<int>::iterator left = begin;
	std::vector<int>::iterator right = end;
	std::vector<int>::iterator mid;

	while (std::distance(left, right) > 1)
	{
		mid = left;
		std::advance(mid, std::distance(left, right) / 2);
		if (nbr > *mid)
			left = mid;
		else
			right = mid;
	}
	if (nbr > *left)
		return right;
	return left;
}

void PmergeMe::makePairList(std::list<std::pair<int, int> > &list)
{
	if (listContainer.size() % 2 != 0)
	{
		struggler = listContainer.back();
		listContainer.pop_back();
	}
	std::list<int>::iterator it = listContainer.begin();
	while (it != listContainer.end())
	{
		int first = *it++;
		if (it == listContainer.end())
			break;
		int second = *it++;
		if (first < second)
			std::swap(first, second);
		list.push_back(std::make_pair(first, second));
	}
}

clock_t PmergeMe::sortList()
{
	std::list<std::pair<int, int> > list;
	std::list<int> main_chain;
	clock_t end;
	struggler = -1;

	makePairList(list);
	mergeSortList(list);
	std::list<std::pair<int, int> >::iterator it_pair = list.begin();
	for (it_pair = list.begin(); it_pair != list.end(); it_pair++)
	{
		main_chain.push_back(it_pair->first);
	}
	main_chain.push_front(list.begin()->second);
	for (it_pair = ++list.begin(); it_pair != list.end(); it_pair++)
	{
		std::list<int>::iterator it = binary_serch_list(main_chain.begin(), main_chain.end(), it_pair->second);
		main_chain.insert(it, it_pair->second);
	}
	if (struggler != -1)
	{
		std::list<int>::iterator it = binary_serch_list(main_chain.begin(), main_chain.end(), struggler);
		main_chain.insert(it, struggler);
	}
	end = clock();
	listContainer = main_chain;
	//std::cout << "listContainer: "; printContainer(listContainer);
	return end;
}

void PmergeMe::mergeSortList(std::list<std::pair<int, int> > &list)
{
	if (std::distance(list.begin(), list.end()) <= 1)
		return;
	std::list<std::pair<int, int> >::iterator mid = list.begin();
	std::advance(mid, list.size() / 2);
	std::list<std::pair<int, int> > left_container(list.begin(), mid);
	std::list<std::pair<int, int> > right_container(mid, list.end());
	mergeSortList(left_container);
	mergeSortList(right_container);
	mergeList(left_container, right_container, list);
}

void PmergeMe::mergeList(std::list<std::pair<int, int> > &leftContainer, std::list<std::pair<int, int> > &rightContainer, std::list<std::pair<int, int> > &container)
{
	std::list<std::pair<int, int> >::iterator itl = leftContainer.begin();
	std::list<std::pair<int, int> >::iterator itr = rightContainer.begin();

	container.clear();
	while (itl != leftContainer.end() && itr != rightContainer.end())
	{
		if (itl->first < itr->first)
			container.push_back(*itl++);
		else
			container.push_back(*itr++);
	}
	container.insert(container.end(), itl, leftContainer.end());
	container.insert(container.end(), itr, rightContainer.end());
}

std::list<int>::iterator PmergeMe::binary_serch_list(std::list<int>::iterator begin, std::list<int>::iterator end, int nbr)
{
	std::list<int>::iterator left = begin;
	std::list<int>::iterator right = end;
	std::list<int>::iterator mid;

	while (std::distance(left, right) > 1)
	{
		mid = left;
		std::advance(mid, std::distance(left, right) / 2);
		if (nbr > *mid)
			left = mid;
		else
			right = mid;
	}
	if (nbr > *left)
		return right;
	return left;
}

void PmergeMe::raceTime()
{
	clock_t startV, endV;
	clock_t startL, endL;

	std::cout << "before: ";
	printContainer(vectContainer);
	startV = clock();
	endV = sortVect();
	startL = clock();
	endL = sortList();
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << vectContainer.size() << " elements with std::vector<int> : ";
	std::cout << (static_cast<double>(endV - startV) / CLOCKS_PER_SEC) * 1000000 << "us\n";
	std::cout << "Time to process a range of " << listContainer.size() << " elements with std::list<int>   : ";
	std::cout << (static_cast<double>(endL - startL) / CLOCKS_PER_SEC) * 1000000 << "us\n";
}

template <typename T>
void PmergeMe::printContainer(T &container)
{
	typename T::iterator it = container.begin();
	for (; it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

bool PmergeMe::strToSizeTVect(std::string &str)
{
	std::stringstream ss(str);
	long nbr;

	ss >> nbr;
	if (ss.fail() || !ss.eof())
	{
		std::cerr << "Error: convert number failed." << std::endl;
		return false;
	}
	else if (nbr > INT_MAX)
	{
		std::cerr << "Error: number bigger than int max." << std::endl;
		return false;
	}
	else if (nbr < 0)
	{
		std::cerr << "Error: number less than 0." << std::endl;
		return false;
	}
	vectContainer.push_back(nbr);
	return true;
}

bool PmergeMe::strToSizeTList(std::string &str)
{
	std::stringstream ss(str);
	size_t nbr;

	ss >> nbr;
	if (ss.fail() || !ss.eof())
	{
		std::cerr << "Error: convert number failed." << std::endl;
		return false;
	}
	else if (nbr > INT_MAX)
	{
		std::cerr << "Error: number bigger than int max." << std::endl;
		return false;
	}
	listContainer.push_back(nbr);
	return true;
}
