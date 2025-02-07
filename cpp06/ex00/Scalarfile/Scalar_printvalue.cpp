/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar_printvalue.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:18:25 by mlow              #+#    #+#             */
/*   Updated: 2025/02/04 15:18:30 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//These are for printing
	//Scalar_typeChar(value, strlen);
	//Scalar_typeInt(value, strlen);
	//Scalar_typeFloat(value, strlen);
	//Scalar_typeDouble(value, strlen);

//static bool	contains_pseudo_literals()
//{
/*
(charValue == "-inff" || charValue == "+inff" || charValue == "nanf"\
|| charValue == "-inf" || charValue == "+inf" || charValue == "nan" )
	if (std::strcmp(charValue, "-inff") == 0 || std::strcmp(charValue, "+inff") == 0 \
		|| std::strcmp(charValue, "nanf") == 0)
	{
		std::cout << "char: " << RED << charImpossible << RESET << std::endl;
		std::cout << "int: " << RED << charImpossible << RESET << std::endl;
		std::cout << "float: " << RED << charValue << "f" << RESET << std::endl;
		std::cout << "double: " << RED << charValue << RESET << std::endl;
	}
	else if (std::strcmp(charValue, "-inf") == 0 || std::strcmp(charValue, "+inf") == 0 \
		|| std::strcmp(charValue, "nan") == 0)
	{
		std::cout << "char: " << RED << charImpossible << RESET << std::endl;
		std::cout << "int: " << RED << charImpossible << RESET << std::endl;
		std::cout << "float: " << RED << charValue << "f" << RESET << std::endl;
		std::cout << "double: " << RED << charValue << RESET << std::endl;
	}
	else 
*/
//};
//std::cout << "Double NaN: " << std::numeric_limits<double>::quiet_NaN() << std::endl;

void	printValue_float(float floatValue, std::string& charImpossible)
{
	char		charValue = static_cast<char>(floatValue);
	long		intValue = static_cast<long>(floatValue);
	double		doubleValue = static_cast<double>(floatValue);

	//You need to use the std::isnan() function from <cmath> to check if floatValue is NaN:
	if (floatValue == std::numeric_limits<float>::infinity() 
		|| floatValue == -std::numeric_limits<float>::infinity()
		|| std::isnan(floatValue))
	{
		std::cout << RED << "--floatValue (+/-)inff or nanf--" \
			<< RESET << std::endl;
		std::cout << "char: " << RED << charImpossible \
			<< RESET << std::endl;
		std::cout << "int: " << RED << charImpossible \
			<< RESET << std::endl;
		//-----------------------------------------------
		std::cout << std::fixed << std::setprecision(1);
		//-----------------------------------------------
		std::cout << "float: " << RED << floatValue \
			<< "f" << RESET << std::endl;
		std::cout << "double: " << RED << doubleValue \
			<< RESET << std::endl;
	}
	else
	{
		if (floatValue >= 32.0f && floatValue <= 126.0f)
		{
			std::cout << "char: " << GREEN << charValue \
				<< RESET << std::endl;
		}
		else if (floatValue >= 0.0f && floatValue <= 127.0f)
		{
			std::cout << "char: " << GREEN << "Non displayable" \
				<< RESET << std::endl;
		}
		else
		{
			std::cout << "char: " << RED << charImpossible \
				<< RESET << std::endl;
		}

		if (intValue > INT_MAX || intValue < INT_MIN)
		{
			std::cout << "int: " << RED << charImpossible \
				<< RESET << std::endl;
		}
		else
		{
			std::cout << "int: " << GREEN << intValue \
				<< RESET << std::endl;
		}
		//-----------------------------------------------
		std::cout << std::fixed << std::setprecision(1);
		//-----------------------------------------------
		std::cout << "float: " << GREEN << floatValue \
			<< "f" << RESET << std::endl;
		std::cout << "double: " << GREEN << doubleValue \
			<< RESET << std::endl;
	}
};

