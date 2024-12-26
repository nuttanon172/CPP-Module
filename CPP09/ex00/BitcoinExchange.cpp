#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : minDate(0)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	*this = obj;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if (this != &obj)
	{
		exchangeRateData = obj.exchangeRateData;
		inputData = obj.inputData;
		minDate = obj.minDate;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::readFiles(std::ifstream &dataFile)
{
	std::string buffer, key, value;
	size_t pos, nline = 0;

	// read data.csv
	std::getline(dataFile, buffer);
	if (buffer != "date,exchange_rate")
	{
		std::cerr << "Error: First line of data.csv should be \"date,exchange_rate\"\n";
		return false;
	}
	nline++;
	while (std::getline(dataFile, buffer))
	{
		if ((pos = buffer.find(',')) == std::string::npos)
		{
			std::cerr << "Error: format data \"yyyy-mm-dd,value\" line " << nline + 1 << std::endl;
			return false;
		}
		key = buffer.substr(0, pos);
		value = buffer.substr(pos + 1);
		if (!isValidDate(key))
			return false;
		else if (!isValuePositive(value))
		{
			std::cerr << "Error: format value " << value << std::endl;
			return false;
		}
		else if (key.empty() || value.empty())
		{
			std::cerr << "Error: format data \"yyyy-mm-dd,value\" => " << buffer << std::endl;
			return false;
		}
		if (minDate > convertDate(key) || minDate == 0)
			minDate = convertDate(key);
		exchangeRateData[convertDate(key)] = convertValueDouble(value);
		nline++;
	}
	return true;
}

bool BitcoinExchange::isValidDate(std::string &date)
{
	std::string year, month, day, format = "yyyy-mm-dd";
	size_t count = 0;

	if (date.size() != format.size())
	{
		std::cerr << "Error: format input \"yyyy-mm-dd | value\" => " << date << std::endl;
		return false;
	}
	for (size_t i = 0; date[i]; i++)
	{
		if (!isdigit(date[i]) && date[i] != '-')
		{
			std::cerr << "Error: format input \"yyyy-mm-dd | value\" => " << date << std::endl;
			return false;
		}
		if (date[i] == '-')
			count++;
	}
	if (count != 2)
	{
		std::cerr << "Error: format input \"yyyy-mm-dd | value\" => " << date << std::endl;
		return false;
	}
	year = date.substr(0, date.find('-'));
	month = date.substr(year.size() + 1, 2);
	day = date.substr(date.find_last_of('-') + 1);
	if (year.size() != 4 || month.size() != 2 || day.size() != 2)
	{
		std::cerr << "Error: format input \"yyyy-mm-dd | value\" => " << date << std::endl;
		return false;
	}
	if (!isValidLeapYear(date))
		return false;
	return true;
}

bool BitcoinExchange::isValidValue(std::string &value)
{
	std::stringstream ss(trimString(value, " \t"));
	double nbr;

	ss >> nbr;
	if (ss.fail() || !ss.eof())
	{
		std::cerr << "Error: convert number failed." << std::endl;
		return false;
	}
	if (nbr > INT_MAX)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	else if (nbr < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	else if (nbr > 1000)
	{
		std::cerr << "Error: input value must be between 0 and 1000." << std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::isValuePositive(std::string &value)
{
	std::stringstream ss(value);
	float nbr;

	ss >> nbr;
	if (ss.fail() || !ss.eof())
	{
		std::cerr << "Error: convert number failed." << std::endl;
		return false;
	}
	else if (nbr < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	return true;
}

float BitcoinExchange::convertValueFloat(std::string &value)
{
	std::stringstream ss(trimString(value, " \t"));
	float nbr;

	ss >> nbr;
	if (ss.fail() || !ss.eof())
	{
		std::cerr << "Error: convert value failed." << std::endl;
		return false;
	}
	return nbr;
}

double BitcoinExchange::convertValueDouble(std::string &value)
{
	std::stringstream ss(trimString(value, " \t"));
	double nbr;

	ss >> nbr;
	if (ss.fail() || !ss.eof())
	{
		std::cerr << "Error: convert value failed." << std::endl;
		return false;
	}
	return nbr;
}

size_t BitcoinExchange::convertDate(const std::string &date)
{
	std::string year, month, day;
	std::stringstream ss;
	size_t nbr;

	year = date.substr(0, date.find('-'));
	month = date.substr(year.size() + 1, 2);
	day = date.substr(date.find_last_of('-') + 1);
	ss << year << month << day;
	ss >> nbr;
	return nbr;
}

void BitcoinExchange::trade(std::ifstream &inputFile)
{
	std::map<size_t, float>::iterator it;
	std::map<size_t, double>::iterator itd;
	std::string buffer, key, value;
	size_t date_tmp, pos;

	// read input file
	std::getline(inputFile, buffer);
	if (buffer != "date | value")
	{
		std::cerr << "Error: First line of input.txt should be \"date | value\"" << std::endl;
		return;
	}
	while (std::getline(inputFile, buffer))
	{
		if ((pos = buffer.find(" | ")) == std::string::npos)
		{
			if (trimString(buffer, " \t").size() == 0)
				continue;
			std::cerr << "Error: bad input => " << buffer << std::endl;
			continue;
		}
		key = buffer.substr(0, pos);
		value = buffer.substr(pos + 3);
		if (!isValidDate(key))
			continue;
		else if (!isValidValue(value))
			continue;
		if (key.empty() || value.empty())
		{
			std::cerr << "Error: format input \"yyyy-mm-dd | value\" => " << buffer << std::endl;
			continue;
		}
		inputData.insert(std::make_pair(convertDate(key), convertValueFloat(value)));
		it = inputData.begin();
		itd = exchangeRateData.find(it->first);
		date_tmp = it->first;
		try
		{
			while (itd == exchangeRateData.end())
			{
				date_tmp = minusDay(date_tmp);
				itd = exchangeRateData.find(date_tmp);
			}
			std::cout << std::setprecision(6);
			std::cout << key << " => " << it->second << " = ";
			std::cout << std::setprecision(7);
			std::cout << it->second * itd->second << std::endl;
		}
		catch (std::out_of_range &e)
		{
			std::cerr << e.what() << std::endl;
		}
		inputData.erase(it->first);
	}
}

bool BitcoinExchange::isLeapYear(size_t &year)
{
	return ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0));
}

bool BitcoinExchange::isValidLeapYear(std::string &date)
{
	size_t day, month, year;
	size_t dayInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	year = convertDate(date) / 10000;		 // 20200112 / 10000 => 2020
	month = (convertDate(date) / 100) % 100; // 20200112 => 202001 => 01
	day = convertDate(date) % 100;
	if (isLeapYear(year))
		dayInMonth[2 - 1] = 29;
	if (month > 12 || day > 32 || day > dayInMonth[month - 1])
	{
		std::cerr << "Error: incorrect date." << std::endl;
		return false;
	}
	return true;
}

size_t BitcoinExchange::minusDay(std::size_t date)
{
	int dayInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	size_t year, month, day, result;
	year = date / 10000;
	month = (date / 100) % 100;
	day = date % 100;
	if (isLeapYear(year))
		dayInMonth[2 - 1] = 29;
	if (day != 0 && month != 0 && year != 0)
	{
		if (month == 1 && day == 1)
		{
			month = 12;
			year -= 1;
			day = dayInMonth[month - 1];
		}
		else if (day == 1)
		{
			month -= 1;
			day = dayInMonth[month - 1];
		}
		day -= 1;
	}
	result = (year * 10000) + (month * 100) + day;
	if (result < minDate)
		throw std::out_of_range("Error: date out of db range.");
	return result;
}

std::string BitcoinExchange::trimString(std::string str, std::string skip)
{
	std::string trimmedStr;
	for (std::string::size_type i = 0; i < str.size(); i++)
	{
		bool skipChar = false;
		for (std::string::size_type j = 0; j < skip.size(); j++)
		{
			if (str[i] == skip[j])
			{
				skipChar = true;
				break;
			}
		}
		if (!skipChar)
		{
			trimmedStr += str[i];
		}
	}
	return trimmedStr;
}
