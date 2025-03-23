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
	return (f);
};

static bool	fundamental_operations(char character)
{
	if (character == '+' || character == '-' 
		|| character == '/' || character == '*')
		return (true);
	return (false);
};

static float	compare_two_values(float v1, float v2, char character)
{
	float	working = 0;

	if (character == '+')
		working = v1 + v2;
	else if (character == '-')
		working = v1 - v2;
	else if (character == '/')
		working = v1 / v2;
	else if (character == '*')
		working = v1 * v2;
	return (working);
};

static void	after_comparing(std::stack<float> *int_array, char character, int *operation_counter)
{
	float	top_value = 0;
	float	top_value2 = 0;
	float	push_topValue = 0;

	top_value = (*int_array).top();
	(*int_array).pop();
	top_value2 = (*int_array).top();
	(*int_array).pop();

	std::cout << YELLOW << "\t------------\n\tOperator \"" << CYAN \
		<< character << YELLOW << "\"\n\t------------" \
		<< RT << std::endl;

	push_topValue = compare_two_values(top_value2, top_value, character);
	(*int_array).push(push_topValue);
	(*operation_counter)--;
	std::cout << "Working[" << YELLOW << top_value2 << " " \
		<< character << " " << top_value << RT << "] = " \
		<< YELLOW << (*int_array).top() << " | operation_counter = " \
		<< *operation_counter << RT << std::endl;
};

/*
else
{
	std::cerr << "operation_counter == " << operation_counter << std::endl;
	std::cerr << RED << "THIS IS WRONG! FAIL!" << RT << std::endl;
}
*/
static bool	int_converter(int argc, char **argv)
{
	std::stack<float> int_array;
	int	operation_counter = 0;

	for (int a = 1; a < argc; a++)
	{
		if (int_array.size() > 1 && fundamental_operations(argv[a][0]))
		{
			while ((a < argc) && fundamental_operations(argv[a][0]) && operation_counter)
			{
				//Comparing top two stack values
				after_comparing(&int_array, argv[a][0], &operation_counter);
				a++;
			}
			//std::cout << "Operation counter = " << operation_counter << std::endl;
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
				std::cout << "Operation++, counter = " << operation_counter << std::endl;
			}
		}
	}
	std::cout << "\nFINAL Value of top: " << GREEN << int_array.top() << RT << std::endl;
	std::cout << "FINAL Push counter == [" << GREEN \
		<< operation_counter << RT << "]" << RT << std::endl;
	if (operation_counter != 0)
		return (false);
	return (true);
};

void	RPN_code(int argc, char **argv)
{
	//convert argv into int
	//if (argc > 1)
	if (!(int_converter(argc, argv)))
	{
		std::cerr << RED << "ERROR! ARGUMENTS not correct!" << RT << std::endl;
	}
};

