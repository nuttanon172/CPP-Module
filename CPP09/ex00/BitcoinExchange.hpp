#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <climits>
#include <map>
#include <iomanip>
#include <string>

class BitcoinExchange
{
private:
	std::map<size_t, double> exchangeRateData;
	std::map<size_t, float> inputData;
	size_t minDate;
	size_t convertDate(const std::string &date);
	float convertValueFloat(std::string &value);
	double convertValueDouble(std::string &value);
	std::string trimString(std::string str, std::string skip);
	bool isValidDate(std::string &date);
	bool isValidValue(std::string &value);
	bool isValuePositive(std::string &value);
	bool isValidLeapYear(std::string &date);
	size_t minusDay(std::size_t date);
	bool isLeapYear(size_t &year);

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &obj);
	BitcoinExchange &operator=(const BitcoinExchange &obj);
	~BitcoinExchange();
	bool readFiles(std::ifstream &dataFile);
	void trade(std::ifstream &inputFile);
};

#endif
