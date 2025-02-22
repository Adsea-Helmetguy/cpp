#include "Array.hpp"

/*
A common solution to this is to write the template declaration in a header file, 
	then implement the class in an implementation file (for example .tpp), 
	and include this implementation file at the end of the header.
*/
template <typename T>//one more thing to add here, <T> beside each Array.
Array<T>::Array() : _name("default Array-empty"), _size(1) , _array(new T[1]())
{
	
};

//MAX_VAL == 750
template <typename T>
Array<T>::Array(unsigned int n) : _name("default Array-unsigned_int"), _size(n), _array(new T[n]())
{
	//unsigned int "n" is for the array
	//try at int main-> 
	//	int *a = new int(); then display *a.
	
	for (unsigned int index = 0; index < n; index++)
	{
		this->_array[index] = static_cast<T>(0);
	}
};

template <typename T>
Array<T>::Array(const Array &copy)
{
	this->_name = copy.getName();
};

template <typename T>
Array<T>&	Array<T>::operator=(const Array &copy)
{
	if (*this != copy)
		this->_name = copy.getName();
	return (*this);
};

template <typename T>
Array<T>::~Array()
{
	//to remove "_array(new T[n]())"
	delete[] (_array);
};

//--------------------Functions--------------------
template <typename T>
std::string	Array<T>::getName()
{
	return (this->_name);
};

template <typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");

	return (_array[index]);
};
//--------------------Functions--------------------





















