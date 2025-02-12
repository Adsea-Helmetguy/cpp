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
	int					_fixedpoint_value;//stores fixed_point num in raw form.
	static const int	_fractionalBits;//always 8.

public:
	Fixed();//(init fixed point to 0) : _fixedpoint_value(0);
	Fixed(const Fixed& other);//(init by copying another obj) : _fixedpoint_value(other.value)
	Fixed& operator=(const Fixed& other);//Copy assignment operator: assigns one object to another
	~Fixed();//Destructor:

	int					getRawBits(void) const;
	void				setRawBits(int const raw);
};
#endif
