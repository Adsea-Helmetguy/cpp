#include "easyfind.hpp"

//https://www.youtube.com/watch?v=6OoSgY6NVVk try later?

template<typename T>
int	easyfind(const T &arr, int b)//assume T is a container of int
{
	//loop through the container of T, find first "int b"
	typename T::const_iterator	num2 = arr.begin();
	int			size = arr.size();

	std::cout << "With iterators: " << std::endl;
/*
	for (num2 = arr.begin(); num2 != arr.end(); num2++)
	{
		std::cout << *num2 << std::endl;
		if (*num2 == b)
		{
			return (b);
		}
	}
	if (*num2 == arr.end())
	{
		throw NotFoundExeption();
	}
*/
	return (0);
};





//links:
//https://pages.cs.wisc.edu/~driscoll/typename.html










/*
to use std::map->
using map = std::map<Key, T, Compare,
	 std::pmr::polymorphic_allocator<std::pair<const Key, T>>>;

--What are keys?--
key is the unqiue identifier to determine what kind of value it is?
*/

