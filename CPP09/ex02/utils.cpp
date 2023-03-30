#include <cstdlib>
#include <iostream>
#include <climits>
#include <vector>
void print(std::vector<int> nums)
{
	for (size_t i = 0; i < nums.size(); i++)
	{
		std::cout << nums[i] << " ";
	}
	std::cout << "\n";
}

void print(std::vector < std::vector<int> > nums)
{
	for (size_t i = 0; i < nums.size(); i++)
	{
		std::cout << nums[i][0] << " ";
		if (nums[i].size() == 2)
			std::cout << nums[i][1] << " ";
		std::cout << "\n";
	}
}

void swap(int &a, int &b)
{
	int temp = a;

	a = b;

	b = temp;
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
    if (errno == EINVAL && l == 0)
	{
        throw "invalid argument";
    }
    return l;
}

int	argv_check(char **argv)
{
	for (size_t i = 1; argv[i]; ++i)
	{
		for (size_t j = 0; argv[i][j]; ++j)
		{
			if (argv[i][j] > '9' || argv[i][j] < '0')
			{
				std::cerr << "Error: you're dumb\n";
				return 69;
			}
		}
		try { str2int(argv[i]); }
		catch (const char *e)
		{ std::cerr << "Error: " << e << '\n'; exit (1); }
	}
	return 0;
}
