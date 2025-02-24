#include "Array.hpp"

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

//Constructor with value
template <typename T>
Array<T>::Array(unsigned int n) : _name("default Array-unsigned_int"), _size(n), _array(new T[n]())
{
	std::cout << GREEN << "default Array-unsigned_int created" << RT << std::endl;
	for (unsigned int index = 0; index < n; index++)
	{
		this->_array[index] = static_cast<T>(0);
	}
};

//copy constructor
template <typename T>
Array<T>::Array(Array &copy)
{
	this->_name = copy.getName();
	this->_size = copy.getSize();
	this->_array = copy.copyArray();
};

//operator= constructor
template <typename T>
Array<T>&	Array<T>::operator=(const Array &copy)
{
	if (*this != copy)
	{
		if (this->_array)
		{
			delete[] (this->_array);
			this->_array = NULL;
		}

		this->_name = copy.getName();
		this->_size = copy.getSize();
		this->_array = copy.copyArray();
	}
	return (*this);
};

template <typename T>
Array<T>::~Array()
{
	std::cout << RED << "***Destructor for \"" << YELLOW \
		<< this->getName() << RED << "\" called." \
		<< " To remove the new allocated array." << RT << std::endl;
	//to remove "_array(new T[n]())"
	if (this->_array)
	{
		delete[] (this->_array);
		this->_array = NULL;
	}
};

//--------------------Functions--------------------
// _name("default Array-unsigned_int")
template <typename T>
std::string		Array<T>::getName() const
{
	return (this->_name);
};

// _size(n)
template <typename T>
unsigned int	Array<T>::getSize() const
{
	return (this->_size);
};

//_array[i] = value;
template <typename T>
T		Array<T>::getArray_value(unsigned int n) const
{
	if (n < this->_size)
		return (this->_array[n]);
	return (0);
};

// _array(new T[n]())
template <typename T>
T*		Array<T>::copyArray()
{
	unsigned int	n = this->getSize();

	T* copy = new T[n]();//creating a new this->_array.
	for (unsigned int index = 0; index < n; index++)
	{
		copy[index] = static_cast<T>(this->getArray_value(index));
	}
	return (copy);
};
//--------------------Functions--------------------












//-----------------------------------------------------------------------
//---Operators!-------------------------------------------------------
template <typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return (_array[index]);
};



template <typename T>
std::ostream&	operator<<(std::ostream& os, const Array<T>& form)
{
	std::cout << YELLOW<< "\n----------------" << "Printing Array<T> information" \
		<< "----------------" << RT << std::endl;

	std::cout << "Name: \""<< form.getName() << "\"" << std::endl;
	std::cout << "Array_size: \""<< form.getSize() << "\"" << std::endl;
	for (unsigned int index = 0; index < form.getSize(); index++)
	{
		std::cout << "Array_value[" << GREEN << index << RT \
			<< "]: \""<< form.getArray_value(index) << "\"" << std::endl;
	}
	std::cout << YELLOW << "------------------------------------" \
		"-------------------------" << RT << std::endl;
	return (os);
};
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------



















