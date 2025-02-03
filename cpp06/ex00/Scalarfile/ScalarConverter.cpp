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

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
ScalarConverter::ScalarConverter()
{

};

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	*this = copy;
};

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& copy)
{
	if (*this == copy)
	{
		std::cout << "don't self assign.....but again nothing to copy...." \
			<< std:endl;	
	}
	else
		std::cout << "Tbh this is useless. Nothing was copied anyways." \
			<< std:endl;
	return (*this);
};

ScalarConverter::~ScalarConverter()
{

};
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

//if argv is valid literal, convert and print all them into 4 types.
//For each exercise,
// the type conversion must be solved using one specific type of casting.
void	ScalarConverter::convert(const std::string& str)
{
	//what type is it?
	//ScalarType(str);

//----------------------------------------------------------------------
//----------------------------------------------------------------------
	//=====char=====
	size_t	length = str.size;// Get the string length
	
	if (length == 1)
	{
		if (str >= 32 && str <= 126)
		{
			std::cout << str << std::endl;
		}
		else
		{
			std::cout << "Non-displayable character (ASCII: " \
				<< static_cast<int>(str) << ")" << std::endl;
		}
	}

	//=====int=====
	int	input = 0;

	input = atoi(str.c_str());
	std::cout << "Converted to int: " << input << std::endl;
};
//----------------------------------------------------------------------
//----------------------------------------------------------------------


//------- INDEX -------
	size_t	index = 0;
//---------------------



























