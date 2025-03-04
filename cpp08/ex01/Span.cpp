/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:08:37 by mlow              #+#    #+#             */
/*   Updated: 2025/02/27 17:10:25 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//fill your Span using a range of iterators.
Span::Span(unsigned int	value) : N(value), _name("default N"), _arraySize(0), _arrayNum(0)
{

	if (N > static_cast<unsigned int>(INT_MAX) || N < 0)// Prevents excessive allocation
	{
		std::cerr << RED << "unsigned int value beyond INT_MAX or less than 0, " \
			<< "_arrayNum == NULL" << RT << std::endl;
		return ;
	}

	_arrayNum.reserve(N);
	std::cout << GREEN << "N's _arrayNum.reserve(s) created" << RT << std::endl;
};

Span::Span(const Span& copy)
{
	this->N = copy.getN();
	this->_name = copy.getName();
	//this->_arrayNum = copy.getArray();
};

Span&	Span::operator=(const Span& copy)
{
	if (this != &copy)
	{
		//std::vector handles memory management
		this->N = copy.getN();
		this->_name = copy.getName();
		//this->_arrayNum = copy.getArray();
	}
	return (*this);
};

Span::~Span()
{
	std::cout << "Function[" << YELLOW << this->_name \
		<< RT << "] is deleted." << RT << std::endl;
};

//----------------------member functions----------------------
int	Span::addNumber(int value)
{
	if (this->_arraySize >= N)
	{
		throw std::runtime_error("Array_Size is at Max capacity");
	}
	this->_arrayNum.push_back(value);

	std::cout << "addNumber| Array[" << GREEN << this->_arraySize << RT \
		<< "] = " << RT << value << " |" << std::endl;

	this->_arraySize++;
	return(0);
};

//Range of Iterators C++98
void	Span::addNumberGroup(const std::vector<int> &numbers)
{
	std::vector<int>::const_iterator	start;

	for (start = numbers.begin(); start != numbers.end(); start++)
	{
		addNumber(*start); // Assuming addNumber() is already implemented
	}
}

//shortest_Span
int	Span::shortestSpan()
{
	if (N <= 1)
		throw std::runtime_error("No numbers or only 1 stored, no Span found.");

	std::sort(_arrayNum.begin(), _arrayNum.end());
	//return(shortest_span);
	return (0);
};

//longest_Span
int	Span::longestSpan()
{
	if (N <= 1)
		throw std::runtime_error("No numbers or only 1 stored, no Span found.");

	int	longest_span = 0;

	std::sort(_arrayNum.begin(), _arrayNum.end());
	
	std::vector<int>::const_iterator	start;
	
	for (start = _arrayNum.begin(); start != _arrayNum.end(); start++)
	{
		std::cout << YELLOW << "Value of _arrayNum: " << *start << RT << std::endl;
	}
	//check the syntax since end is the null pointers
	longest_span = ((*_arrayNum.begin()) - (*_arrayNum.end() - 1)) * -1;
	
	
	return(longest_span);
};

int	Span::add_numSpan()
{
	return(0);
};

unsigned int	Span::getN() const
{
	return (this->N);
};

std::string	Span::getName() const
{
	return (this->_name);
};

unsigned int	Span::getArray_size() const
{
	return (this->_arraySize);
};

int	Span::getArray_num(unsigned int array) const
{
	return (this->_arrayNum[array]);
};

//std::vector<int>	Span::getArray() const
//{
//	return (this->_arrayNum);
//};
//----------------------member functions----------------------


//std::ostream& operator<<(std::ostream& os, const const Span& SS)
//{
//};
