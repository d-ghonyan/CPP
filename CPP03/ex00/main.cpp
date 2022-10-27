#include "ClapTrap.hpp"

int main()
{
	ClapTrap	trap1("Hello1");
	ClapTrap	trap2(trap1);

	ClapTrap	new_("NEW");

	new_ = (trap1 = (trap2 = new_));
	new_.beRepaired(123);
	new_.attack("hello");
	new_.takeDamage(123);
	new_.takeDamage(123);
	new_.attack("hello");
	new_.attack("hello");
	new_.beRepaired(123);
	new_.beRepaired(123);
	new_.beRepaired(123);
	new_.attack("hello");
}