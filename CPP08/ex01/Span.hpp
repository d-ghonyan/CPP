#pragma once

#include <iostream>
#include <vector>
#include <climits>

class Span
{
private:
	size_t size;
	std::vector<int> arr;
	size_t getsize() const;
public:

	typedef std::vector<int>::const_iterator iterator;

	Span();
	Span(size_t n);
	Span(const Span& other);
	void addNumber(int num);
	void addNumberIt(std::vector<int>::iterator begin,
			std::vector<int>::iterator end, int num);
	std::vector<int>::iterator begin();
	std::vector<int>::iterator end();
	int longestSpan() const ;
	int shortestSpan() const ;
	Span& operator=(const Span& other);
	~Span();
};
