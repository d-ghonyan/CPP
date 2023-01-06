#include <iostream>
#include <vector>
#include "Span.hpp"

int main()
{
	Span hello(1);

	// std::cout << hello.arr.size() << "\n";
	hello.addNumber(123);

	std::cout << hello.shortestSpan() << "\n";

	// hello.addNumber(123);

	// std::cout << hello.arr.size() << "\n";

	// std::vector<int> a = std::vector<int>(4);

	// a.push_back(1);

	// std::cout << a.size() << "\n";
}