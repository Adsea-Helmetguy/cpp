#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>
{
	std::cout << GREEN << "Constructor \"" << RT << this->_name << \
		GREEN << "\" created!" << RT << std::endl;
};

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& copy) : std::stack<T>
{
	(*this) = copy;
	this->_name = copy.getName();
};

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack& copy)
{
	if (this != &copy)
	{
		std::stack<T>::operator=(copy);
		this->_name = copy.getName();
	}
	return (*this);
};

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << RED << "Destructor called for: " \
		<< RT << "[" << YELLOW << this->_name \
		<< RT << "]" << RT << std::endl;
};






//--------------------------------------------------------------
//-----------------------member functions-----------------------
/*
template <typename T>
void	MutantStack<T>::getstack_values() const
{
	std::list<int>::const_iterator	start;
	unsigned int	array = 0;

	std::cout << "_stackValue values: " << std::endl;
	for (start = this->begin(); start != this->end(); start++)
	{
		std::cout << "Value of Array[" << YELLOW << array++ << RT << \
			"]: " << GREEN << *start << RT << std::endl;
	}
};

template <typename T>
std::list<int>	MutantStack<T>::copystack() const
{
	return (this->_stackValue);
};
*/
//-----------------------member functions-----------------------
//--------------------------------------------------------------



//-----------------------------------------------------------------------
//---Operators!-------------------------------------------------------
template <typename T>
std::ostream&	operator<<(std::ostream& os, const MutantStack<T>& stack)
{
	std::cout << "\n*********************************\n" \
		<< "Printing stack's information |\n" \
		<< "******************************" << std::endl;

	std::cout << "Name: \"" << stack.getName() << "\"" << std::endl;
	//stack.getstack_values();
	std::cout << "\n*********************************" << std::endl;
	return (os);
};
//---Operators!-------------------------------------------------------
//-----------------------------------------------------------------------

//links:
/*
https://en.cppreference.com/w/cpp/container/stack/stack --constructor of std::stack--
*/
