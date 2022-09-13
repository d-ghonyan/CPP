#include "Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name );

int	main()
{
	int		i = -1;
	int		N = 5;
	Zombie	*zombies = zombieHorde(N, "bro");

	while (++i < N)
		zombies[i].announce();
	delete[] zombies;

	i = -1;
	N = 10;
	zombies = zombieHorde(N, "bro_again");
	while (++i < N)
		zombies[i].announce();
	delete[] zombies;
}
