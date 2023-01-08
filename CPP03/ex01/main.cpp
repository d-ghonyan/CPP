#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap	new_("NEW");

	ScavTrap a("hello");

	ScavTrap copy(a);

	ClapTrap *b = new ScavTrap("virtual_test");

	std::cout << "\n";
	std::cout << "copy " ;
	copy.guardGate();
	std::cout << "\n";
	a.attack("target");
	b->attack("target_virtual_test");
	a.beRepaired(123);
	a.guardGate();

}