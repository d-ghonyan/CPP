#include "Span.hpp"

Span::Span(): size(0), arr(std::vector<int>()) { }

Span::Span(size_t n): size(0), arr(std::vector<int>(n)) { }

Span& Span::operator=(const Span& other)
{
	arr = other.arr;
	size = other.size;
	return *this;
}

Span::Span(const Span& other) { *this = other; }

int Span::longestSpan()
{
	int _max = INT_MIN;
	if (size == 0 || size == 1)
		throw std::range_error("Span can't be found");
	for (size_t i = 0; i < size - 1; i++)
	{
		if (arr[i + 1] - arr[i] > _max)
			_max = abs(arr[i + 1] - arr[i]);
	}
	return _max;
}

int Span::shortestSpan()
{
	int _min = INT_MAX;

	if (size == 0 || size == 1)
		throw std::length_error("Span can't be found");
	for (size_t i = 0; i < size - 1; i++)
	{
		if (arr[i + 1] - arr[i] < _min)
			_min = abs(arr[i + 1] - arr[i]);
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