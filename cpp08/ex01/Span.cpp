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

	if (N > static_cast<unsigned int>(INT_MAX))// Prevents excessive allocation
	{
		std::cerr << YELLOW << "unsigned int value beyond INT_MAX " \
			<< "auto changed N == (INT_MAX)2147483647" << RT << std::endl;
		N = 2147483647;
	}

	_arrayNum.reserve(N);
	std::cout << GREEN << "N's _arrayNum.reserve(s) created" << RT << std::endl;
};

Span::Span(const Span& copy)
{
	this->N = copy.getN();
	this->_name = copy.getName();
	this->_arraySize = copy.getArray_size();
	this->_arrayNum = copy.copyArray();
};

Span&	Span::operator=(const Span& copy)
{
	if (this != &copy)
	{
		//std::vector handles memory management
		this->N = copy.getN();
		this->_name = copy.getName();
		this->_arraySize = copy.getArray_size();
		this->_arrayNum = copy.copyArray();
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

	unsigned int	shortest_span = static_cast<unsigned int>(INT_MAX);
	int		difference = 0;

	std::sort(_arrayNum.begin(), _arrayNum.end());
	for (unsigned int index = 1; index < this->_arraySize; index++)
	{
		difference = _arrayNum[index - 1] - _arrayNum[index];
		if (difference < 0)
			difference *= -1;
		if (static_cast<unsigned int>(difference) < shortest_span)
			shortest_span = static_cast<unsigned int>(difference);
	}
	return (shortest_span);
};

//longest_Span
int	Span::longestSpan()
{
	if (N <= 1)
		throw std::runtime_error("No numbers or only 1 stored, no Span found.");

	unsigned int	longest_span = 0;

	std::sort(_arrayNum.begin(), _arrayNum.end());
	longest_span = static_cast<unsigned int>((_arrayNum[0] - _arrayNum[this->_arraySize - 1]) * -1);
	return (static_cast<int>(longest_span));
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

std::vector<int>	Span::copyArray() const
{
	return (this->_arrayNum);
};

void	Span::getArray_values() const
{
	std::vector<int>::const_iterator	start;
	unsigned int	array = 0;

	std::cout << "_arrayNum values: " << std::endl;
	for (start = _arrayNum.begin(); start != _arrayNum.end(); start++)
	{
		std::cout << "Value of Array[" << YELLOW << array++ << RT << \
			"]: " << GREEN << *start << RT << std::endl;
	}
};

void	Span::clearArray_values()
{
	this->_arrayNum.clear();
	this->_arraySize = 0;
};
//----------------------member functions----------------------
std::ostream&	operator<<(std::ostream& os, const Span& sp)
{
	std::cout << "\n*********************************\n" \
		<< "Printing span's information |\n" \
		<< "*****************************" << std::endl;

	std::cout << "Name: \"" << sp.getName() << "\"" << std::endl;
	std::cout << "N's Max size: \"" << sp.getN() << "\"" << std::endl;
	std::cout << "sp's current used size: \"" << sp.getArray_size() << "\"" << std::endl;
	sp.getArray_values();
	std::cout << "\n*********************************" << std::endl;
	return (os);
};
