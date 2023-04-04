#include "Date.hpp"

long Date::str2int(std::string str, int limit)
{
	long		l;
	const char	*year_c = str.c_str();

    errno = 0;
    l = strtol(year_c, NULL, 10);
    if ((errno == ERANGE && (l == LONG_MAX || l == LONG_MIN)) || l > limit || l < 0)
	{
        throw DateOutOfRange();
    }
    if (errno == EINVAL && l == 0)
	{
        throw InvalidDateException();
    }
	return l;
}

void Date::is_num()
{
	for (size_t i = 0; i < year.size(); ++i)
	{
		if (year[i] < '0' || year[i] > '9')
			throw InvalidDateException();
	}

	for (size_t i = 0; i < day.size(); ++i)
	{
		if (day[i] < '0' || day[i] > '9')
			throw InvalidDateException();
	}

	for (size_t i = 0; i < month.size(); ++i)
	{
		if (month[i] < '0' || month[i] > '9')
			throw InvalidDateException();
	}	
}

Date::Date(std::string date)
{
	std::istringstream sstream(date);

	std::getline(sstream, year, '-');
	std::getline(sstream, month, '-');
	std::getline(sstream, day, '-');

	year = trim(year);
	month = trim(month);
	day = trim(day);

	parse_date();
}

const char *Date::InvalidDateException::what() const throw()
{
	return "Error: invalid date";
}

const char *Date::DateOutOfRange::what() const throw()
{
	return "Error: out of range";
}

void Date::parse_date()
{
	is_num();

	y = str2int(year);
	m = str2int(month, 12);	
	d = str2int(day, 31);	

	if (year.size() != 4 || month.size() != 2 || day.size() != 2) { throw InvalidDateException(); }

	check_range(y, m, d);
}

int is_in_arr(long num, long *arr, size_t count)
{
	for (size_t i = 0; i < count; i++)
	{
		if (arr[i] == num)
			return 1;
	}
	return 0;
}

void Date::check_range(long y, long m, long d)
{
	long shorts[5] = { FEB, APR, JUN, SEP, NOV };

	if ((is_in_arr(m, shorts, 5) && d == 31) || (m == FEB && ((!(LEAP_YEAR(y)) && d > 28) || (LEAP_YEAR(y) && d > 29))))
		throw DateOutOfRange();
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

long Date::getYear() const
{
	return y;
}
long Date::getMonth() const
{
	return m;
}
long Date::getDay() const
{
	return d;
}

std::ostream& operator<<(std::ostream &os, const Date& date)
{
	os << date.getYear() << "-" << date.getMonth() << "-" << date.getDay();
	return os;
}

Date::~Date() { }