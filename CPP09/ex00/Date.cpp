#include "Date.hpp"

Date::Date(std::string date)
{
	std::string strs[3];
	std::istringstream sstream(date);

	std::getline(sstream, strs[0], '-');
	std::getline(sstream, strs[1], '-');
	std::getline(sstream, strs[2], '-');

	if (!strs[0][0] || !strs[1][0] || !strs[2][0]) { throw InvalidDateException(); }

	is_num(strs);

	y = str2int(strs[0]);
	m = str2int(strs[1], 12);
	d = str2int(strs[2], 31);

	check_range(y, m, d);
}

Date::Date(const Date& other)
{
	*this = other;
}

int Date::is_in_arr(long num, long *arr, size_t count)
{
	for (size_t i = 0; i < count; i++)
	{
		if (arr[i] == num)
			return 1;
	}
	return 0;
}

std::string Date::trim(std::string to_trim)
{
	std::string ret;

	for (size_t i = 0; i < to_trim.size(); ++i)
	{
		if (!(::isspace(to_trim[i])))
			ret.push_back(to_trim[i]);
	}
	return ret.c_str();
}

long Date::str2int(std::string str, int limit)
{
	long		l;
	const char	*year_c = str.c_str();

	errno = 0;
	l = strtol(year_c, NULL, 10);
	if ((errno == ERANGE && (l == LONG_MAX || l == LONG_MIN)) || l > limit || l <= 0)
	{
		throw DateOutOfRange();
	}
	return l;
}

void Date::is_num(std::string strs[3])
{
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < strs[i].size(); ++j)
		{
			if (strs[i][j] < '0' || strs[i][j] > '9')
				throw InvalidDateException();
		}
	}
}

void Date::check_range(long y, long m, long d)
{
	long shorts[5] = { FEB, APR, JUN, SEP, NOV };

	if ((is_in_arr(m, shorts, 5) && d == 31) || (m == FEB && ((!(LEAP_YEAR(y)) && d > 28) || (LEAP_YEAR(y) && d > 29))))
		throw DateOutOfRange();
}

Date& Date::operator=(const Date& lhs)
{
	y = lhs.y;
	m = lhs.m;
	d = lhs.d;

	return *this;
}

bool Date::operator<(const Date& lhs) const
{
	if (y < lhs.y)
		return true;
	if (y == lhs.y)
	{
		if (m < lhs.m)
			return true;
		if (m == lhs.m)
		{
			if (d < lhs.d)
				return true;
		}
	}
	return false;
}

bool Date::operator==(const Date& lhs) const
{
	return (y == lhs.y && m == lhs.m && d == lhs.d);
}

bool Date::operator<=(const Date& lhs) const
{
	return (*this < lhs || *this == lhs);
}

long Date::getYear() const { return y; }

long Date::getMonth() const { return m; }

long Date::getDay() const { return d; }

std::ostream& operator<<(std::ostream &os, const Date& date)
{
	os << date.getYear() << "-" << date.getMonth() << "-" << date.getDay();
	return os;
}

const char *Date::InvalidDateException::what() const throw() { return "Error: invalid date"; }

const char *Date::DateOutOfRange::what() const throw() { return "Error: date out of range"; }

Date::~Date() { }