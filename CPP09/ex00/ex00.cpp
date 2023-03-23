#include "ex00.hpp"

void printExchangeRate(std::string filename, char delim, std::list< std::pair<std::string, std::string> > pairs)
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

		std::pair<std::string, std::string> pair;

		std::getline(sstream, pair.first, delim);
		std::getline(sstream, pair.second, delim);

		if (!pair.first[0] || !pair.second[0])
			std::cerr << "Error: empty values in file\n";
		else if (trim(pair.first) != "date" && pair.first[0] && !strptime(pair.first.c_str(), "%Y-%m-%d", &tm))
		{
			std::cerr << "Error: invalid date\n";
		}
		else
		{
			try
			{
				if (trim(pair.first) == "date")
					continue ;
				float mult = str2float(pair.second);
				float rate = getExchangeRate(trim(pair.first), pairs);
				if (mult < 0)
					std::cerr << "Error: not a positive number\n";
				else if (rate < 0)
					std::cerr << "Error: not found in a database: " << pair.first << "\n";
				else
					std::cout << pair.first << " => " << getExchangeRate(trim(pair.first), pairs) * mult << "\n";
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
	std::list< std::pair<std::string, std::string> > database;

	if (argc < 2)
		return 0;

	database = readFile(CSV_PATH, ',');

	printExchangeRate(argv[1], '|', database);
}
