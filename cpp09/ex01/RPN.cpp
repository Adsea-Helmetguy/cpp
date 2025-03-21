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

static float	convert_token(const char *string)
{
	std::stringstream ss(string);
	float	f;

	ss >> f;
	std::cout << "INT IS: \"" << GREEN << f << RT << "\"" << std::endl;
	return (f);
};

static std::stack<float>	int_converter(int argc, char **argv)
{
	std::stack<float> int_array;
	float	new_value = 0;

	for (int a = 1; a < argc; a++)
	{
		if (int_array.size() == 2)
		{
			if (argv[a][0] == '+' || argv[a][0] == '-' 
				|| argv[a][0] == '/' || argv[a][0] == '*')
			{
				new_value = int_array.top();
				int_array.pop();
				if (argv[a][0] == '+')
				{
					new_value += int_array.top();
				}
				if (argv[a][0] == '-')
				{
					new_value -= int_array.top();
				}
				if (argv[a][0] == '/')
				{
					new_value /= int_array.top();
				}
				if (argv[a][0] == '*')
				{
					new_value *= int_array.top();
				}
				int_array.pop();
				std::cout << "Size after pop now: " \
					<< int_array.size() << std::endl;
			}
		}
		int_array.push(convert_token(argv[a]));
	}
	//std::cout << GREEN << "Converted: \"" << YELLOW << int_array 
	//	<< GREEN << "\" into INT!" << RT << std::endl;
	return (int_array);
};

void	RPN_code(int argc, char **argv)
{
	//convert argv into int
	std::stack<float> int_array = int_converter(argc, argv);
};

