#include "ex00.hpp"

const char *InvalidNumber::what() const throw() { return "Invalid number"; }
const char *NumberOutOfRange::what() const throw() { return "Number out of range"; }

bool is_float(std::string hello)
{
	size_t i = 0;
	bool point = false;

	while (std::isspace(hello[i])) ++i ;

	if (hello[i] == '+' || hello[i] == '-') ++i;

	for (; i < hello.size(); ++i)
	{
		if (hello[i] == '.' && !point)
			point = true;
		else if (hello[i] == '.' && point)
			return false;
		if ((hello[i] < '0' || hello[i] > '9') && hello[i] != '.')
			return false;
	}
	return true;
}

float str2float (std::string str)
{
	float 		l;
	const char	*s = str.c_str();

	errno = 0;

	if (!is_float(str)) { throw InvalidNumber(); }

	l = strtof(s, NULL);

	if (errno == ERANGE) { throw NumberOutOfRange(); }

	return l;
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

std::string trim(std::string to_trim)
{
	std::string ret;

	for (size_t i = 0; i < to_trim.size(); ++i)
	{
		if (!(::isspace(to_trim[i])))
			ret.push_back(to_trim[i]);
	}
	return ret.c_str();
}
