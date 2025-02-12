/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
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

# define RESET		"\033[0m"
# define RED		"\033[31m"//Red
# define GREEN		"\033[32m"//Green
# define YELLOW		"\033[33m"//Yellow
# define BLUE		"\033[34m"//Blue


// ************************************************************************** //
//                                       Class                                //
// ************************************************************************** //

class Fixed
{
private:
	int			_fixedpoint_value;
	static const int	_fractionalBits;//always 8.

public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	//New Constructors
	Fixed(const int parameter);//init fixedpoint = 0 and then replace with parameter value!
	Fixed(const float floatvalue);//fixedpoint = 0, replace it with parameter as int. 
	//
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	//
	//New member functions!
	float	toFloat(void) const;//converts this->_fixedpoint_value to float value.
	int		toInt(void) const;//converts this->_fixedpoint_value to int.
};

std::ostream& operator<<(std::ostream& out, const Fixed& other);
#endif
