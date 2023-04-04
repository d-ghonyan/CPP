#include "ex02.hpp"

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
		std::list<int>::iterator j(it);
		std::list<int>::iterator k(it);

		--k;
		while (j != nums.begin() && *j < *k)
		{
			std::iter_swap(j, k);
			--j;
			--k;
		}
	}
}
