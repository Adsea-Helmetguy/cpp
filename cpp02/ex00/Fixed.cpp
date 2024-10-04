/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:34:28 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:34:30 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedpoint_value(0)
{
	std::cout << "(Default constructor called)" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _fixedpoint_value(other._fixedpoint_value)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
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
