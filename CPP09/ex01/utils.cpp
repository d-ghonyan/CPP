#include <iostream>
#include <errno.h>

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

long str2int (std::string str)
{
    long 		l;
	const char	*s = str.c_str();

    errno = 0;
    l = strtol(s, NULL, 10);
    if ((errno == ERANGE && (l == LONG_MAX || l == LONG_MIN)) || l > INT_MAX || l < INT_MIN) {
        throw "out of range";
    }
    if (errno == EINVAL && l == 0) {
        throw "invalid argument";
    }
    return l;
}

double str2double (std::string str)
{
	double 		l;
	const char	*s = str.c_str();

	errno = 0;

	if (!is_float(str)) { throw "Invalid number"; }

	l = strtod(s, NULL);

	if (errno == ERANGE) { throw "Out of range"; }

	return l;
}

int	argv_check(std::string s)
{
	std::string valid("0123456789+-*/ ");

	for (size_t i = 0; i < s.size(); ++i)
	{
		if (valid.find(s[i]) == std::string::npos)
		{
			std::cerr << "Error: invalid numbers\n";
			return 1;
		}
	}
	return 0;
}
