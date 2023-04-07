#include "BitcoinExchange.hpp"

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

		base[first] = second;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) { *this = other; }

float BitcoinExchange::findExchangeRate(Date date) const
{
	std::map<Date, std::string>::const_iterator it = base.begin();

	while (it != base.end() && (*it).first <= date) { ++it; }

	if (date < (*(base.begin())).first) { throw DateNotFoundException(); }

	if (it != base.end() && (*it).first == date)
	{
		return str2float((*(it)).second);
	}

	return str2float(((*(--it)).second));
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

		second = trim(second);
		first = trim(first);

		if (first == "date" || (!first[0] && !second[0]))
			continue ;
		else if (!first[0] || !second[0])
			std::cout << "Empty values in the file, skipping\n";
		else
		{
			try
			{
				std::stringstream s(second);

				double mult;
				double rate = findExchangeRate(first);

				s >> mult;

				std::cout << mult << "\n";

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

const char *BitcoinExchange::InvalidFileException::what() const throw() { return strerror(errno); }
const char *BitcoinExchange::DateNotFoundException::what() const throw() { return "Date not found in the database"; }
const char *BitcoinExchange::InvalidNumberException::what() const throw() { return "Invalid number"; }

BitcoinExchange::~BitcoinExchange() { }