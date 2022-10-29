#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap	new_("NEW");

	ScavTrap a("hello");

	ScavTrap copy(a);

	std::cout << "\n";
	std::cout << "copy " ;
	copy.guardGate();
	std::cout << "\n";
	a.attack("target");
	a.beRepaired(123);
	a.guardGate();
}