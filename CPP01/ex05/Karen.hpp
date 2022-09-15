#pragma once

#include <iostream>

class Karen
{
private:
	void	debug();
	void	info();
	void	warning();
	void	error();
public:
	void	complain(std::string level);
};

typedef void (Karen::*complain_funcs)(void);