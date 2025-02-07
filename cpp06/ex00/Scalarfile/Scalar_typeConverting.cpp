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

static bool	float_pseudo_literals(const std::string& value)
{
	std::cout << "Changing value float literals to value" << std::endl;
	if (value == "-inff" || value == "+inff" || value == "inff" || value == "nanf")
	{
		return (true);
	}
	return (false);
};

static bool	double_pseudo_literals(const std::string& value)
{
	std::cout << "Changing value double literals to value" << std::endl;
	if (value == "-inf" || value == "+inf" || value == "inf" || value == "nan")
	{
		return (true);
	}
	return (false);
};

//good link:
//https://stackoverflow.com/questions/43810190/string-to-long-double-conversion-in-c98
static void    Scalar_typeFloat(const std::string& value)
{
	std::string	converted_value = value;
	float		floatValue;
	std::string	charImpossible = "impossible";

	if (float_pseudo_literals(value) == false)
	{
		std::stringstream ss(converted_value);//change it to float value!!
		std::cout << "ss(" << YELLOW << ss << RESET << ")" << std::endl;
		ss >> floatValue;
		std::cout << "FloatValue(" << YELLOW << &floatValue << RESET \
			<< ") = " << MAG << floatValue << "f" << RESET << std::endl;
	}
	else
	{
		if (value == "+inff" || value == "inff")
			floatValue = std::numeric_limits<float>::infinity();
		else if (value == "-inff")
			floatValue = -std::numeric_limits<float>::infinity();
		else
			floatValue = std::numeric_limits<float>::quiet_NaN();
	}
	//--Once you have the value of Scalar, convert it 3 more times!--
	//--Then print all four values out in std::cout!
	//create a function called: contains_pseudo_literals()
	//if (charValue == "-inf" || charValue == "+inf" || charValue == "nanf")
	/*
	stuff happens
	*/
	printValue_float(floatValue, charImpossible);
};

// std::cout << "Max float: " << std::numeric_limits<float>::max() << std::endl;
// std::cout << "Min positive float: " << std::numeric_limits<float>::min() << std::endl;
// std::cout << "Float infinity: " << std::numeric_limits<float>::infinity() << std::endl;
// std::cout << "double NaNF: " << std::numeric_limits<double>::quiet_NaN() << std::endl;
static void    Scalar_typeDouble(const std::string& value)
{
	std::string	converted_value = value;
	double		doubleValue;
	std::string	charImpossible = "impossible";

	if (double_pseudo_literals(value) == false)
	{
		if (!value.empty() && value[value.length() - 1] == 'f')
			converted_value = value.substr(0, value.length());
		std::stringstream ss(converted_value);//change it to float value!!
		std::cout << "ss(" << YELLOW << ss << RESET << ")" << std::endl;
		ss >> doubleValue;
		std::cout << "doubleValue(" << YELLOW << &doubleValue << RESET \
			<< ") = " << MAG << doubleValue << RESET << std::endl;
	}
	else
	{
		if (value == "+inf" || value == "inf")
			doubleValue = std::numeric_limits<double>::infinity();
		else if (value == "-inf")
			doubleValue = -std::numeric_limits<double>::infinity();
		else
			doubleValue = std::numeric_limits<double>::quiet_NaN();
	}
	//--Once you have the value of Scalar, convert it 3 more times!--
	//--Then print all four values out in std::cout!
	printValue_double(doubleValue, charImpossible);
};

//don't forget about intMAX and intMIN
static void    Scalar_typeInt(const std::string& value)
{
	std::string	converted_value = value;
	size_t		index = 0;
	long		intValue;
	std::string	charImpossible = "impossible";

	if (!value.empty() && value[value.length() - 1] == 'f')
	{
		if (value[index] == '-' || value[index] == '+')
			index++;
		while (index < value.length() && (value[index] >= 48 && value[index] <= 57))
			index++;
		if (index == value.length())
			converted_value = value.substr(0, value.length() - 1);
	}
	std::stringstream ss(converted_value);//change it to float value!!
	std::cout << "ss(" << YELLOW << ss << RESET << ")" << std::endl;
	ss >> intValue;
	std::cout << "intValue(" << YELLOW << &intValue << RESET \
		<< ") = " << MAG << intValue << RESET << std::endl;

	//--Once you have the value of Scalar, convert it 3 more times!--
	//--Then print all four values out in std::cout!
	printValue_int(intValue, charImpossible);
};

//https://www.geeksforgeeks.org/convert-string-char-array-cpp/
//#include <cstring>// For strcpy
//make sure it's only one char. If not write either impossible or undefined.
static void    Scalar_typeChar(const std::string& value)
{
	size_t		index = value.length();
	char		charValue[index + 1];
	std::string	charImpossible = "impossible";

	strcpy(charValue, value.c_str());
	std::cout << "strcpy charValue: " << MAG << charValue \
		<< RESET << std::endl;
	
	//--Once you have the value of Scalar, convert it 3 more times!--
	//--Then print all four values out in std::cout!
	printValue_char(index, charValue, charImpossible);
};

void    Scalar_type(const std::string& value, std::string value_type)
{
	//--Convert it from string to actual type!
	std::cout << "the type of value is: " << GREEN \
		<< value_type << RESET << "." << std::endl;
	if (value_type == "float")
		Scalar_typeFloat(value);
	else if (value_type == "double")
		Scalar_typeDouble(value);
	else if (value_type == "int")
		Scalar_typeInt(value);
	else if (value_type == "char")
		Scalar_typeChar(value);
	else
		std::cout << RED << "How did u come here!?" << RESET << std::endl;










	(void)value;
	(void)value_type;
	//--Once you have the value of Scalar, convert it 3 more times!--
	//--Then print all four values out in std::cout!
	//Scalar_print();
};

//links to defend:
/*
--human reads 1.f--
https://stackoverflow.com/questions/26100753/what-does-1-f-mean
*/
