#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <sstream>
#include <climits>
#include <ctime>
#include <iomanip>

class PmergeMe
{
private:
	std::vector<int> vectContainer;
	std::list<int> listContainer;
	long struggler;
	
	void makePairVect(std::vector<std::pair<int, int> > &vector);
	clock_t sortVect();
	void mergeSortVect(std::vector<std::pair<int, int> >::iterator begin, std::vector<std::pair<int, int> >::iterator end);
	void mergeVect(std::vector<std::pair<int, int> >::iterator begin, std::vector<std::pair<int, int> >::iterator mid, std::vector<std::pair<int, int> >::iterator end);
	std::vector<int>::iterator binary_serch_vect(std::vector<int>::iterator begin, std::vector<int>::iterator end, int nbr);
	
	void makePairList(std::list<std::pair<int, int> > &list);
	clock_t sortList();
	void mergeSortList(std::list<std::pair<int, int> > &list);
	void mergeList(std::list<std::pair<int, int> > &leftContainer, std::list<std::pair<int, int> > &rightContainer, std::list<std::pair<int, int> > &container);
	std::list<int>::iterator binary_serch_list(std::list<int>::iterator begin, std::list<int>::iterator end, int nbr);

	template <typename T>
	void printContainer(T &container);
	bool strToSizeTVect(std::string &str);
	bool strToSizeTList(std::string &str);
	bool isSort();

public:
	PmergeMe();
	PmergeMe(const PmergeMe &obj);
	PmergeMe &operator=(const PmergeMe &obj);
	~PmergeMe();
	bool initPmerge(char **av);
	void raceTime();
};

#endif
