/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:34:28 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:34:30 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//since it is static, it will be first to be displayed, init here first
const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedpoint_value(0)
{
	std::cout << "(Default constructor called)" << std::endl;
}

//comment out either "*this = other"
//or
//": _fixedpoint_value(other._fixedpoint_value)"
//will still give the same good results.
Fixed::Fixed(const Fixed& other) : _fixedpoint_value(other._fixedpoint_value)
{
	std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
	//*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this == &other)//need to add & because 'this' is a pointer
	{
		std::cout << "Don't Self-assign!!" << std::endl;
		return *this; // handle self-assignment
	}
	std::cout << GREEN << "Copy assignment operator called" << RESET << std::endl;
	setRawBits(other.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "(Destructor called)" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedpoint_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedpoint_value = raw;
}

/*
//-this also works just without this-> thingy for some of them-
//but damn it so "ugly"

cause it is smart enough to know it's talking about it's own
functions/variables without adding "this->" as long as it's 
not the same name as it's own.
but heck just add it in. less confusion and tempt fate.


#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedpoint_value(0)
{
	std::cout << "(Fixed Constructor)" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _fixedpoint_value(other._fixedpoint_value)
{
	std::cout << "(Fixed COPY Constructor)" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "(Fixed COPY ASSIGNMENT Constructor)" << std::endl;
	setRawBits(other.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "(Fixed destructor)" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (_fixedpoint_value);
}

void Fixed::setRawBits(int const raw)
{
	_fixedpoint_value = raw;
}
*/
