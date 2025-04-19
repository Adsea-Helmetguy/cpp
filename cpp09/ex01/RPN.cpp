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

static bool	int_converter(int argc, char **argv)
{
	std::stack<float>	int_array;
	int	operation_counter = 0;

	for (int a = 1; a < argc; a++)
	{
		if (int_array.size() > 1 && fundamental_operations(argv[a][0]))
		{
			while ((a < argc) && fundamental_operations(argv[a][0]) && operation_counter)
			{
				after_comparing(&int_array, argv[a][0], &operation_counter);
				a++;
			}
			std::cout << YELLOW << "Current size: " << CYAN << int_array.size() << RT \
				<< YELLOW << " | character: " << CYAN << int_array.top() << \
				YELLOW << " | " << GREEN << "operation counter == [" << CYAN \
					<< operation_counter << GREEN << "]" << RT << std::endl;
			if (operation_counter != 0)
				return (false);
		}
		if (a < argc)
		{
			int_array.push(convert_token(argv[a]));
			if (int_array.size() > 1)
			{
				operation_counter++;
				std::cout << "Operation++, counter = " \
					<< operation_counter << std::endl;
			}
		}
	}
	std::cout << "FINAL Push counter == [" << GREEN \
		<< operation_counter << RT << "]" << RT << std::endl;
	if (operation_counter != 0)
		return (false);
	std::cout << "\nFINAL Value of top: " << GREEN << int_array.top() << RT << std::endl;
	return (true);
};

void	RPN_code(int argc, char **argv)
{
	std::cout << GREEN << "\n" <<\
		"\t========================\n" << \
		"\t|Starting RPN_CODE now.|\n" << \
		"\t========================" << RT << std::endl;

	if (!(int_converter(argc, argv)))
	{
		std::cerr << RED << "ERROR! ARGUMENTS not correct!" << RT << std::endl;
	}
};

