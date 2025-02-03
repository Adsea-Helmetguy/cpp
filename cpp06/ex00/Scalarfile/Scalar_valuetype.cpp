/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
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
static int    Scalar_checkChar(const std::string& value)
{
	if (value[0] < 127 || value[0] > 31)//Checking if ASCII char
        {
		std::cout << GREEN << "Value is part of ASCII printable" \
			RESET << std::endl;
		std::cout << "Checking if it's \"char\"." << std::endl;
		if (value[0] < 48 || value[0] > 57)
		{
			std::cout << BLUE << "Not part of 0-9. Value is \"Char\"" \
				RESET << std::endl;
			return (1);
		}
		else
		{
			std::cout << YELLOW << "it's part of 0-9. Value is \"int\"" \
				RESET << std::endl;
			return (2);
		}
	}
	else
	{
		std::cout << RED << "Value is NOT part of ASCII printable!!" \
			RESET << std::endl;
	}
	std::cout << MAG << "Wait how did u get here? What did i miss?" \
			RESET << std::endl;
	return (0);
};


static bool    Scalar_checkFloat(value, strlen)
{
	size_t	index = 0;
	size_t	index_dot = 0;

	if (value[strlen - 1] == "f")
	{
		while (index < strlen)
		{
			if (value[index] == ".")
				index_dot++;
			index++;
		}
		if (index_dot == 1)
		{
			index_dot = index;
			index = 0;
			while ((index < strlen) && (value[index] >= 48 && value[index] <= 57))
			{
				if (index == index_dot)
					index++;
				index++;
			}
			return (true);
		}
	}
	return (false);
};


static int    Scalar_checknumber(value, strlen)
{
	if (Scalar_checkFloat(value, strlen) == true)
	{
		return ("float");
	}
	else
		return ("impossible");
/*
	else if (Scalar_checkDouble(value, strlen) == true)
	{
		return ("double");
	}
	else if (Scalar_checkInt(value, strlen) == true)
	{
		return ("int");
	}
	else
		return ("impossible");
*/
};


//factors used:
	//Scalar_checkChar(value):
	//Scalar_checknumber(value):
		//Scalar_checkInt(value):
		//Scalar_checkFloat(value):
		//Scalar_checkDouble(value):
std::string    Scalar_value(const std::string& value, const size_t strlen)
{
	int	char_or_not = 0;
	std::string	ifd = "What am i";
	
	//read the arrays one by one
	ifd = Scalar_checknumber(value, strlen):
	//if (ifd == "int" || ifd == "float" || ifd == "double")
	//	return (ifd);

/*
	std::cout << "testing for strlen value of: " \
		<< GREEN << "\"" << value << "\"" << RESET << std::endl;
	std::cout << MAG << strlen << RESET << std::endl;
	if (strlen == 1)//Checking if only one char
	{
		std::cout << "confirmed it's only length of " << std::endl;
		std::cout << GREEN << "\"1\"" << RESET << std::endl;
		char_or_not = Scalar_checkChar(value);
		if (char_or_not == 1)
		{
			std::cout << GREEN << "It is \"char\"!!" \
				<< "Now it's as it shall be!!!" \
				<< RESET << std::endl;
			//convert value to char
			return ("char");
		}
		else if (char_or_not == 2)
			return ("int");
		else
			std::cout << "Damn it" << std::endl;
	}
*/
	//put error if all else fails
	std::cout << RED << "Value is ERROR!" << RESET << std::endl;
	return ("impossible");
};

//void  Scalar_checkChar(const std::string& value, const size_t strlen);

void    Scalar_type(const std::string& value)
{
	//--Conver it from string to actual type!
	//Scalar_type()
	(void)value;

	//These are for printing
	//Scalar_typeChar(value, strlen);
	//Scalar_typeInt(value, strlen);
	//Scalar_typeFloat(value, strlen);
	//Scalar_typeDouble(value, strlen);
};























