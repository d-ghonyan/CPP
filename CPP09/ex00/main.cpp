#include <iostream>
#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc < 3)
		return 0;
	try
	{
		BitcoinExchange exchange(argv[1], ',');

		exchange.getExchangeRate(argv[2], '|');
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}
