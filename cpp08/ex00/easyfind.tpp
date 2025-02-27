#include "easyfind.hpp"

//https://www.youtube.com/watch?v=6OoSgY6NVVk try later?

template<typename T>
int	easyfind(const T &arr, int b)//assume T is a container of int
{
	//loop through the container of T, find first "int b"
	typename T::const_iterator	num2;

	for (num2 = arr.begin(); num2 != arr.end(); num2++)
	{
		if (static_cast<int>(*num2) == b)
			return (b);
	}
	if (num2 == arr.end())
	{
		std::cerr << RT << "Unable to find the value: (" \
			<< RED << b << RT << ")" << std::endl;
		throw std::runtime_error("No value found in iterator");
	}
	return (0);
};


//links:
//https://pages.cs.wisc.edu/~driscoll/typename.html -usage of typename beside vector-










/*
to use std::map->
using map = std::map<Key, T, Compare,
	 std::pmr::polymorphic_allocator<std::pair<const Key, T>>>;

--What are keys?--
key is the unqiue identifier to determine what kind of value it is?
*/

