#pragma once

#include <list>
#include <cmath>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

class PmergeMe
{
	char **nums;
	std::list<int> nums_l;
	std::vector<int> nums_v;
	void merge_sort(std::list<int>& nums);
	void merge_sort(std::vector<int>& nums);
	void insertion_sort(std::list<int>& nums);
	void insertion_sort(std::vector<int>& nums);
	void insert(std::list<int>& nums, std::list<int> b);
	void insert(std::vector<int>& nums, std::vector<int> b);
public:
	PmergeMe(char **argv);
	PmergeMe(const PmergeMe& other);

	static long str2int (std::string str);

	void sortList();
	void sortVector();
	void print_list(size_t precision) const ;
	void print_vector(size_t precision) const ;
	PmergeMe& operator=(const PmergeMe& lhs);

	class InvalidNumberException : public std::exception { const char *what () const throw(); };
	class NumberOutOfRangeException : public std::exception { const char *what () const throw(); };

	~PmergeMe();
};
