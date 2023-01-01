#pragma once

#include <iostream>

template<typename T>
class Array
{
private:
	size_t	cap;
	T		*arr;
public:
	Array();
	Array(size_t n);
	Array(const Array& other);
	Array& operator=(const Array& other);
	T& operator[](size_t n);
	size_t size() const ;
	~Array();
};

template<typename T> Array<T>::Array(): arr(nullptr), cap(0) { }

template<typename T> Array<T>::Array(size_t n): cap(n)
{
	arr = new T[n];
	for (size_t i = 0; i < cap; i++)
		arr[i] = T();
}

template<typename T> Array<T>::Array(const Array& other): arr(nullptr)
{
	*this = other;
}

template<typename T> Array<T>& Array<T>::operator=(const Array& other)
{
	if (this == &other)
		return *this;

	delete arr;

	arr = new T[other.size()];
	cap = other.size();
	for (size_t i = 0; i < cap; i++)
		arr[i] = T();
	return *this;
}

template<typename T> T& Array<T>::operator[](size_t n)
{
	if (n >= cap)
		throw std::out_of_range("lmao get doxxed");
	return arr[n];
}

template<typename T> size_t Array<T>::size() const 
{
	return cap;
}

template<typename T> Array<T>::~Array()
{
	delete arr;
}
