#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::vector<std::string> readFile(std::string filename)
{
	std::ifstream file(filename);
	std::vector<std::string> lines;

	if (file.fail())
	{
		std::cout << "ax\n";
		exit(1);
	}

	std::string line;
	while (std::getline(file, line))
	{
		lines.push_back(line);
	}
	return lines;
}

int	main(int argc, char **argv)
{
	std::vector<std::string> lines;

	if (argc < 2)
		return 0;

	lines = readFile(argv[1]);
	for (size_t i = 0; i < lines.size(); ++i) std::cout << lines[i] << "\n";
}