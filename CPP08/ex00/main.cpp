#include <iostream>
#include <vector>
#include <algorithm>
#include "easyfind.hpp"

int main(int argc, char **argv)
{
	std::vector<int> a;

	(void)argv;
	(void)argc;

	for (int i = 0; i < 100; ++i)
		a.push_back(i);
	std::cout << *(a.end() - 1) << "\n";
	std::cout << *(easyfind(a, 50)) << "\n";

	if (easyfind(a, 13123123) == a.end())
		std::cout << "not found\n";
}
