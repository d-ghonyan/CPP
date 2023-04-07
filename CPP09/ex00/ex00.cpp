#include "ex00.hpp"
#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc < 3)
		return 0;
	
	// std::ifstream s("a.txt");

	// double a;

	// s >> a;

	// std::cout << a << "\n";

	try
	{
		BitcoinExchange exchange(argv[1], ',');

		exchange.getExchangeRate(argv[2], '|');
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	
	//std::map<Date, std::string> database;

	//database = readFile(CSV_PATH, ',');

	//printExchangeRate(argv[1], '|', database);
}
