#include "RPN.hpp"

RPN::RPN(std::string expression)
{
	parse_str(expression);

	to_calc = trim(expression);
}

void RPN::calculate()
{
	std::stack<double> nums;

	for (size_t i = 0; i < to_calc.size(); ++i)
	{
		if (IS_OPERATION(to_calc, i))
		{
			if (nums.size() < 2) throw InvalidExpressionException();

			double first, second;

			second = nums.top(); nums.pop();
			first = nums.top(); nums.pop();

			switch (to_calc[i])
			{
				case '+':
					nums.push(first + second);
					break ;
				case '-':
					nums.push(first - second);
					break ;
				case '*':
					nums.push(first * second);
					break ;
				case '/':
					if (second == 0) throw DivisionByZeroException();
					nums.push(first / second);
					break ;
			}
		}
		else
			nums.push(to_calc[i] - 48);
	}
	if (nums.size() != 1)  { throw InvalidExpressionException(); }

	std::cout << nums.top() << "\n";
}

double RPN::str2double(std::string str)
{
	double 		l;
	const char	*s = str.c_str();

	errno = 0;

	l = strtod(s, NULL);

	if (errno == ERANGE && (l == HUGE_VALL || l == -HUGE_VALL || l == 0))
	{
		throw RPN::NumberOutOfRangeException();
	}
	return l;
}

std::string RPN::trim(std::string s)
{
	std::string res;

	for (size_t i = 0; i < s.size(); ++i)
	{
		if (s[i] != ' ')
			res.push_back(s[i]);
	}
	return res;
}

void RPN::parse_str(std::string s)
{
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (s[i] == ' ') continue ;

		if (!IS_OPERATION(s, i) && (s[i] < '0' || s[i] > '9'))
		{
			throw InvalidNumberException();
		}
	}
}

RPN::RPN(const RPN& other) { *this = other; }
RPN& RPN::operator=(const RPN& lhs) { to_calc = lhs.to_calc; return *this; }

const char *RPN::InvalidNumberException::what () const throw() { return "Invalid number"; }
const char *RPN::DivisionByZeroException::what () const throw() { return "Division by zero"; }
const char *RPN::NumberOutOfRangeException::what () const throw() { return "Number out of range"; }
const char *RPN::InvalidExpressionException::what () const throw() { return "Invalid expression"; }

RPN::~RPN() { }