#include "PmergeMe.hpp"

void PmergeMe::print_vector(size_t precision) const
{
	for (size_t i = 0; i < nums_v.size() && i < precision; i++)
	{
		std::cout << nums_v[i] << " ";
	}
	if (nums_v.size() >= precision)
		std::cout << "[ ... ] ";
	std::cout << "\n";
}

void PmergeMe::print_list(size_t precision) const
{
	size_t size = nums_l.size();
	std::list<int> tmp = nums_l;

	for (size_t i = 0; !tmp.empty() && i < precision; ++i)
	{
		std::cout << tmp.front() << " ";
		tmp.pop_front();
	}
	if (size > precision)
		std::cout << "[ ... ] ";
	std::cout << "\n";
}
