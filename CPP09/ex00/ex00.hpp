#pragma once

#include <list>
#include <ctime>
#include <string>
#include <cctype>
#include <sstream>
#include <errno.h>
#include <fstream>
#include <utility>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define CSV_PATH "../cpp_09/data.csv"

struct isEqual
{
	isEqual(std::string a_wanted) : wanted(a_wanted) { }
	std::string wanted;
	bool operator()(std::pair<std::string, std::string> pair)
	{
		return wanted.compare(pair.first) == 0;
	}
};

float str2float (std::string str);
std::list< std::pair<std::string, std::string> > readFile(std::string filename, char delim);
bool isequal(std::pair<std::string, std::string> pair);
float getExchangeRate(std::string date, std::list< std::pair<std::string, std::string> > pairs);
std::string trim(std::string to_trim);
