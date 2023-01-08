#include <iostream>
#include <map>
// #include <pair>

int main()
{
	std::map<std::string, int> map;

	std::cout << map.size() << "\n";

	map.insert(std::map<std::string, int>::value_type("hello", 123));
	map.insert(std::map<std::string, int>::value_type("hello1", 123));
	map.insert(std::map<std::string, int>::value_type("hello2", 123));
	map.insert(std::map<std::string, int>::value_type("hello3", 123));
	map.insert(std::map<std::string, int>::value_type("hello4", 123));
	map.insert(std::map<std::string, int>::value_type("hello5", 123));
	map.insert(std::map<std::string, int>::value_type("hello6", 123));
	map.insert(std::map<std::string, int>::value_type("hello7", 123));

	for (std::map<std::string, int>::iterator it = map.begin(); it != map.end(); ++it)
		std::cout << it->first << " " << it->second << std::endl;

	std::cout << map["hello"] << "\n";
}