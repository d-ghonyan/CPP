#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <utility>
#include <ctime>
#include <algorithm>
#include <cctype>

#define CSV_PATH "cpp_09/data.csv"

struct isEqual
{
	isEqual(std::string a_wanted) : wanted(a_wanted) { }
	std::string wanted;
	bool operator()(std::pair<std::string, std::string> pair)
	{
		return wanted.compare(pair.first) == 0;
	}
};

std::vector< std::pair<std::string, std::string> > readFile(std::string filename, char delim)
{
	std::ifstream file(filename);
	std::vector< std::pair<std::string, std::string> > pairs;

	if (file.fail())
	{
		std::cout << "ax\n";
		exit(1);
	}

	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream sstream(line);

		std::pair<std::string, std::string> pair;

		std::getline(sstream, pair.first, delim);
		std::getline(sstream, pair.second, delim);

		pairs.push_back(pair);
	}
	return pairs;
}

bool isequal(std::pair<std::string, std::string> pair)
{
	return pair.first == "";
}

float	getExchangeRate(std::string date, std::vector< std::pair<std::string, std::string> > pairs)
{
	std::vector< std::pair<std::string, std::string> >::iterator it = std::find_if(pairs.begin(), pairs.end(), isEqual(date));
	if (it == pairs.end())
		return (-1);
	return std::stof((*it).second);
}

std::string trim(std::string to_trim)
{
	std::string ret;

	size_t	j = -1;
	for (size_t i = 0; i < to_trim.size(); ++i)
	{
		if (!(::isspace(to_trim[i])))
			ret[++j] = to_trim[i];
	}
	return ret.c_str();
}

void printExchangeRate(std::string filename, char delim, std::vector< std::pair<std::string, std::string> > pairs)
{
	struct tm tm;
	const char *date;
	std::ifstream file(filename);

	if (file.fail())
	{
		std::cout << "ax\n";
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
		else if (!strptime(pair.first.c_str(), "%Y-%m-%d", &tm))
		{
			std::cerr << "Error: invalid date\n";
		}
		else
		{
			try
			{
				float mult = std::stof(pair.second);
				float rate = getExchangeRate(trim(pair.first), pairs);
				if (mult < 0)
					std::cerr << "Error: not a positive number\n";
				else if (rate < 0)
					std::cerr << "Error: not found in a database\n";
				else
					std::cout << pair.first << " => " << getExchangeRate(trim(pair.first), pairs) * mult << "\n";
			}
			catch(std::exception &e)
			{
				std::cerr << "Error: " << e.what() << '\n';
			}
		}
	}
}

int	main(int argc, char **argv)
{
	// std::vector<std::string> lines;
	std::vector< std::pair<std::string, std::string> > database;
	std::vector< std::pair<std::string, std::string> > input;

	if (argc < 2)
		return 0;

	const char *a = argv[1];

	struct tm tm;

	database = readFile(CSV_PATH, ',');

	printExchangeRate(argv[1], '|', database);
}
