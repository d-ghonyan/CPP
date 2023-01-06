#include <iostream>
#include "Span.hpp"

int main()
{
	Span sp = Span(10000);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	// Span hello = Span(3);
	// hello.addNumber(1);
	// hello.addNumber(1);
	// hello.addNumber(1);
	// hello.addNumber(1);

	// for (Span::iterator it = sp.begin(); it != sp.end(); ++it)
	// 	std::cout << *(it) << " ";

	std::cout << "\n";
	std::cout << "\n";

	sp.addNumberIt(sp.begin() + 5, sp.end(), 123);

	sp.addNumber(1);

	for (Span::iterator it = sp.begin(); it != sp.end() - 9900; ++it)
		std::cout << *(it) << " ";
	std::cout << "\n";

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}