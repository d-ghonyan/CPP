#pragma once

#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <climits>
#include <iostream>

#include "Date.hpp"

float str2float (std::string str);

class BitcoinExchange
{
private:
	std::map<Date, std::string> base;
	double findExchangeRate(Date date) const;
public:
	BitcoinExchange(std::string filename, char delim);
	BitcoinExchange(const BitcoinExchange& other);

	BitcoinExchange& operator=(const BitcoinExchange& lhs);

	void getExchangeRate(std::string inputFile, char delim) const;
	static bool is_double(std::string hello);
	static double str2double(std::string str);

	class InvalidFileException : public std::exception { const char *what () const throw(); };
	class DateNotFoundException : public std::exception { const char *what () const throw(); };
	class InvalidNumberException : public std::exception { const char *what () const throw(); };
	class NumberOutOfRangeException : public std::exception { const char *what () const throw(); };
	
	~BitcoinExchange();
};
