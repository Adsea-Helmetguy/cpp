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
Span::Span(unsigned int	value) : N(value), _name("default N"), _arraySize(0), _arrayNum(NULL)
{

	if (N > static_cast<unsigned int>(INT_MAX))// Prevents excessive allocation
	{
		std::cerr << RED << "unsigned int value beyond INT_MAX, " \
			<< "_arrayNum == NULL" << RT << std::endl;
		return ;
	}

	try
	{
		_arrayNum = new unsigned int[N]();
		for (unsigned int index = 0; index < N; index++)
		{
			this->_arrayNum[index] = static_cast<unsigned int>(0);
		}
		std::cout << GREEN << "N's array(s) created" << RT << std::endl;
	}
	catch (const std::bad_alloc& e)
	{
		throw std::runtime_error("Memory allocation failed: " + std::string(e.what()));
	}
};

Span::Span(const Span& copy)
{
	this->N = copy.getN();
	this->_name = copy.getName();
	this->_arrayNum = copy.getArray();
};

Span&	Span::operator=(const Span& copy)
{
	if (this != &copy)
	{
		if (this->_arrayNum)
			delete(this->_arrayNum);
		this->N = copy.getN();
		this->_name = copy.getName();
		this->_arrayNum = copy.getArray();
	}
	return (*this);
};

Span::~Span()
{
	if (this->_arrayNum)
		delete[] (this->_arrayNum);//Don't forget, delete array need '[]'
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
	this->_arrayNum[_arraySize] = value;

	std::cout << "addNumber| Array[" << GREEN << this->_arraySize << RT \
		<< "] = " << RT << this->getArray_num(_arraySize) << " |" << std::endl;

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

	unsigned int	difference = 0;
	unsigned int	shortest_span = static_cast<unsigned int>(INT_MAX);

	for (unsigned int array = 1; array < N; array++)
	{
		difference = this->_arrayNum[array - 1] - this->_arrayNum[array];
		if (difference < 0)
				difference *= -1;
		if (shortest_span > difference)
			shortest_span = difference;
	}
	return(shortest_span);
};

//longest_Span
int	Span::longestSpan()
{
	if (N <= 1)
		throw std::runtime_error("No numbers or only 1 stored, no Span found.");

	int	difference = 0;
	int	longest_span = 0;

	for (unsigned int array = 1; array < N; array++)
	{
		difference = this->_arrayNum[array - 1] - this->_arrayNum[array];
		if (difference < 0)
				difference *= -1;
		if (longest_span < difference)
			longest_span = difference;
	}
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

unsigned int	Span::getArray_num(unsigned int array) const
{
	return (this->_arrayNum[array]);
};

unsigned int*	Span::getArray() const
{
	return (this->_arrayNum);
};
//----------------------member functions----------------------


//std::ostream& operator<<(std::ostream& os, const const Span& SS)
//{
//};
