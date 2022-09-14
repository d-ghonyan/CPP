#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		char	hello[10000];
		std::ifstream readfile(argv[1]);

		if (readfile.fail())
		{
			std::cout << "why?" << std::endl;
			return (0);
		}
		readfile >> hello;
		std::cout << hello;
	}
}