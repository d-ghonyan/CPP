#include <iostream>
#include <errno.h>

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
