#include "Span.hpp"

Span::Span(): size(0), arr(std::vector<int>()) { }

Span::Span(size_t n): size(0), arr(std::vector<int>(n)) { }

Span::Span(const Span& other) { *this = other; }

Span& Span::operator=(const Span& other)
{
	arr = other.arr;
	size = other.size;
	return *this;
}

int Span::longestSpan() const
{
	int _max = INT_MIN;
	if (this->getsize() == 0 || this->getsize() == 1)
		throw std::range_error("Span can't be found");
	for (size_t i = 0; i < this->getsize() - 1; i++)
	{
		if (arr[i + 1] - arr[i] > _max)
			_max = abs(arr[i + 1] - arr[i]);
	}
	return _max;
}

int Span::shortestSpan() const
{
	int _min = INT_MAX;

	if (this->getsize() == 0 || this->getsize() == 1)
		throw std::length_error("Span can't be found");

	for (size_t i = 0; i < this->getsize() - 1; i++)
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

void Span::addNumberIt(std::vector<int>::iterator begin,
	std::vector<int>::iterator end, int num)
{
	if (begin < arr.begin() || end > arr.end())
		throw std::out_of_range("Iterator out or range");

	for (std::vector<int>::iterator it = begin; it != end; ++it)
	{
		*it = num;
	}
}

size_t Span::getsize() const
{
	size_t i = 0;

	for (Span::iterator it = arr.begin(); it != arr.end(); ++it) ++i;

	return i;
}

std::vector<int>::iterator Span::begin() { return arr.begin(); }

std::vector<int>::iterator Span::end() { return arr.end(); }

Span::~Span() { }