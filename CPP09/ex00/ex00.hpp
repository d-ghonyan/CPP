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

class InvalidNumber : public std::exception { const char *what () const throw(); };
class NumberOutOfRange : public std::exception { const char *what () const throw(); };

float str2float (std::string str);
std::string trim(std::string to_trim);
