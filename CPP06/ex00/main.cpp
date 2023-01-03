#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	std::string hello(argv[1]);

	if (hello == "nan")
		std::cout << static_cast<float>() << " " << std::stod(hello) << "\n";
	std::cout << hello << "\n";
}