#include <cstring>
#include <iostream>

int	main(int argc, char **argv)
{
	int	i = 0;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (++i < argc)
		{
			int j = -1;
			while (argv[i][++j])
				std::cout << (char)::toupper(argv[i][j]);
		}
	}
	std::cout << std::endl;
}