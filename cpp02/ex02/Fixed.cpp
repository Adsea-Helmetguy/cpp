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
	std::cout << "(Default Constructor)" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _fixedpoint_value(other._fixedpoint_value)
{
	std::cout << BLUE << "(COPY Constructor WITH VALUES)" << RESET << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this == &other)//need to add & because 'this' is a pointer
	{
		std::cout << "Don't Self-assign!!" << std::endl;
		return *this; // handle self-assignment
	}
	std::cout << BLUE << "Copy assignment operator called" << RESET << std::endl;
	setRawBits(other.getRawBits());
	return (*this);
}

Fixed::Fixed(const int parameter) : _fixedpoint_value(0)
{
	std::cout << GREEN << "(INT Constructor CONVERTING)" << RESET << std::endl;
	this->_fixedpoint_value = (parameter << _fractionalBits);
}

Fixed::Fixed(const float floatvalue) : _fixedpoint_value(0)
{
	std::cout << GREEN << "(FLOAT Constructor CONVERTING)" << RESET << std::endl;
	this->_fixedpoint_value = static_cast<int>(roundf(floatvalue * (1 << _fractionalBits)));
}

Fixed::~Fixed()
{
	std::cout << RED << "(Default Constructor DESTROYED HERE)" << RESET << std::endl;
}

int		Fixed::getRawBits(void) const
{
	return (this->_fixedpoint_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedpoint_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_fixedpoint_value) / (1 << _fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (static_cast<int>(this->_fixedpoint_value) / (1 << _fractionalBits));
}

//
//
//
//
//
//
//New functions!!

Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1 < fixed2)
		return (fixed1);
	return (fixed2);
}

const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1 > fixed2)
		return (fixed1);
	return (fixed2);
}

const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->toFloat() > other.toFloat());
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->toFloat() < other.toFloat());
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->toFloat() >= other.toFloat());
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->toFloat() <= other.toFloat());
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->toFloat() == other.toFloat());
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->toFloat() != other.toFloat());
}


//
//
//
//You can also write it as:
//float	Fixed::operator+(const Fixed& other) const
//instead of using Fixed. just remember to change .hpp one too.
Fixed	Fixed::operator+(const Fixed& other) const
{
	return ((this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	return ((this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	return ((this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	return ((this->toFloat() / other.toFloat()));
}
//
//
/*
When you're inside a member function of a class, 
the special pointer this is automatically available, 
which points to the current instance of the class.
*/
//NEW NOTE:
//by writing "Fixed&" instead of "Fixed", you are
//returning the Reference to it, thus the destructor
//won't happen. You aren't replacing it.
Fixed&	Fixed::operator++(void)
{
	this->_fixedpoint_value++;
	return (*this);
} 

//int is there to tell us this is post increment,
//the int doesnt do anything actually.
//the idea is to point to the 'i' before it pluses and 
//give it THAT value. While its true i increased in value,
//what you need to return is the original value since its i++.
/*
e.g:
    std::cout << i++ << std::endl; //i == 1;
    std::cout << i << std::endl; // i == 2;
*/
//You can't return "Fixed&" Here because,
// once old_value finishes, since it's a local variable,
// it's gonna go out of scope. So its gone, bye bye, done.
Fixed	Fixed::operator++(int)
{
	Fixed	old_value = *this;

	this->_fixedpoint_value++;
	return (old_value);//old_value goes out of scope
}

Fixed&	Fixed::operator--(void)
{
	this->_fixedpoint_value--;
	return (*this);
} 

Fixed	Fixed::operator--(int)
{
	Fixed	old_value = *this;

	this->_fixedpoint_value--;
	return (old_value);
}

std::ostream& operator<<(std::ostream& out, const Fixed& other)
{
	out << other.toFloat();
	return (out);

}
