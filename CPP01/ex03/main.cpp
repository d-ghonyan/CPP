#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	// how tf do i do this
	{
		Weapon club("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.settype("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.settype("some other type of club");
		jim.attack();
	}
	return (0);
}