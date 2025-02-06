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
--(*1)this one is for converting int to char--



*/
