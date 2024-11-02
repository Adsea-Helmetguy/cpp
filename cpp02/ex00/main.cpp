/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:34:13 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:34:18 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	std::cout << YELLOW << "\n\nConstructor happens" << RESET << std::endl;
	Fixed a;
	Fixed b(a);//copy constructor, new object b as copy of a.
	Fixed c;

	std::cout << YELLOW << "\n\nNow it starts" << RESET << std::endl;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << YELLOW << "\n\nother tests, updating fixedpoint_value" \
	", can ignore."<< RESET << std::endl;
	a.setRawBits(1);
	b.setRawBits(2);
	c.setRawBits(3);
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	Fixed d(c);
	std::cout << d.getRawBits() << std::endl;
	std::cout << "-------setting rawbits = 4-------" << RESET << std::endl;
	d.setRawBits(4);
	std::cout << d.getRawBits() << std::endl;
	std::cout << YELLOW << ">>>>>>>>>>Test end!<<<<<<<<<<" \
	<< RESET << std::endl;
	std::cout << YELLOW << "\nDestructors!" \
	<< RESET << std::endl;
	return 0;
}
