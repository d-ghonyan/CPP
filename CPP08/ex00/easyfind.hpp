#include <iostream>
#include <algorithm>

template<typename T>
std::iterator<std::input_iterator_tag, T> easyfind(T& cont, int to_find)
{
	T < T<int>::iterator > it = std::find(cont.begin(), cont.end(), to_find);
	if (it == cont.end())
		return cont.end();
	return it;
}