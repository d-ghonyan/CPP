#pragma once

#include <iostream>
#include <algorithm>

template< typename T >
typename T::iterator easyfind(T& cont, int to_find)
{
	return std::find(cont.begin(), cont.end(), to_find);
}