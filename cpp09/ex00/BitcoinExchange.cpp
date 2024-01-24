#include "BitcoinExchange.hpp"

static int countOccurrences(const std::string& str, const std::string& substring) {
    int count = 0;
    std::string::size_type pos = 0;

    while ((pos = str.find(substring, pos)) != std::string::npos) {
        pos += substring.length();
        ++count;
		if (count > 2)
			break ;
    }

    return count;
}

BitcoinExchange::BitcoinExchange(const std::string& filename) {
	std::ifstream file(filename.c_str());
	std::string line;
	size_t lineNum = 1;
	std::getline(file, line);
	
	while (std::getline(file, line)) {
		std::string::size_type delimiter_pos = line.find(',');
		lineNum++;
		if (delimiter_pos == std::string::npos || countOccurrences(line , ",") != 1) {
			std::cerr << "Error: Invalid format in database line #" <<lineNum << " => " << line << std::endl;
			continue;
		}

		std::stringstream ss;
		ss << line;
		std::string date, rate_db;
		getline(ss, date, ',');
		getline(ss, rate_db);

		double rate;
		std::stringstream rss(rate_db);
		if (!(rss >> rate)) {
			std::cerr << "Error: Invalid rate in database line #" <<lineNum << " => " << rate_db << std::endl;
			continue;
		}

		_data[date] = rate;
	}
}

double BitcoinExchange::getExchangeRate(const std::string &date) {
	std::map<std::string, double>::iterator it = _data.lower_bound(date);
	if (it->first != date && it != _data.begin())
		--it;
	
	if (it != _data.end())
		return it->second;

	return -1.0;
}

bool BitcoinExchange::isValidDate(const std::string& date) {
	if (countOccurrences(date , "-") != 2)
		return false;

	std::stringstream ss;
	ss << date;
	std::string year_str, month_str, day_str;
	getline(ss, year_str, '-');
	getline(ss, month_str, '-');
	getline(ss, day_str);

	int year, month, day;
	std::istringstream year_ss(year_str), month_ss(month_str), day_ss(day_str);

	if (!(year_ss >> year) || !(month_ss >> month) || !(day_ss >> day))
		return false;

	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	switch (month) {
        case 2: {
			bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
            if ((isLeapYear && day > 29) || (!isLeapYear && day > 28)) {
                return false;
            }
            break;
		}
        case 4:
        case 6:
        case 9:
        case 11:
            if (day > 30) {
                return false;
            }
            break;
        default:
            if (day > 31 || day < 1) {
                return false;
            }
            break;
    }
	return true;
}

valError BitcoinExchange::isValidValue(const double &value) {
	if ( value < 0 )
		return NOT_POSITIVE;
	 if ( value > 1000 )
	 	return TOO_LARGE;
	return VALID;
}

void BitcoinExchange::calculate(const std::string &filename) {
	std::ifstream file(filename.c_str(), std::ios::in);
	if (!file) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        exit(1);
    }

	std::string line;
	size_t lineNum = 1;
	std::getline(file, line);
	while (std::getline(file, line)) {
		lineNum++;
		std::stringstream ss(line);
		std::string date;
		double value;
		char delimiter;

		if (!(ss >> date >> delimiter >> value)) {
			std::cerr << "Error: Unable to parse line #" <<lineNum << " => " << line << std::endl;
			continue;
		}

		if (delimiter != '|') {
			std::cerr << "Error: Expected '|' delimiter in line #" <<lineNum << " => " << line << std::endl;
			continue;
		}

		if (!isValidDate(date)) {
			std::cerr << "Error: Invalid date format in line #" <<lineNum << " => " << line << std::endl;
			continue;
		}

		valError val_check = isValidValue(value);
		if (val_check) {
			std::string err_msg;
			if (val_check == TOO_LARGE)
				err_msg = "too large ";
			else
				err_msg = "not a positive ";
			std::cerr<< "Error: Invalid value " << err_msg << "in line #" << lineNum << " => " << line << std::endl;
			continue;
		}

		double exchangeRate = getExchangeRate(date);
		if (exchangeRate == -1.0) {
			std::cerr << "Error: No exchange rate available for date => " << date << std::endl;
			continue;
		}

		std::cout << date << " => " << value << " = " << value * exchangeRate << std::endl;
	}
}
