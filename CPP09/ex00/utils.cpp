#include "ex00.hpp"

bool is_float(std::string hello)
{
	size_t i = 0;
	bool point = false;

	while (std::isspace(hello[i])) ++i ;

	if (hello[i] == '+' || hello[i] == '-') ++i;

	for (; i < hello.size(); ++i)
	{
		if (hello[i] == '.' && !point)
			point = true;
		else if (hello[i] == '.' && point)
			return false;
		if ((hello[i] < '0' || hello[i] > '9') && hello[i] != '.')
			return false;
	}
	return true;
}

float str2float (std::string str)
{
    float 		l;
	const char	*s = str.c_str();

    errno = 0;

	if (!is_float(str))
		throw "invalid argument";

    l = strtof(s, NULL);
    if (errno == ERANGE) {
        throw "out of range";
    }

    return l;
}

std::list< std::pair<std::string, std::string> > readFile(std::string filename, char delim)
{
	struct tm tm;
	std::ifstream file(filename);
	std::list< std::pair<std::string, std::string> > pairs;

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
		
		if ((!pair.first[0] && pair.second[0]) || (!pair.second[0] && pair.first[0]))
		{
			std::cerr << "Error: empty values in database\n";
			exit (67);
		}
		else if (pair.first != "date" && pair.first[0] && !strptime(pair.first.c_str(), "%Y-%m-%d", &tm))
		{
			std::cerr << "Error: invalid dates in database: " << pair.first << "\n";
			exit (68);
		}

		pairs.push_back(pair);
	}
	return pairs;
}

bool isequal(std::pair<std::string, std::string> pair)
{
	return pair.first == "";
}

float	getExchangeRate(std::string date, std::list< std::pair<std::string, std::string> > pairs)
{
	std::list< std::pair<std::string, std::string> >::iterator it = std::find_if(pairs.begin(), pairs.end(), isEqual(date));
	if (it == pairs.end())
		return (-1);
	return str2float((*it).second);
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
