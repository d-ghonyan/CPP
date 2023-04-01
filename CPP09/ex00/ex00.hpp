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

float str2float (std::string str);
std::map<std::string, std::string> readFile(std::string filename, char delim);
bool isequal(std::pair<std::string, std::string> pair);
float getExchangeRate(std::string date, std::map<std::string, std::string> pairs);
std::string trim(std::string to_trim);
