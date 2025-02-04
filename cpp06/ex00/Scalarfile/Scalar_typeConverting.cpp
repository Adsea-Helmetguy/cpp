/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar_typeConverting.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:18:25 by mlow              #+#    #+#             */
/*   Updated: 2025/02/04 15:18:30 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void    Scalar_typeFloat(const std::string& value)
{
	std::cout << GREEN << "testing if it comes here first" \
		<< RESET << std::endl;
	//change it to float value!!
	
};

void    Scalar_type(const std::string& value, std::string value_type)
{
	//--Convert it from string to actual type!
	std::cout << "the type of value is: " << GREEN \
		<< value_type << RESET << "." << std::endl;
	if (value_type == "float")
		Scalar_typeFloat(value);
/*
	else if (value_type == "double")
		Scalar_typeFloat(value);
	else if (value_type == "int")
		Scalar_typeFloat(value);
	else if (value_type == "char")
		Scalar_typeFloat(value);
	else
		std::cout << RED << "How did u come here!?" << RESET << std::endl;
*/
	//These are for printing
	//Scalar_typeChar(value, strlen);
	//Scalar_typeInt(value, strlen);
	//Scalar_typeFloat(value, strlen);
	//Scalar_typeDouble(value, strlen);










	(void)value;
	(void)value_type;
	//--Once you have the value of Scalar, convert it 3 more times!--
	//--Then print all four values out in std::cout!
	//Scalar_print();
};

