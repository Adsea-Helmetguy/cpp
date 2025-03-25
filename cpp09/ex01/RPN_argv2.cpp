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

static float	convert_token(std::string string)
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
	std::string		split_value;
	int			operation_counter = 0;
	int			start = 0;

	std::cout << "size(" << CYAN << str.size() << RT << ")" << std::endl;
	for (size_t a = 0; a <= str.size(); a++)
	{
		while (a != str.size() && !std::isspace(str[a]))
		{
			if (fundamental_operations(str[a]) && operation_counter != 0)
			{
				after_comparing(&int_array, str[a], &operation_counter);
			}
			else if (str[a] && (str[a] < '0' || str[a] > '9'))
			{
				std::cerr << RED << "Invalid element found" << RT << std::endl;
				return (false);
			}
			a++;
		}
		if ((!(str[a]) || std::isspace(str[a])) && (a != 0 && (!fundamental_operations(str[a - 1]))))
		{
			split_value = str.substr(start, (a - start));
			int_array.push(convert_token(split_value));
			if (int_array.size() > 1)
			{
				operation_counter++;
				std::cout << "Operation++, counter = " \
					<< operation_counter << std::endl;
			}
			start = a + 1;
		}
	}
	std::cout << "FINAL Push counter == [" << GREEN \
		<< operation_counter << RT << "]" << RT << std::endl;
	if (operation_counter != 0)
		return (false);
	std::cout << "\nFINAL Value of top: " << GREEN << int_array.top() << RT << std::endl;
	return (true);
};

void	RPN_argv2code(std::string string)
{
	std::cout << CYAN << "\n" <<\
		"\t=============================\n" << \
		"\t|Starting RPN_argv2code now.|\n" << \
		"\t=============================" << RT << std::endl;

	if (!(converting_value(string)))
	{
		std::cerr << RED << "ERROR! " << \
			"ARGUMENTS not correct!" << RT << std::endl;
	}
};
