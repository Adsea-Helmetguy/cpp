#include "easyfind.hpp"

/*
A common solution to this is to write the template declaration in a header file, 
	then implement the class in an implementation file (for example .tpp), 
	and include this implementation file at the end of the header.
*/

//Default constructor
template <typename T>
Array<T>::Array() : _name("default Array-empty"), _size(0) , _array(new T[0]())
{
	//unsigned int "n" is for the array
	//try at int main-> 
	//	int *a = new int(); then display *a.
	std::cout << GREEN << "default Array-empty created" << RT << std::endl;
};



















