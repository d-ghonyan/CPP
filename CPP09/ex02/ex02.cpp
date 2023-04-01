#include "ex02.hpp"

int	is_sorted(std::vector<int> nums)
{
	for (size_t i = 0; i < nums.size() - 1; ++i)
	{
		if (nums[i] > nums[i + 1])
			return 0;
	}
	return 1;

}

int main(int argc, char **argv)
{
	t_timeval now;
	std::vector<int> nums;

	if (argc < 3 || argv_check(argv))
		return (0);
	
	for (size_t i = 1; argv[i]; ++i) { nums.push_back(str2int(argv[i])); }

	gettimeofday(&now, NULL);

	double start = gettime(now);
	
	merge_sort_vector(nums);

	double end = gettime(now);

	std::cout.precision(17);

	print(nums);

	std::cout << "Time taken by vector: " << std::fixed << end - start << " ms\n"; 

	// std::cout << nums.size() << "\n";
}
