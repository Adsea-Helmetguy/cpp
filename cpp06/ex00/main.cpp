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

int	main(int argc, char **argv)
{
	//Ensure ScalarConverter::convert
	// is a static before contiuning.
	if (argc == 2)
	{
		std::cout << "Test Case 1 -char-" << std::endl;
		{
			std::cout << RED "ARGV[1]: \"" << argv[1] << "\"" << RESET << std::endl;
			//if its empty please leave it DAMN IT
			ScalarConverter::convert(argv[1]);
		}
	}
	return (0);
}

//links used:
/*
https://faculty.cs.niu.edu/~winans/CS501/Notes/strings.html#:~:text=You%20can%20obtain%20the%20length,valid%20characters%20in%20the%20string.
*/
