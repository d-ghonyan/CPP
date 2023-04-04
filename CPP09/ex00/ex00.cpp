#include "ex00.hpp"

void printExchangeRate(std::string filename, char delim, std::map<Date, std::string> pairs)
{
	std::ifstream file(filename);

	if (file.fail())
	{
		perror("");
		exit(1);
	}

	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream sstream(line);

		std::string first, second;

		std::getline(sstream, first, delim);
		std::getline(sstream, second, delim);

		second = trim(second);
		first = trim(first);
		//std::cout << second << "\n";
		if (!first[0] || !second[0])
			std::cerr << "Error: empty values in file\n";
		else
		{
			try
			{
				if (trim(first) == "date")
					continue ;

				Date date(first);

				std::cout.precision(5);
				float mult = str2float(second);
				float rate = getExchangeRate(first, pairs);

				if (mult < 0 || mult > 1000)
					std::cerr << "Error: out of range: " << mult << "\n";
				else if (rate < 0)
					std::cerr << "Error: not found in a database: " << first << "\n";
				else
					std::cout << first << " => " << std::fixed << getExchangeRate(first, pairs) * mult << "\n";
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}
}

int	main(int argc, char **argv)
{
	std::map<Date, std::string> database;

	if (argc < 2)
		return 0;

	database = readFile(CSV_PATH, ',');

	printExchangeRate(argv[1], '|', database);
}
