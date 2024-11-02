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

//for greater readability, the constructor/destructor messages are removed
//as stated in the question.
int	main(void)
{
	std::cout << YELLOW << "\n\nCONSTRUCTOR HERE!" << RESET << std::endl;
//
//
	Fixed			a;
	Fixed const		b(Fixed(5.05f) * Fixed(2));

//
//
	std::cout << RED << "Note: " << RESET << "Two temporary objects " \
	<< "Fixed(5.05f) && Fixed(2) were created." << RESET << std::endl;
	std::cout << "After the assigning the muliplied value to \"b\"" \
	" both Fixed(5.05f) && Fixed(2)\nare no longer needed and " \
	"are automatically destroyed." << std::endl;
	std::cout << YELLOW << "\n---------TESTS HERE!---------" \
	<< RESET << std::endl;
	std::cout << YELLOW << "Increment operators" << RESET << std::endl;
	std::cout << a << std::endl;
	std::cout << "++a: " <<  ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
//
//
//
//
//
	std::cout << YELLOW << "\n--------OTHER TESTS!!--------" \
	<< RESET << std::endl;
	Fixed			c(2.5f);
	Fixed			e(2);
	std::cout << YELLOW << "Decrement operators" << RESET << std::endl;
	std::cout << c << std::endl;
	std::cout << "c-- : " << --c << std::endl;
	std::cout << "--c : " << c-- << std::endl;
	std::cout << c << std::endl;
	std::cout << YELLOW << "\n\nComparison operators" << RESET << std::endl;
	std::cout << YELLOW << "Keep in mind the value of c: " << RESET \
	<< c << std::endl;
	std::cout << "If c > 2, print yes" << std::endl;
	if (c > e)
		std::cout << GREEN << "YESYESYES\n---------\n" << RESET << std::endl;
	std::cout << "\nIf c < 2, print yes" << std::endl;
	if (c < e)
		std::cout << GREEN << "YESYESYES\n" << RESET << "---------\n" \
		<< RESET << std::endl;
	std::cout << "\nIf c >= 2, print yes" << std::endl;
	if (c >= e)
		std::cout << GREEN << "YESYESYES\n" << RESET << "---------\n" \
		<< RESET << std::endl;
	std::cout << "\nIf c <= 2, print yes" << std::endl;
	if (c <= e)
		std::cout << GREEN << "YESYESYES\n" << RESET << "---------\n" \
		<< RESET << std::endl;
	std::cout << "\nIf c == 2, print yes, else print NO" << std::endl;
	if (c == e)
		std::cout << GREEN << "YESYESYES\n" << RESET << "---------\n" \
		<< RESET << std::endl;
	else
		std::cout << RED << "NO NO NO\n" << RESET << "---------\n" \
		<< RESET << std::endl;
	std::cout << "\nIf c != 2, print yes, else print NO" << std::endl;
	if (c != e)
		std::cout << GREEN << "YESYESYES\n" << RESET << "---------\n" \
		<< RESET << std::endl;
	else
		std::cout << RED << "NO NO NO\n" << RESET << "---------\n" \
		<< RESET << std::endl;
	std::cout << YELLOW << "\n\n\n\narithmetic operators" << RESET << std::endl;
	Fixed			d(5.5f);
	std::cout << YELLOW << "Keep in mind the value of d: " << RESET \
	<< d << std::endl;
	std::cout << "\nd + 2 = " << d + e << std::endl;
	std::cout << "\nd - 2 = " << d - e << std::endl;
	std::cout << "\nd * 2 = " << d * e << std::endl;
	std::cout << "\nd / 2 = " << d / e << std::endl;
	d = 5 + 10;
	std::cout << YELLOW << "\n\nSetting value of (d = 5 + 10), d = " << RESET \
	<< d << std::endl;
	std::cout << "d + 5 = \n------------------------\n" << d + 5 \
	<< "\n------------------------" << std::endl;
	std::cout << YELLOW << "\n\nDESTRUCTOR HERE!" << RESET << std::endl;
	return 0;
}
/*
If you ever do a division by 0, 
it is acceptable that the program crashes.
*/
//
//
//
/*
int main (void)
{

	Fixed number(1); // so we have an instace of the fixed calss with value 1
	Fixed othernumber( number + 2); // this is another instance with value 3

	Fixed result = Fixed(number + othernumber); // when we do this, 1 + 3 -> result gets stored in the LHS
}
*/
