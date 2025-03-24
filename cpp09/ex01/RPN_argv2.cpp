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
	//int			operation_counter = 0;
	std::string	split_value;
	int			start = 0;

	for (size_t a = 0; a < str.size(); a++)
	{
		if (str[a] != ' ' && str[a] != '\t')
		{
			if (a == (str.size() - 1) || str[a] == ' ' || str[a] == '\t')
			{
				split_value = str.substr(start, (a - start));
				int_array.push(convert_token(split_value));
				std::cout << "int_array top value: " << CYAN \
					<< int_array.top() << RT << std::endl;
				start = a;
			}
			else if (str[a] < '0' || str[a] > '9')
			{
				std::cerr << RED << "Invalid element found" << RT << std::endl;
				return (false);
			}
		}
	}
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
