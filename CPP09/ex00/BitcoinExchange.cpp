#include "BitcoinExchange.hpp"
#include "Date.hpp"

BitcoinExchange::BitcoinExchange(std::string filename, char delim)
{
	std::ifstream file(filename);

	if (file.fail()) { throw InvalidFileException(); }

	std::string line;
	while (std::getline(file, line))
	{
		std::string first, second;
		std::istringstream sstream(line);

		std::getline(sstream, first, delim);
		std::getline(sstream, second, delim);

		if (first == "date" || (!first[0] && !second[0]))
			continue ;

		if ((!first[0] && second[0]) || (!second[0] && first[0]))
		{
			std::cerr << "Empty values in the database, skipping\n";
			continue ;
		}

		if (!is_double(second)) throw InvalidValuesInDatabaseException();

		base[first] = second;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) { *this = other; }

double BitcoinExchange::findExchangeRate(Date date) const
{
	std::map<Date, std::string>::const_iterator it = base.begin();

	while (it != base.end() && (*it).first <= date) { ++it; }

	if (date < (*(base.begin())).first) { throw DateNotFoundException(); }

	if (it != base.end() && (*it).first == date)
	{
		return str2double((*(it)).second);
	}

	return str2double(((*(--it)).second));
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& lhs)
{
	base = lhs.base;

	return *this;
}

void BitcoinExchange::getExchangeRate(std::string filename, char delim) const
{
	std::ifstream file(filename);

	if (file.fail()) { throw InvalidFileException(); };

	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream sstream(line);

		std::string first, second;

		std::getline(sstream, first, delim);
		std::getline(sstream, second, delim);

		second = Date::trim(second);
		first = Date::trim(first);

		if (first == "date" || (!first[0] && !second[0]))
			continue ;
		else if (!first[0] || !second[0])
			std::cout << "Empty values in the file, skipping\n";
		else
		{
			try
			{
				double mult = str2double(second);
				double rate = findExchangeRate(first);

				if (mult < 0 || mult > 1000) { throw InvalidNumberException(); }
				if (rate < 0) { throw DateNotFoundException(); }
				
				std::cout << first << " => " << findExchangeRate(first) * mult << "\n";
			}
			catch(const std::exception& e)
			{
				std::cerr << "Error: " <<  e.what() << '\n';
			}
		}
	}
}

bool BitcoinExchange::is_double(std::string hello)
{
	size_t i = 0;
	bool point = false;

	while (std::isspace(hello[i])) ++i ;

	if (hello[i] == '+' || hello[i] == '-') ++i;

	for (;  (hello[i] != 'e' && hello[i] != 'E') && i < hello.size(); ++i)
	{
		if (hello[i] == '.' && !point)
			point = true;
		else if (hello[i] == '.' && point)
			return false;
		if ((hello[i] < '0' || hello[i] > '9') && hello[i] != '.')
			return false;
	}

	i += (hello[i] == 'e' || hello[i] == 'E');
	i += (hello[i] == '+' || hello[i] == '-');

	for (; i < hello.size(); ++i)
	{
		if (hello[i] < '0' || hello[i] > '9')
			return false;
	}

	return true;
}

double BitcoinExchange::str2double(std::string str)
{
	double 		l;
	const char	*s = str.c_str();

	errno = 0;

	l = strtod(s, NULL);

	if (!is_double(str)) throw InvalidNumberException();

	if (errno == ERANGE && (l == HUGE_VAL || l == -HUGE_VAL || l == 0))
	{
		throw NumberOutOfRangeException();
	}
	return l;
}

const char *BitcoinExchange::InvalidFileException::what() const throw() { return strerror(errno); }
const char *BitcoinExchange::DateNotFoundException::what() const throw() { return "Date not found in the database"; }
const char *BitcoinExchange::InvalidNumberException::what() const throw() { return "Invalid number"; }
const char *BitcoinExchange::NumberOutOfRangeException::what() const throw() { return "Number out of range"; }
const char *BitcoinExchange::InvalidValuesInDatabaseException::what() const throw() { return "Invalid values in the database"; }

BitcoinExchange::~BitcoinExchange() { }