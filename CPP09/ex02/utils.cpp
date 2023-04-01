#include "ex02.hpp"

double	gettime(t_timeval start)
{
	t_timeval	now;

	gettimeofday(&now, NULL);
	return (((double)((now.tv_sec - start.tv_sec) * 1000)
		+ ((double)(now.tv_usec - start.tv_usec) / 1000)));
}

void print(std::vector<int> nums)
{
	for (size_t i = 0; i < nums.size(); i++)
	{
		std::cout << nums[i] << " ";
	}
	std::cout << "\n";
}

void insertion_sort(std::vector<int>& nums)
{
	for (size_t i = 1; i < nums.size(); ++i)
	{
		int j = i;
		while (j > 0 && nums[j] < nums[j - 1])
		{
			swap(nums[j], nums[j - 1]);
			j--;
		}
	}
}

void insertion_sort(std::list<int>& nums)
{
	std::list<int>::iterator begin = nums.begin();

	++begin;

	for (std::list<int>::iterator it = begin; it != nums.end(); ++it)
	{
		std::list<int>::iterator j = it;
		std::list<int>::iterator cp = j;

		std::list<int>::iterator k = --cp;

		while (j != nums.begin() && *j < *k)
		{
			std::cout << "hello\n";
			swap(*j, *k);
			--j;
		}
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
