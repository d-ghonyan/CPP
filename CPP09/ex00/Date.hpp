#pragma once

#include <iostream>
#include <sstream>

std::string trim(std::string to_trim);

#define LEAP_YEAR(x) ((x % 400 == 0) || (x % 100 != 0 && x % 4 == 0))

typedef enum e_short {
	FEB = 2,
	APR = 4,
	JUN = 6,
	SEP = 9,
	NOV = 11
} t_short;

class Date
{
private:
	long y, m, d;
	std::string year, month, day;

	void parse_date();
	void is_num();
	long str2int(std::string str, int limit = INT_MAX);
	void check_range(long y, long m, long d);

public:
	Date(std::string date);

	bool operator<(const Date& lhs) const;
	bool operator==(const Date& lhs) const;
	bool operator<=(const Date& lhs) const;

	long getYear() const;
	long getMonth() const;
	long getDay() const;

	class InvalidDateException : public std::exception { const char *what () const throw(); };
	class DateOutOfRange : public std::exception { const char *what () const throw(); };
	
	~Date();
};

std::ostream& operator<<(std::ostream &os, const Date& date);
