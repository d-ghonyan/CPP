#include <vector>
#include <iostream>

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

void merge_sort_vector(std::vector<int> nums)
{
	std::vector<int> a;
	std::vector<int> b;
	size_t size = nums.size() / 2 + (nums.size() % 2);
	
	std::vector < std::vector<int> > merge;

	std::cout << size << "\n";

	for (size_t i = 0; i < size; ++i)
	{
		std::vector<int> temp;

		temp.push_back(nums[i * 2]);
		if (i != size - 1 || nums.size() % 2 == 0)
		{
			temp.push_back(nums[i * 2 + 1]);
			if (temp[0] > temp[1])
				swap(temp[0], temp[1]);
			a.push_back(temp[1]);
			b.push_back(temp[0]);
		}
		merge.push_back(temp);
	}

	print(merge);
	print(a);
	print(b);
}

int main(int argc, char **argv)
{
	std::vector<int> nums;

	if (argc < 3 || argv_check(argv))
		return (0);
	
	for (size_t i = 1; argv[i]; ++i) { nums.push_back(str2int(argv[i])); }

	std::cout << "\n";
	merge_sort_vector(nums);
}
