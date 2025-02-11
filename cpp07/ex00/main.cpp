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

int	main(int argc, char **argv)
{
	//Ensure ScalarConverter::convert
	// is a static before contiuning.
	std::cout << "Program start! Checking if ./scalar has arguements" << std::endl;
	if (argc == 2)
	{
		std::cout << "Test Case 1 -char-" << std::endl;
		{
			std::cout << "ARGV[1]: \"" << argv[1] << "\"" << std::endl;
			//if its empty please leave it DAMN IT
			if (!argv[1][0])
			{
				std::cout << RED << "String empty, trying to test me?" << RESET << std::endl;
				return (0);
			}
			ScalarConverter::convert(argv[1]);
		}
	}
	return (0);
}

//links used:
/*
https://faculty.cs.niu.edu/~winans/CS501/Notes/strings.html#:~:text=You%20can%20obtain%20the%20length,valid%20characters%20in%20the%20string.
*/
