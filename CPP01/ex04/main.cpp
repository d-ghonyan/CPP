#include <iostream>
#include <fstream>

#define READCOUNT 100

int	filesize(char *name)
{
	int				size = 0;

	char			c[READCOUNT];
	std::ifstream	readfile(name);

	if (readfile.fail())
		return (-1);
	while (1)
	{
		readfile.read(c, READCOUNT);
		size += readfile.gcount();
		if (!readfile || readfile.gcount() == 0)
			return (size);
	}
}

void	replace_contents(char *buf, char *find, char *repl, char *filename)
{
	size_t			pos = 0;

	std::string	f(find);
	std::string	s(buf);
	std::string	r(repl);
	std::string	name(filename);

	while (1)
	{
		pos = s.find(f, pos);
		if (pos == std::string::npos)
			break ;
		s.erase(pos, f.length());
		s.insert(pos, r);
		pos += r.length();
	}
	std::ofstream newfile(name + ".replace");
	if (newfile.fail())
	{
		std::cout << "Can't create file\n";
		return ;
	}
	newfile << s;
}

int main(int argc, char **argv)
{
	if (argc > 3)
	{
		int	size = filesize(argv[1]);

		if (size <= 0)
		{
			if (size < 0)
				std::cout << "Error opening the file\n";
			else
			{
				std::string name(argv[1]);
				std::ofstream newfile(name + ".replace");
				if (newfile.fail())
					std::cout << "Failed to create a file\n";
			}
			return (0);
		}
		char *buf = new char[size + 1];
		std::ifstream readfile(argv[1]);

		if (readfile.fail())
		{
			std::cout << "why?" << std::endl;
			return (0);
		}
		readfile.read(buf, size);
		buf[size] = '\0';
		replace_contents(buf, argv[2], argv[3], argv[1]);
	}
}