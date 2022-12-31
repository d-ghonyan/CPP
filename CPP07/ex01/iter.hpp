#pragma once

#include <iostream>

template<typename T>
void iter(T *arr, size_t size, void (*f)(T& el))
{
	for (size_t i = 0; i < size; ++i) { f(arr[i]); }
}
