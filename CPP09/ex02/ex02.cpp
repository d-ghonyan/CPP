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

	if (argc < 3 || argv_check(argv))
		return (0);
	
	for (size_t i = 1; argv[i]; ++i) { nums_v.push_back(str2int(argv[i])); nums_l.push_back(str2int(argv[i])); }


	// gettimeofday(&now, NULL);

	// double start = gettime(now);
	
	// merge_sort_vector(nums_v);

	// double end = gettime(now);

	// std::cout.precision(17);

	// print(nums_v);

	// std::cout << "Time taken by vector: " << std::fixed << end - start << " ms\n"; 
	// std::cout << nums_v.size() << "\n";

	insertion_sort(nums_l);

	merge_sort_list(nums_l);
}
