#include <vector>
#include <iostream>

long str2int (std::string str);
int	argv_check(char **argv);

void swap(int &a, int &b)
{
	int temp = a;

	a = b;

	b = temp;
}

void merge_sort_vector(std::vector<int> nums)
{
	size_t size = nums.size() / 2 + (nums.size() % 2);
	
	std::vector < std::vector<int> > merge;

	std::cout << size << "\n";

	for (size_t i = 0; i < size; ++i)
	{
		std::vector<int> temp;

		temp.push_back(nums[i * 2]);
		if (i != size - 1 || nums.size() % 2 == 0)
			temp.push_back(nums[i * 2 + 1]);
		merge.push_back(temp);
	}

	std::vector<int> a;
	for (size_t i = 0; i < merge.size(); i++)
	{
		if (merge[i].size() > 1 && merge[i][0] > merge[i][1])
			swap(merge[i][0], merge[i][1]);
		a.push_back(merge[i][0]);
		for (size_t j = 0; j < merge[i].size(); j++)
		{
			std::cout << merge[i][j] << " ";
		}
		std::cout << " | ";
	}
	std::cout << "\n";

	for (size_t i = 0; i < a.size(); i++)
	{
		std::cout << a[i] << " ";
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

void	bin(std::vector<int> nums, std::vector<int> to_sort)
{
	size_t size = (nums.size() - 1) / 2;

	size_t mid = size;
	for (size_t i = 0; i < to_sort.size(); )
	{
		std::cout << mid << "\n";
		std::cout << to_sort[i] << "\n";
		if (mid >= nums.size())
			mid = nums.size() - 1;
		if ((to_sort[i] > nums[mid] && mid < nums.size() && to_sort[i] < nums[mid + 1]))
		{
			nums.insert(nums.begin() + mid + 1, to_sort[i]);
			mid = nums.size() / 2;
			++i;
		}
		else if (mid == nums.size() - 1 || mid == 0)
		{
			nums.insert(nums.begin() + mid + 1 - (mid == 0), to_sort[i]);
			mid = nums.size() / 2;
			++i;
		}
		else if (to_sort[i] > nums[mid])
		{
			mid = mid + mid / 2 + (mid == 1);
		}
		else if (to_sort[i] < nums[mid])
		{
			mid = mid - mid / 2 - (mid == 1);
		}
	}

	std::vector<int> a = nums;
	for (size_t i = 0; i < a.size(); i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << "\n";

}

void	bin_2(std::vector<int> nums, std::vector<int> to_sort)
{
	size_t mid = nums.size() / 2;
	size_t end = nums.size() - 1;
	size_t start = 0;

	for (size_t i = 0; i < to_sort.size(); )
	{
			
	}
}

int main(int argc, char **argv)
{
	std::vector<int> nums;

	if (argc < 3 || argv_check(argv))
		return (0);
	
	for (size_t i = 1; argv[i]; ++i) { nums.push_back(str2int(argv[i])); }

	std::cout << "\n";
	//merge_sort_vector(nums);

	int arr[] = {2,5,8,11,14};
	std::vector<int> hello(arr, arr+5);

	bin(nums, hello);
}
