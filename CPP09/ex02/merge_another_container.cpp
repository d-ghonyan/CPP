#include "ex02.hpp"

void insert(std::list<int>& nums, std::list<int> b)
{
	int n = 0;
	int power = 0;
	size_t end_index = 0;
	size_t start_index = 0;

	size_t size = b.size();

	int arr[b.size()];

	for (size_t i = 0; !b.empty(); ++i)
	{
		arr[i] = b.front();
		b.pop_front();
	}

	for (size_t i = 0; i < size;)
	{
		++power;

		n = pow(2, power) - n;

		start_index += n;

		end_index = start_index - n;

		if (start_index > size)
			start_index = size;

		for (size_t j = start_index - 1; j >= end_index;)
		{
			nums.insert(std::upper_bound(nums.begin(), nums.end(), arr[j]), arr[j]);
			++i;
			if (j == 0)
				break ;
			--j;
		}
	}
}

void merge_sort(std::list<int>& nums)
{
	int				unpaired;
	std::list<int>	a;
	std::list<int>	b;

	unpaired = ((nums.size() % 2 == 0) ? -1 : nums.back());

	if (nums.size() == 2 || nums.size() == 3)
	{
		insertion_sort(nums);
		return ;
	}

	if (unpaired >= 0)
		nums.pop_back();


	while (!nums.empty())
	{
		int n = nums.front();
		nums.pop_front();
		int m = nums.front();
		nums.pop_front();
		
		if (n > m)
			swap(n, m);
		a.push_back(m);
		b.push_back(n);
	}

	if (unpaired >= 0)
		b.push_back(unpaired);
	merge_sort(a);
	insert(a, b);
	nums = a;
}
