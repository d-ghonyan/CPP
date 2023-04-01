#include "ex00.hpp"

void printExchangeRate(std::string filename, char delim, std::map<std::string, std::string> pairs)
{
	struct tm tm;
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

		if (!first[0] || !second[0])
			std::cerr << "Error: empty values in file\n";
		else if (trim(first) != "date" && first[0] && !strptime(first.c_str(), "%Y-%m-%d", &tm))
		{
			std::cerr << "Error: invalid date\n";
		}
		else
		{
			try
			{
				if (trim(first) == "date")
					continue ;
				float mult = str2float(second);
				float rate = getExchangeRate(trim(first), pairs);
				if (mult < 0)
					std::cerr << "Error: not a positive number\n";
				else if (rate < 0)
					std::cerr << "Error: not found in a database: " << first << "\n";
				else
					std::cout << first << " => " << getExchangeRate(trim(first), pairs) * mult << "\n";
			}
			catch(const char *e)
			{
				std::cerr << "Error: " << e << '\n';
			}
		}
	}
}

int	main(int argc, char **argv)
{
	std::map<std::string, std::string> database;

	if (argc < 2)
		return 0;

	database = readFile(CSV_PATH, ',');

	printExchangeRate(argv[1], '|', database);
}
