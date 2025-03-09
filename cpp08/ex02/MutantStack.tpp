#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	std::cout << GREEN << "Constructor created!" << RT << std::endl;
};

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& copy) : std::stack<T>()
{
	(*this) = copy;
};

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack& copy)
{
	if (this != &copy)
	{
		std::stack<T>::operator=(copy);
	}
	return (*this);
};
template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << RED << "Destructor called for: " \
		<< RT << "[" << YELLOW << "This constructor" \
		<< RT << "]" << RT << std::endl;
};


//--------------Creating my own iterators--------------
//typename MutantStack<t>:: cause it's outside the class here
template <typename T>
typename MutantStack<T>::iterator		MutantStack<T>::begin()
{
	//👉 std::stack<T> has a protected member variable called c.
	//👉 c stores the actual elements inside the stack.
	//👉 c is of type std::deque<T> by default,
	//		it could be std::vector<T> or std::list<T>.
	return (this->c.begin());
};

template <typename T>
typename MutantStack<T>::iterator		MutantStack<T>::end()
{
	return (this->c.end());
};

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin() const
{
	return (this->c.begin());
};

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end() const
{
	return (this->c.end());
};
//-----------------------------------------------------


//--------------------------------------------------------------
//-----------------------member functions-----------------------
template <typename T>
void	MutantStack<T>::getstack_values() const
{
	std::deque<int>::const_iterator	start;
	unsigned int	array = 0;

	std::cout << "_stackValue values: " << std::endl;
	for (start = this->begin(); start != this->end(); start++)
	{
		std::cout << "Value of Array[" << YELLOW << array++ << RT << \
			"]: " << GREEN << *start << RT << std::endl;
	}
	std::cout << "Address: (" << MAG << this << RT << ")" << std::endl;
};
//-----------------------member functions-----------------------
//--------------------------------------------------------------



//-----------------------------------------------------------------------
//---Outside!-------------------------------------------------------
template <typename T>
std::ostream&	operator<<(std::ostream& os, const MutantStack<T>& stack)
{
	std::cout << "\n*********************************\n" \
		<< "Printing stack's information |\n" \
		<< "******************************" << std::endl;
	(void)stack;
	stack.getstack_values();
	std::cout << "\n*********************************" << std::endl;
	return (os);
};

template <typename T>
int		easyfind(const T &arr, int ValueToFind)
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
//---Outside!-------------------------------------------------------
//-----------------------------------------------------------------------

//links:
/*
https://en.cppreference.com/w/cpp/container/stack/stack --constructor of std::stack--

https://stackoverflow.com/questions/3582608/how-to-correctly-implement-custom-iterators-and-const-iterators
https://stackoverflow.com/questions/73440733/how-can-i-implement-my-own-stack-iterator-in-c
--creating a iterator in replacement for std::stack--

*/
