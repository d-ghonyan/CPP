#pragma once

#include <iostream>
#include <algorithm>

template< template < class ... > typename T>
typename T<int>::iterator easyfind(T< int >& cont, int to_find)
{
	return std::find(cont.begin(), cont.end(), to_find);
}