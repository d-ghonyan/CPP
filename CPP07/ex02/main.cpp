#include "Array.hpp"
#include <iostream>

int main()
{
	Array<int> hello1(15);
	Array<int> hello2(15);

	Array<std::string> hello3(5);

	std::cout << "`" << hello3[2] << "'\n";

	for (size_t i = 0; i < hello2.size(); i++)
		hello2[i] = i;

	for (size_t i = 0; i < hello3.size(); i++)
		hello3[i] = "hello" + std::to_string(i);
	
	hello1 = hello2;
	hello1 = hello2;
	hello1 = hello2;
	hello1 = hello2;
	hello1 = hello2;

	hello1[5] = 723564;

	std::cout << hello1[5] << " 1 \n";
	std::cout << hello2[5] << " 2 \n";
	std::cout << hello3[2] << " 3 \n";

	std::cout << hello1.size() << "\n";

}