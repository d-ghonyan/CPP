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

	// try
	// {
	// 	BitcoinExchange exchange(argv[1], ',');

	// 	exchange.getExchangeRate(argv[2], '|');
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << "Error: " << e.what() << '\n';
	// }
	
	double a = BitcoinExchange::str2double(argv[1]);

	std::cout << a << "\n";
	std::cout << (BitcoinExchange::is_double(argv[1]) ? "true" : "false") << "\n";

	//std::map<Date, std::string> database;

	//database = readFile(CSV_PATH, ',');

	//printExchangeRate(argv[1], '|', database);
}
