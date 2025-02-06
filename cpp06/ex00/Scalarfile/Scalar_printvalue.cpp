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
(charValue == "-inff" || charValue == "+inff" || charValue == "nan"\
|| charValue == "-inf" || charValue == "+inf" || charValue == "nanf" )
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
	//char		charValue = static_cast<char>(floatValue);
	//int		floatValue = static_cast<int>(floatValue);
	//double	doubleValue = static_cast<double>(floatValue);

	//if (floatValue std::numeric_limits<float>::infinity()
	std::cout << "Max float: " << std::numeric_limits<float>::max() << std::endl;
	std::cout << "Min positive float: " << std::numeric_limits<float>::min() << std::endl;
	std::cout << "Float infinity: " << std::numeric_limits<float>::infinity() << std::endl;
	std::cout << "double NaNF: " << std::numeric_limits<double>::quiet_NaN() << std::endl;
	
	
	(void)floatValue;
	(void)charImpossible;
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
		std::cout << "int: " << GREEN << intValue \
			<< RESET << std::endl;
		//-----------------------------------------------
		std::cout << std::fixed << std::setprecision(10);
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
