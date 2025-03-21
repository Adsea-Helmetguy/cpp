/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:41:40 by mlow              #+#    #+#             */
/*   Updated: 2025/03/11 09:41:41 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//objective
/*
1) convert argv into int, check it 0-9.

2) place the values on the stack one by one std::stack
*/

static int	convert_token(const char *string)
{
	std::stringstream ss(string);
	int	i;

	ss >> i;
	std::cout << "INT IS: \"" << GREEN << i << RT << "\"" << std::endl;
	return (i);
};

static std::stack<int>	int_converter(int argc, char **argv)
{
	std::stack<int> int_array;

	for (int a = 1; a < argc; a++)
	{
		int_array.push(convert_token(argv[a]));
	}
	//std::cout << GREEN << "Converted: \"" << YELLOW << int_array 
	//	<< GREEN << "\" into INT!" << RT << std::endl;
	return (int_array);
};

void	RPN_code(int argc, char **argv)
{
	//convert argv into int
	std::stack<int> int_array = int_converter(argc, argv);
};

