#include "Array.hpp"

/*
A common solution to this is to write the template declaration in a header file, 
	then implement the class in an implementation file (for example .tpp), 
	and include this implementation file at the end of the header.
*/
//MAX_VAL == 750
template <typename T>
void	numbers(Array max_value)//max_value is 750
{
    //implementation
    
};

template <typename T>//one more thing to add here, WHERE IS T being used!?
Array::Array() : _name("Default_name")
{
	
};

template <typename T>
Array::Array(unsigned int n) : _name("Default_name")
{
	//unsigned int "n" is for the array
	//try at int main-> 
	//	int * a = new int(); then display *a.
			
};

template <typename T>
Array::Array(const Array &copy)
{
	this->_name = copy.getName();
};

template <typename T>
Array&	Array::operator=(const Array &copy)
{
	if (*this != copy)
		this->_name = copy.getName();
	return (*this);
};

template <typename T>
Array::~Array()
{
};
