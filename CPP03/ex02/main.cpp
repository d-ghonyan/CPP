#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap	trap1("Hello1");
	ClapTrap	trap2(trap1);

	ClapTrap	new_("NEW");

	FragTrap a("hello");

	a.attack("target");
	trap1.attack("target");
	trap2.attack("target");
	a.beRepaired(123);
	a.highFiveGuys();
}