/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:18:14 by mlow              #+#    #+#             */
/*   Updated: 2025/04/19 13:18:33 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

float	compare_two_values(float v1, float v2, char character)
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

float	convert_token_argv2(std::string string)
{
	std::stringstream ss(string);
	float	f;

	ss >> f;
	if (ss.fail())
	{
		std::cerr << RED << "Conversion failed for token: [" << string << "]" << RT << std::endl;
		return (0);
	}
	return (f);
};

bool	fundamental_operations_argv2(char character)
{
	if (character == '+' || character == '-' 
		|| character == '/' || character == '*')
		return (true);
	return (false);
};

float	convert_token(const char *string)
{
	std::stringstream ss(string);
	float	f;

	ss >> f;
	if (ss.fail())
	{
		std::cerr << RED << "Conversion failed for token: [" << string << "]" << RT << std::endl;
		return (0);
	}
	return (f);
};

bool	fundamental_operations(char character)
{
	if (character == '+' || character == '-' 
		|| character == '/' || character == '*')
		return (true);
	return (false);
};

void	after_comparing(std::stack<float> *int_array, char character, int *operation_counter)
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
