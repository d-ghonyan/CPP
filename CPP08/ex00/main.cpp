#include <iostream>
#include <vector>
#include <algorithm>
#include "easyfind.hpp"

int main(int argc, char **argv)
{
	std::vector<int> a;

	if (argc == 1)
		return 1;
	(void)argv;
	for (int i = 0; i < 100; ++i)
		a.push_back(i);
	std::cout << *(a.end() - 1) << "\n";
	(easyfind< std::vector<int> >(a, 50));
}
