#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **argv): nums(argv) { }

long PmergeMe::str2int (std::string str)
{
	long 		l;
	const char	*s = str.c_str();

	errno = 0;
	l = strtol(s, NULL, 10);
	if ((errno == ERANGE && (l == LONG_MAX || l == LONG_MIN))
		 || l > INT_MAX || l < INT_MIN)
	{
		throw NumberOutOfRangeException();
	}
	if (errno == EINVAL && l == 0)
	{
		throw InvalidNumberException();
	}
	return l;
}

void PmergeMe::sortList()
{
	for (size_t i = 1; nums[i]; ++i) { nums_l.push_back(str2int(nums[i])); }
	
	merge_sort(nums_l);
}

void PmergeMe::sortVector()
{
	for (size_t i = 1; nums[i]; ++i) { nums_v.push_back(str2int(nums[i])); }
	
	merge_sort(nums_v);
}

PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& lhs) { nums = lhs.nums; return *this; }

const char *PmergeMe::InvalidNumberException::what () const throw() { return "Invalid number"; }
const char *PmergeMe::NumberOutOfRangeException::what () const throw() { return "Number out of range"; }

PmergeMe::~PmergeMe() { }