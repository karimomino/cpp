#ifndef EX00_BITCOINEXCHANGE_HPP_
#define EX00_BITCOINEXCHANGE_HPP_

#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>

enum valError{
VALID,
TOO_LARGE,
NOT_POSITIVE
};

class BitcoinExchange {
private:
	BitcoinExchange();

	std::map<std::string, double> _data;
	double getExchangeRate(const std::string &date);
	bool isValidDate(const std::string &date);
	valError isValidValue(const double &value);
public:
	void calculate(const std::string &filename);
	BitcoinExchange(const std::string &path);
	BitcoinExchange(const BitcoinExchange &rhs);
};

#endif
