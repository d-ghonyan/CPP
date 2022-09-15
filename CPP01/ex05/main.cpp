#include "Karen.hpp"

int	main()
{
	Karen karen;

	std::cout << "\n\n";
	karen.complain("debug");
	std::cout << "\n\n";
	karen.complain("info");
	std::cout << "\n\n";
	karen.complain("warning");
	std::cout << "\n\n";
	karen.complain("error");
	std::cout << "\n\n";
	karen.complain("aaaaaAAAAAAAAAAA");
	karen.complain("");
}