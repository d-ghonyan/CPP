#pragma once

#include <cmath>
#include <stack>
#include <iostream>

#define IS_OPERATION(s, i) (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')

double str2double (std::string str);

class RPN
{
	std::string to_calc;
	void parse_str(std::string expression);
public:
	RPN(std::string expression);
	RPN(const RPN& other);

	void calculate();

	static double str2double(std::string str);
	static std::string trim(std::string s);

	RPN& operator=(const RPN& lhs);

	class InvalidNumberException : public std::exception { const char *what () const throw(); };
	class DivisionByZeroException : public std::exception { const char *what () const throw(); };
	class NumberOutOfRangeException : public std::exception { const char *what () const throw(); };
	class InvalidExpressionException : public std::exception { const char *what () const throw(); };
	
	~RPN();
};
