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

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedpoint_value(0)
{
	std::cout << "(Default constructor called)" << std::endl;
}

Fixed::Fixed(const Fixed& other)// : _fixedpoint_value(other._fixedpoint_value)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this == &other)//need to add & because 'this' is a pointer
	{
		std::cout << "Don't Self-assign!!" << std::endl;
		return *this; // handle self-assignment
	}
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(other.getRawBits());
	return (*this);
}

//
//
//New constructors!
Fixed::Fixed(const int parameter) : _fixedpoint_value(0)
{
	this->_fixedpoint_value = (parameter << _fractionalBits);
	std::cout << "Int constructor called" << ", new value of this fixedpoint: " \
	<< RED << this->_fixedpoint_value << RESET << std::endl;
	/*
	The integer value is converted into the fixed-point format by 
	shifting it left by 8 bits (intValue << _fractionalBits), 
	which essentially multiplies it by 256, ensuring the lower 
	8 bits represent the fractional part.
	*/
}

/*
the process is similar to the integer case above,
but you'll need to handle the fractional part of the 
floating-point number as well.
*/
Fixed::Fixed(const float floatvalue) : _fixedpoint_value(0)
{
	//this->_fixedpoint_value = (floatvalue << _fractionalBits);
	this->_fixedpoint_value = static_cast<int>(roundf(floatvalue * (1 << _fractionalBits)));
	std::cout << "Float constructor called" << ", new value of this fixedpoint: " \
	<< RED << this->_fixedpoint_value << RESET << std::endl;
}
//
//

Fixed::~Fixed()
{
	std::cout << "(Destructor called)" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixedpoint_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedpoint_value = raw;
}

//
//
//NEW Member functions!
float	Fixed::toFloat(void) const
{
	//that converts the fixed-point value to a floating-point value.
	//we use '/' in this case as fixedpoint_value is already multiplied at this point.
	return (static_cast<float>(this->_fixedpoint_value) / (1 << _fractionalBits));
}

int		Fixed::toInt(void) const
{
	//that converts the fixed-point value to an integer value.
	//we use '/' in this case as fixedpoint_value is already multiplied at this point.
	return (static_cast<int>(this->_fixedpoint_value) / (1 << _fractionalBits));
}

//std::cout << Fixed;
// "<<" == std::ostream& out.-> a reference to an output stream object
// "other" == Fixed.-> a constant reference of Fixed, the value we wanna output.
std::ostream& operator<<(std::ostream& out, const Fixed& other)
{
	out << other.toFloat();
	return (out);

}
