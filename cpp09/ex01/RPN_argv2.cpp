/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN_argv2.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:28:35 by mlow              #+#    #+#             */
/*   Updated: 2025/03/24 11:38:52 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static float	convert_token(const char *string)
{
	std::stringstream ss(string);
	float	f;

	ss >> f;
	return (f);
};

//work on this ltr std::string
static bool	converting_value(std::string str)
{
	std::stack<float>	int_array;
	int	operation_counter = 0;

	for (int a = 0; a < str.size(); a++)
	{
		std::cout << GREEN << "Array is: " << RT << array << std::endl;
		if (sizeof_array(array) > 1)
			return (false);
		if (array[0] >= 48 && array[0] <= 57)
		{
			int_array.push(convert_token(array));
			if (int_array.size() > 1)
			{
				operation_counter++;
				std::cout << "Operation++, counter = " \
					<< operation_counter << std::endl;
				
			}
		}
	}
	return (true);
};

void	RPN_argv2code(char *string)
{
	std::cout << CYAN << "\n" <<\
		"\t=============================\n" << \
		"\t|Starting RPN_argv2code now.|\n" << \
		"\t=============================" << RT << std::endl;

	if (!(converting_value(string)))
	{
		std::cerr << RED << "ERROR! ARGC == 2, " << \
			"ARGUMENTS not correct!" << RT << std::endl;
	}
};
