#include "Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name );

int	main()
{
	int		i = -1;
	int		N = 5;
	Zombie	*zombies = new Zombie[N];//zombieHorde(N, "bro");

	while (++i < N)
		zombies[i].announce();
	delete[] zombies;
}
