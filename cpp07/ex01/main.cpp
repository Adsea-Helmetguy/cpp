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

#include "whatever.hpp"

int	main(void)
{
	std::cout << "\n\n-----------------------------------------------------" << std::endl;
	std::cout << YELLOW << "Provided test |" << RT << std::endl;
	std::cout << YELLOW << "---------------" << RT << std::endl;
	{
		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
		/*
		-Output should be:-

		a = 3, b = 2
		min(a, b) = 2
		max(a, b) = 3
		c = chaine2, d = chaine1
		min(c, d) = chaine1
		max(c, d) = chaine2
		*/
	}

	std::cout << "\n\n-----------------------------------------------------" << std::endl;
	std::cout << YELLOW << "-Test 1- |" << RT << std::endl;
	std::cout << YELLOW << "----------" << RT << std::endl;
	{
		float	a = 21.445f;
		float	b = 42.445f;

		std::cout << "The max of a: " << CYAN << a << RT \
			<< " and b: " << CYAN << b << RT << " is:" \
			<< "\t" << GREEN << max(a, b) << RT << std::endl;

		std::cout << "The min of a: " << CYAN << a << RT \
			<< " and b: " << CYAN << b << RT << " is:" \
			<< "\t" << GREEN << min(a, b) << RT << std::endl;

		std::cout << "\n" << std::endl;
		std::cout << MAG << "-Swapping time!-" << RT << std::endl;
		std::cout << "before:\n\ta: " << CYAN << a << RT "\n\tb: " \
			<< CYAN << b << RT << std::endl;
		swap(a, b);
		std::cout << "after:\n\ta: " << CYAN << a << RT << "\n\tb: " \
			<< CYAN << b << RT << std::endl;
		
		//compare again
		std::cout << "\n" << std::endl;
		std::cout << MAG << "--Comparing AGAIN to check!--" << RT << std::endl;

		std::cout << "The max of a: " << CYAN << a << RT \
			<< " and b: " << CYAN << b << RT << " is:" \
			<< "\t" << GREEN << max(a, b) << RT << std::endl;

		std::cout << "The min of a: " << CYAN << a << RT \
			<< " and b: " << CYAN << b << RT << " is:" \
			<< "\t" << GREEN << min(a, b) << RT << std::endl;
	}

	std::cout << "\n\n-----------------------------------------------------" << std::endl;
	std::cout << YELLOW << "-Test 2- |" << RT << std::endl;
	std::cout << YELLOW << "----------" << RT << std::endl;
	{
		std::string	a = "I W From country \"A\"";
		std::string	b = "I manna destroy Country A LOL -B-";

		std::cout << "The max of a: " << CYAN << a << RT " and b: " \
			<< CYAN << b << RT " is:" \
			<< "\t" << GREEN << max(a, b) << RT << std::endl;

		std::cout << "The min of a: " << CYAN << a << RT \
			<< " and b: " << CYAN << b << RT << " is:" \
			<< "\t" << GREEN << min(a, b) << RT << std::endl;

		std::cout << std::endl;

		std::cout << std::endl;
		std::cout << MAG << "-Swapping time!-" << RT << std::endl;
		std::cout << "before:\n\ta: " << CYAN << a << RT "\n\tb: " \
			<< CYAN << b << RT << std::endl;
		swap(a, b);
		std::cout << "after:\n\ta: " << CYAN << a << RT << "\n\tb: " \
			<< CYAN << b << RT << std::endl;
		
		//compare again
		std::cout << "\n" << std::endl;
		std::cout << MAG << "--Comparing AGAIN to check!--" << RT << std::endl;

		std::cout << "The max of a: " << CYAN << a << RT \
			<< " and b: " << CYAN << b << RT << " is:" \
			<< "\t" << GREEN << max(a, b) << RT << std::endl;

		std::cout << "The min of a: " << CYAN << a << RT \
			<< " and b: " << CYAN << b << RT << " is:" \
			<< "\t" << GREEN << min(a, b) << RT << std::endl;
	}
	std::cout << "\n\n-------------------------end-------------------------" << std::endl;
	return 0;
}

