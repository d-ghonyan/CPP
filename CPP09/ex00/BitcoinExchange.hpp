#pragma once

#include <map>
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
	float findExchangeRate(Date date) const;
public:
	BitcoinExchange(std::string filename, char delim);
	BitcoinExchange(const BitcoinExchange& other);

	BitcoinExchange& operator=(const BitcoinExchange& lhs);

	void getExchangeRate(std::string inputFile, char delim) const;

	class InvalidFileException : public std::exception { const char *what () const throw(); };
	class DateNotFoundException : public std::exception { const char *what () const throw(); };
	class InvalidNumberException : public std::exception { const char *what () const throw(); };
	
	~BitcoinExchange();
};

std::ostream& operator<<(std::ostream &os, const BitcoinExchange& BitcoinExchange);
