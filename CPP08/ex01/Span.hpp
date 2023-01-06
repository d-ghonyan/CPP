#pragma once

#include <iostream>
#include <vector>
#include <climits>

class Span
{
private:
	size_t size;
	std::vector<int> arr;
public:
	Span();
	Span(size_t n);
	Span(const Span& other);
	void addNumber(int num);
	int getsize();
	int longestSpan();
	int shortestSpan();
	Span& operator=(const Span& other);
	~Span();
};

Span::Span(): size(0), arr(std::vector<int>()) { }

Span::Span(size_t n): size(0), arr(std::vector<int>(n)) { }

int Span::getsize() { return size; }

int Span::longestSpan()
{
	int _max = INT_MIN;
	if (size == 0 || size == 1)
		throw std::range_error("Span can't be found");
	for (size_t i = 0; i < size - 1; i++)
	{
		if (arr[i + 1] - arr[i] > _max)
			_max = arr[i] - arr[i + 1];
	}
	return _max;

}

int Span::shortestSpan()
{
	int _min = INT_MIN;

	if (size == 0 || size == 1)
		throw std::length_error("Span can't be found");
	for (size_t i = 0; i < size - 1; i++)
	{
		if (arr[i + 1] - arr[i] < _min)
			_min = arr[i] - arr[i + 1];
	}
	return _min;
}

void Span::addNumber(int num)
{
	if (size == arr.size())
		throw std::length_error("Exceeded array length");
	arr[size] = num;
	++size;
}

Span::~Span() { }