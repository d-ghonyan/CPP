#pragma once

#include <map>
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

#include "Date.hpp"

class InvalidNumber : public std::exception { const char *what () const throw(); };
class NumberOutOfRange : public std::exception { const char *what () const throw(); };

float str2float (std::string str);
std::map<Date, std::string> readFile(std::string filename, char delim);
float getExchangeRate(Date date, std::map<Date, std::string> pairs);
std::string trim(std::string to_trim);
