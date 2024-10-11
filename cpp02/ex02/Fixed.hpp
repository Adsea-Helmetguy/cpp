/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:35:16 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:35:18 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <string>//std::string
# include <cmath>

// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class Fixed
{
private:
	int			_fixedpoint_value;
	static const int	_fractionalBits;//always 8.

public:
	Fixed();//(init fixed point to 0) : _fixedpoint_value(0);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	Fixed(const int parameter);
	Fixed(const float floatvalue);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
//New OVERLOADED member functions
	static Fixed&		min(Fixed& fixed1, Fixed& fixed2);
	static const Fixed&	min(const Fixed& num1, const Fixed& num2);
	static Fixed&		max(Fixed& fixed1, Fixed& fixed2);
	static const Fixed&	max(const Fixed& num1, const Fixed& num2);

//New* Public member functions to overload.
//These are still inside public class so don't forget to
//call them with Fixed::
//comparison operators
	bool	operator>(const Fixed& other) const;
	bool	operator<(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;
//
//arithmetic operators
	Fixed	operator+(const Fixed& other) const;
	Fixed	operator-(const Fixed& other) const;
	Fixed	operator*(const Fixed& other) const;
	Fixed	operator/(const Fixed& other) const;
//
//(pre/post)Increment/(pre/post)decrement operators
	Fixed	operator++(void);
	Fixed	operator++(int);
	Fixed	operator--(void);
	Fixed	operator--(int);
//
};

std::ostream& operator<<(std::ostream& out, const Fixed& other);
#endif
