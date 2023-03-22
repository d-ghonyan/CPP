#include <iostream>
#include <deque>
#include <sstream>

int	argv_check(std::string s)
{
	std::string valid("0123456789+-*/ ");

	for (size_t i = 0; i < s.size(); ++i)
	{
		if (valid.find(s[i]) == std::string::npos)
		{
			std::cerr << "Error: you're dumb\n";
			return 69;
		}
	}
	return 0;
}

int main(int argc, char **argv)
{
	if (argc < 2 || argv_check(argv[1]))
		return (0);

	std::istringstream stream(argv[1]);
	std::deque<std::string> nums;

	std::string a;

	while (std::getline(stream, a, ' ')) {nums.push_back(a);}

	std::deque<std::string> temp;

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
			i = std::stoi(temp.front()); temp.pop_front();
			j = std::stoi(temp.front());
		}
		catch (std::exception& e)
		{
			std::cerr << "Error: " << e.what() << "\n";
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
	std::cout << nums.front() << "\n";
}
