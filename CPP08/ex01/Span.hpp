#pragma once

#include <iostream>
#include <vector>
#include <climits>

class Span
{
private:
	size_t size;
	std::vector<int> arr;
	std::vector::iterator begin;
	std::vector::iterator end;
public:
	Span();
	Span(size_t n);
	Span(const Span& other);
	void addNumber(int num);
	void addNumberIt(std::vector::iterator begin);
	int longestSpan();
	int shortestSpan();
	Span& operator=(const Span& other);
	~Span();
};
