#include "easyfind.hpp"

//https://www.youtube.com/watch?v=6OoSgY6NVVk try later?

template<typename T>
int	noteasyfind(const T &arr, int b)//assume T is a container of int
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

//Version 1 (I am using this one)
template<typename T>
int	easyfind(const T &arr, int ValueToFind)//assume T is a container of int
{
	//loop through the container of T, find first "int b"
	typename T::const_iterator	found;
		
	found = std::find(arr.begin(), arr.end(), ValueToFind);
	if (found == arr.end())
	{
		std::cerr << RT << "Unable to find the value: (" \
			<< RED << ValueToFind << RT << ")" << std::endl;
		throw std::runtime_error("No value found in iterator");
	}
	std::cout << "INDEX[" << GREEN \
		<< std::distance(arr.begin(), found) << RT << "]" \
		<< " = " << std::flush;
	return (*found);
};

//Version 2 (Found in test[7, 8 && 9])
template <typename T>
typename T::const_iterator it_easyfind(const T &arr, int ValueToFind)
{
	typename T::const_iterator found;

	found = std::find(arr.begin(), arr.end(), ValueToFind);
	if (found == arr.end())
	{
		std::cerr << RT << "Unable to find the value: (" \
			<< RED << ValueToFind << RT << ")" << std::endl;
		throw std::runtime_error("No value found in iterator");
	}
	std::cout << "INDEX[" << GREEN \
		<< std::distance(arr.begin(), found) << RT << "]" \
		<< " = " << std::flush;
	return (found);
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

