#include "Karen.hpp"

size_t str_to_int(std::string& level)
{
	size_t	i = 0;

	std::string hello;

	std::string lvl[5] = {"debug", "info", "warning", "error", "hello"};

	for (std::string::iterator it = level.begin(); it != level.end(); ++it)
		*it = std::tolower(*it);

	for (; i < 4 && level != lvl[i]; i++) ;

	return i;
}

void karenFilter(std::string lvl, Karen karen)
{
	switch (str_to_int(lvl))
	{
		case 0:
			std::cout << "[ DEBUG ]\n";
			karen.complain("debug");
			std::cout << "\n";
		case 1:
			std::cout << "[ INFO ]\n";
			karen.complain("info");
			std::cout << "\n";
		case 2:
			std::cout << "[ WARNING ]\n";
			karen.complain("warning");
			std::cout << "\n";
		case 3:
			std::cout << "[ ERROR ]\n";
			karen.complain("error");
			break;
		default:
			karen.complain("banik");
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return 0;
	Karen karen;
	karenFilter(argv[1], karen);
}