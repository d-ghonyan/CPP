#include <vector>
#include <iostream>
#include <algorithm>

long str2int (std::string str);
int	argv_check(char **argv);
void swap(int &a, int &b);
void print(std::vector<int>  nums);
void print(std::vector < std::vector<int> > nums);

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

int	is_sorted(std::vector<int> nums)
{
	for (size_t i = 0; i < nums.size() - 1; ++i)
	{
		if (nums[i] > nums[i + 1])
			return 0;
	}
	return 1;
}

void kov(std::vector<int>& nums, std::vector<int> b, int unpaired)
{
	int group = 1;
	int power = 0;
	int current_power = 2;
	int next_power = 4;
	int start_index = 0;
	int end_index = 0;

	for (size_t i = 0; i < b.size(); ++i)
	{
		if (group >= b.size())
			group = b.size() - 1;
		for (size_t j = group; j > end_index; j--)
		{
			nums.insert(std::upper_bound(nums.begin(), nums.end(), b[j]), b[j]);
		}
		group = 
	}
}

void merge_sort_vector(std::vector<int>& nums)
{
	int					unpaired;
	std::vector<int>	a;
	std::vector<int>	b;
	size_t size = nums.size() / 2 + (nums.size() % 2);

	unpaired = (nums.size() % 2 ? -1 : nums[nums.size() - 1]);

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
	kov(a, b);
	nums = a;
}

int main(int argc, char **argv)
{
	std::vector<int> nums;

	if (argc < 3 || argv_check(argv))
		return (0);
	
	for (size_t i = 1; argv[i]; ++i) { nums.push_back(str2int(argv[i])); }

	// std::cout << "\n";
	merge_sort_vector(nums);
	print(nums);
}
