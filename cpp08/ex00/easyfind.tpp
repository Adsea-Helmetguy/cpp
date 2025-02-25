#include "easyfind.hpp"

//https://www.youtube.com/watch?v=6OoSgY6NVVk try later?
template<typename T>
//void bar(const Container<T> & c, const T & t)
int	easyfind(const T &arr, int b)//assume T is a container of int
{
	//loop through the container of T, find first "int b"
	//using iterators?
	std::vector<int>	numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));
	unsigned int		size = numbers.size();

	try
	{
		std::cout << "With iterators: " << std::endl;
		std::vector<int>::iterator	num2;
		for (num2 = numbers.begin(); num2 != numbers.end(); num2++)
		{
			std::cout << *num2 << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		//if cannot find "int b", throw exception/return error.
		std::cerr << MAG << e.what() << RT << std::endl;
	}
};

















/*
to use std::map->
using map = std::map<Key, T, Compare,
	 std::pmr::polymorphic_allocator<std::pair<const Key, T>>>;

--What are keys?--
key is the unqiue identifier to determine what kind of value it is?
*/

