#include "ex00.hpp"

const char *InvalidNumber::what() const throw() { return "Invalid number"; }
const char *NumberOutOfRange::what() const throw() { return "Number out of range"; }

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

	if (!is_float(str)) { throw InvalidNumber(); }

    l = strtof(s, NULL);

    if (errno == ERANGE) { throw NumberOutOfRange(); }

    return l;
}

std::map<Date, std::string> readFile(std::string filename, char delim)
{
	std::ifstream file(filename);
	std::map<Date, std::string> pairs;

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
		
		if (first == "date")
			continue ;

		std::getline(sstream, second, delim);

		if ((!first[0] && second[0]) || (!second[0] && first[0]))
		{
			std::cerr << "Error: empty values in database\n";
			exit (67);
		}

		if (!first[0] && !second[0])
			continue ;

		try
		{
			pairs[first] = second;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << ": " << first << '\n';
			exit(128);
		}
	}
	return pairs;
}

float	getExchangeRate(Date date, std::map<Date, std::string> pairs)
{
	std::map<Date, std::string>::iterator it = pairs.begin();

	while (it != pairs.end() && (*it).first <= date) { ++it; }

	if (date < (*(pairs.begin())).first)
	{
		return -1;
	}

	if (it != pairs.end() && (*it).first == date)
	{
		return str2float((*(it)).second);
	}

	return str2float(((*(--it)).second));
}

std::string trim(std::string to_trim)
{
	std::string ret;

	for (size_t i = 0; i < to_trim.size(); ++i)
	{
		if (!(::isspace(to_trim[i])))
			ret.push_back(to_trim[i]);
	}
	return ret.c_str();
}
