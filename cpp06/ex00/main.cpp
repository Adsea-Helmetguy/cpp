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

int	main()
{
	//Ensure ScalarConverter::convert
	// is a static before contiuning.
	std::cout << "Test Case 1 -char-" << std::endl;
	{
		ScalarConverter::convert("a");
	}
	return (0);
}

//links used:
/*
https://faculty.cs.niu.edu/~winans/CS501/Notes/strings.html#:~:text=You%20can%20obtain%20the%20length,valid%20characters%20in%20the%20string.
*/
