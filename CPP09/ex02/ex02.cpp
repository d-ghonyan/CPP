#include "ex02.hpp"

int	is_sorted(std::vector<int> nums_v)
{
	for (size_t i = 0; i < nums_v.size() - 1; ++i)
	{
		if (nums_v[i] > nums_v[i + 1])
			return 0;
	}
	return 1;

}

int main(int argc, char **argv)
{
	t_timeval now;
	std::list<int> nums_l;
	std::vector<int> nums_v;

	if (argc < 3 || argv_check(argv)) return (0);
	
	for (size_t i = 1; argv[i]; ++i) { nums_v.push_back(str2int(argv[i])); nums_l.push_back(str2int(argv[i])); }

	std::cout.precision(17);

	{
		std::cout << "\nBefore: ";
		print(nums_v, 10);

		gettimeofday(&now, NULL);
		double start = gettime(now);
		merge_sort(nums_v);
		double end = gettime(now);

		std::cout << "After: ";
		print(nums_v, 10);

		std::cout << "\nTime taken by std::vector: " << std::fixed << end - start << " ms\n\n\n"; 
	}
	{
		std::cout << "Before: ";
		print(nums_l, 10);

		gettimeofday(&now, NULL);
		double start = gettime(now);
		merge_sort(nums_l);
		double end = gettime(now);

		std::cout << "After: ";
		print(nums_l, 10);

		std::cout << "\nTime taken by std::list: " << std::fixed << end - start << " ms\n\n";
	}
}