void	printValue_double(double doubleValue, std::string& charImpossible)
{
	char		charValue = static_cast<char>(doubleValue);
	long		intValue = static_cast<long>(doubleValue);
	float		floatValue = static_cast<float>(doubleValue);

	//You need to use the std::isnan() function from <cmath> to check if floatValue is NaN:
	if (doubleValue == std::numeric_limits<double>::infinity() 
		|| doubleValue == -std::numeric_limits<double>::infinity()
		|| std::isnan(doubleValue))
	{
		std::cout << RED << "--doubleValue (+/-)inf or nan--" \
			<< RESET << std::endl;
		std::cout << "char: " << RED << charImpossible \
			<< RESET << std::endl;
		std::cout << "int: " << RED << charImpossible \
			<< RESET << std::endl;
		//-----------------------------------------------
		std::cout << std::fixed << std::setprecision(1);
		//-----------------------------------------------
		std::cout << "float: " << RED << floatValue \
			<< "f" << RESET << std::endl;
		std::cout << "double: " << RED << doubleValue \
			<< RESET << std::endl;
	}
	else
	{
		if (doubleValue >= 32.0 && doubleValue <= 126.0)
		{
			std::cout << "char: " << GREEN << charValue \
				<< RESET << std::endl;
		}
		else if (doubleValue >= 0.0 && doubleValue <= 127.0)
		{
			std::cout << "char: " << GREEN << "Non displayable" \
				<< RESET << std::endl;
		}
		else
		{
			std::cout << "char: " << RED << charImpossible \
				<< RESET << std::endl;
		}

		if (intValue > INT_MAX || intValue < INT_MIN)
		{
			std::cout << "int: " << RED << charImpossible \
				<< RESET << std::endl;
		}
		else
		{
			std::cout << "int: " << GREEN << intValue \
				<< RESET << std::endl;
		}
		//-----------------------------------------------
		std::cout << std::fixed << std::setprecision(1);
		//-----------------------------------------------
		std::cout << "float: " << GREEN << floatValue \
			<< "f" << RESET << std::endl;
		std::cout << "double: " << GREEN << doubleValue \
			<< RESET << std::endl;
	}
};

//(*1)
void	printValue_int(long intValue, std::string& charImpossible)
{
	char		charValue = static_cast<char>(intValue);
	float		floatValue = static_cast<float>(intValue);
	double		doubleValue = static_cast<double>(intValue);

	std::cout << "int_Max: "<< RED << INT_MAX << RESET << std::endl;
	std::cout << "int_Min: "<< RED << INT_MIN << RESET << std::endl;
	if (intValue > INT_MAX || intValue < INT_MIN)
	{
		std::cout << RED << "--intValue beyond INT_MIN/MAX!!--" \
			<< RESET << std::endl;//undefined behavior!!
		std::cout << "char: " << RED << charImpossible \
			<< RESET << std::endl;
		std::cout << "int: " << RED << charImpossible \
			<< RESET << std::endl;
		//-----------------------------------------------
		std::cout << std::fixed << std::setprecision(1);
		//-----------------------------------------------
		std::cout << "float: " << RED << charImpossible \
			<< RESET << std::endl;
		std::cout << "double: " << RED << charImpossible \
			<< RESET << std::endl;
	}
	else
	{
		std::cout << GREEN << "--Yey good job--" << RESET << std::endl;
		if (intValue > 31 && intValue < 127)
		{
			std::cout << "\"31 > value < 127\"" << std::endl;
			std::cout << "char: " << GREEN << charValue \
				<< RESET << std::endl;
		}
		else
		{
			std::cout << "\"31 < value > 127\"" << std::endl;
			std::cout << "char: " << RED << "Non displayable" \
				<< RESET << std::endl;
		}
		std::cout << "int: " << GREEN << intValue \
			<< RESET << std::endl;
		//-----------------------------------------------
		std::cout << std::fixed << std::setprecision(1);
		//-----------------------------------------------
		std::cout << "float: " << GREEN << floatValue \
			<< "f" << RESET << std::endl;
		std::cout << "double: " << GREEN << doubleValue \
			<< RESET << std::endl;
	}
};

void	printValue_char(size_t index, char *charValue, std::string& charImpossible)
{
	int		intValue = static_cast<int>(charValue[0]);
	float		floatValue = static_cast<float>(charValue[0]);
	double		doubleValue = static_cast<double>(charValue[0]);

	if (index == 1)
	{
		std::cout << "char: " << GREEN << charValue \
			<< RESET << std::endl;
		if (intValue > INT_MAX || intValue < INT_MIN)
		{
			std::cout << "int: " << GREEN << charImpossible \
				<< RESET << std::endl;
		}
		else
		{
			std::cout << "int: " << GREEN << intValue \
				<< RESET << std::endl;
		}
		//-----------------------------------------------
		std::cout << std::fixed << std::setprecision(1);
		//-----------------------------------------------
		std::cout << "float: " << GREEN << floatValue \
			<< "f" << RESET << std::endl;
		std::cout << "double: " << GREEN << doubleValue \
			<< RESET << std::endl;
	}
	else
	{
		std::cout << "char: " << RED << charImpossible \
			<< RESET << std::endl;
		std::cout << "int: " << RED << charImpossible \
			<< RESET << std::endl;
		//-----------------------------------------------
		std::cout << std::fixed << std::setprecision(1);
		//-----------------------------------------------
		std::cout << "float: " << RED << charImpossible \
			<< RESET << std::endl;
		std::cout << "double: " << RED << charImpossible \
			<< RESET << std::endl;
	}
};

//links:
/*
--(*1)this one is for INT_MIN/MAX--
https://www.digitalocean.com/community/tutorials/int-max-min-c-plus-plus


*/
