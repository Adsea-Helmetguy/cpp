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

#include "Scalarfile/ScalarConverter.hpp"

//For each exercise,
// the type conversion must be solved using one specific type of casting.
int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cout << "\n\n----------------------------------------" \
			<< std::endl;
		std::cout << MAG \
			<< "Please enter a char/ int/ float/ double value" \
			<< " only. Like with \"./convert \'123.97\'\"." \
			<< RESET << std::endl;
		std::cout << "----------------------------------------\n\n" \
			<< std::endl;
		return (0);
	}
	std::cout << "\n\n----------------------------------------" \
		<< std::endl;
	std::cout << RED << "Testing test" << RESET << std::endl;
	//ScalarConverter::convert(argv[1]);//
	std::cout << "----------------------------------------\n\n" \
		<< std::endl;
	return (0);
}
