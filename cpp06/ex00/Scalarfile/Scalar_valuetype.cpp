/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar_valuetype.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:34:28 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:34:30 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//https://www.twitch.tv/shashshy
//miss uptoyou LOL

/*
------------
example:   |
------------
char: a
int: 0
float: 0.0f
double: 0.0
*/
//

static bool    Scalar_checkFloat(const std::string& value, const size_t strlen)
{
	size_t	index = 0;
	size_t	index_dot = 0;

	if (value == "-inff" || value == "+inff" || value == "inff" || value == "nanf")
		return (true);
	if (value[strlen - 1] == 'f')
	{
		while (index < strlen)
		{
			if (value[index] == '.')
				index_dot++;
			index++;
		}
		if (index_dot == 0 || index_dot == 1)
		{
			index = 0;
			std::cout << "value of value[0]: " << GREEN << value[0] << RESET << std::endl;
			if (value[0] == '-' || value[0] == '+')
				index = 1;
			while ((index < strlen) && (value[index] >= 48 && value[index] <= 57))
			{
				index++;
				if (value[index] == '.')
				{
					std::cout << "value of value[index]: " << GREEN \
						<< value[index] << RESET << std::endl;
					index++;
				}
				std::cout << "value of value[index]: " << GREEN << value[index] \
					<< RESET << std::endl;
			}
			if (value[index] == 'f' && index == (strlen - 1))
				return (true);
		}
	}
	return (false);
};

static bool    Scalar_checkDouble(const std::string& value, const size_t strlen)
{
	size_t	index = 0;
	size_t	index_dot = 0;

	if (value == "-inf" || value == "+inf" || value == "inf" || value == "nan")
		return (true);
	if (value[strlen - 1] != 'f')
	{
		while (index < strlen)
		{
			if (value[index] == '.')
				index_dot++;
			index++;
		}
		if (index_dot == 1)
		{
			index = 0;
			std::cout << "value of value[0]: " << GREEN << value[0] << RESET << std::endl;
			if (value[0] == '-' || value[0] == '+')
				index = 1;
			while ((index < strlen) && (value[index] >= 48 && value[index] <= 57))
			{
				index++;
				if (value[index] == '.')
				{
					std::cout << "value of value[index]: " << GREEN \
						<< value[index] << RESET << std::endl;
					index++;
				}
				std::cout << "value of value[index]: " << GREEN << value[index] \
					<< RESET << std::endl;
			}
			if (index == strlen)
				return (true);
		}
	}
	return (false);
};

static bool    Scalar_checkInt(const std::string& value, const size_t strlen)
{
	size_t	index = 0;

	std::cout << "value of value[0]: " << GREEN << value[0] << RESET << std::endl;
	if ((value[0] == '-' || value[0] == '+') && strlen != 1)
		index = 1;
	while ((index < strlen) && (value[index] >= 48 && value[index] <= 57))
		index++;
	if (index == strlen)
		return (true);
	return (false);
};

static bool    Scalar_checkChar(const std::string& value, const size_t strlen)
{
	size_t	index = 0;

	while (index < strlen)
	{
		if (value[index] > 31 && value[index] < 127)//Checking if ASCII char
		{
			std::cout << GREEN << "Value: " << RESET << value[index] \
				<< GREEN " is part of ASCII printable" \
				<< RESET << std::endl;
		}
		else
		{
			std::cout << RED << "Value is NOT part of ASCII printable!!" \
				<< RESET << std::endl;
			return (false);
		}
		index++;
	}
	std::cout << GREEN << "Looks like all is GREEN~!" << RESET << std::endl;
	return (true);
};

std::string    Scalar_value(const std::string& value, const size_t strlen)
{
	if (Scalar_checkFloat(value, strlen) == true)
	{
		return ("float");
	}
	else if (Scalar_checkDouble(value, strlen) == true)
	{
		return ("double");
	}
	else if (Scalar_checkInt(value, strlen) == true)
	{
		return ("int");
	}
	else if (Scalar_checkChar(value, strlen) == true)
	{
		return ("char");
	}
	//put error if all else fails
	std::cout << RED << "Value is ERROR! Stop program here!" << RESET << std::endl;
	return ("impossible");
};
