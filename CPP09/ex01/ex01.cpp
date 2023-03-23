#include <iostream>
#include <deque>
#include <sstream>
#include <errno.h>

long str2int (std::string str);
int	argv_check(std::string s);

int main(int argc, char **argv)
{
	if (argc < 2 || argv_check(argv[1]))
		return (0);

	std::istringstream stream(argv[1]);
	std::deque<std::string> nums;

	std::string a;

	while (std::getline(stream, a, ' ')) {if (a.size()) nums.push_back(a);}

	std::deque<std::string> temp;

	if (nums.size() == 0)
		return 0;

	while (nums.size() != 1)
	{
		while (nums.front() != "*" && nums.front() != "+" &&
			nums.front() != "/" && nums.front() != "-" && !nums.empty())
		{
			temp.push_front(nums.front());
			nums.pop_front();
		}
		if (temp.size() == 1 || temp.empty() || nums.empty())
		{
			std::cerr << "Error: why?\n";
			return 420;
		}

		int i, j;

		try
		{
			i = str2int(temp.front()); temp.pop_front();
			j = str2int(temp.front());
		}
		catch (const char *e)
		{
			std::cerr << "Error: " << e << "\n";
			return (68 + 1);
		}

		std::string operation = nums.front();
		nums.pop_front();
		if (operation == "*")
			nums.push_front(std::to_string(j * i));
		else if (operation == "+")
			nums.push_front(std::to_string(j + i));
		else if (operation == "-")
			nums.push_front(std::to_string(j - i));
		else if (operation == "/")
			nums.push_front(std::to_string(j / i));
		temp.pop_front();
	}
	try { std::cout << str2int(nums.front()) << "\n"; }
	catch (const char *e) { std::cerr << "Error: " << e << '\n'; }
}
