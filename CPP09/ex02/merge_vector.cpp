#include "ex02.hpp"

void insert(std::vector<int>& nums, std::vector<int> b)
{
	int n = 0;
	int power = 0;
	int start_index = 0;
	int end_index = 0;

	start_index = 0;

	for (size_t i = 0; i < b.size();)
	{
		++power;

		n = pow(2, power) - n;

		start_index += n;

		end_index = start_index - n;

		if (start_index > b.size())
			start_index = b.size();

		for (int j = start_index - 1; j >= end_index; --j)
		{
			nums.insert(std::upper_bound(nums.begin(), nums.end(), b[j]), b[j]);
			++i;
		}
	}
}

void merge_sort_vector(std::vector<int>& nums)
{
	int					unpaired;
	std::vector<int>	a;
	std::vector<int>	b;
	size_t size = nums.size() / 2 + (nums.size() % 2);

	unpaired = ((nums.size() % 2 == 0) ? -1 : nums[nums.size() - 1]);

	if (nums.size() == 2 || nums.size() == 3)
	{
		insertion_sort(nums);
		return ;
	}

	for (size_t i = 0; i < size; ++i)
	{
		if (i != size - 1 || nums.size() % 2 == 0)
		{
			int n = nums[i * 2], m = nums[i * 2 + 1];
			if (n > m)
				swap(n, m);
			a.push_back(m);
			b.push_back(n);
		}
	}
	if (unpaired != -1)
		b.push_back(unpaired);
	merge_sort_vector(a);
	insert(a, b);
	nums = a;
}
