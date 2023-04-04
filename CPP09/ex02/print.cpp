#include "ex02.hpp"

void print(std::vector<int> nums, size_t precision)
{
	for (size_t i = 0; i < nums.size() && i < precision; i++)
	{
		std::cout << nums[i] << " ";
	}
	if (nums.size() >= precision)
		std::cout << "[ ... ] ";
	std::cout << "\n";
}

void print(std::list<int> nums, size_t precision)
{
	size_t size = nums.size();
	for (size_t i = 0; !nums.empty() && i < precision; ++i)
	{
		std::cout << nums.front() << " ";
		nums.pop_front();
	}
	if (size > precision)
		std::cout << "[ ... ] ";
	std::cout << "\n";
}
