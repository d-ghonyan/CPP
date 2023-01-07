#include "Karen.hpp"

void	Karen::hello() { std::cout << "[ Probably complaining about insignificant problems ]\n"; }

void	Karen::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!\n";
}

void	Karen::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void	Karen::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month.\n";
}

void	Karen::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void	Karen::complain(std::string level)
{
	size_t	i = 0;

	std::string lvl[5] = {"debug", "info", "warning", "error", "why do you want to break my code"};
	complain_funcs funcs[5] = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error, &Karen::hello};

	for (; i < 4 && level != lvl[i]; i++) ;

	(this->*(funcs[i]))();
}
