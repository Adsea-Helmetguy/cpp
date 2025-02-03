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
	std::cout << "This doesn't do anything." << std::endl;
};

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	*this = copy;
	std::cout << "Why are you copying? It's empty~" << std::endl;
};

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& copy)
{
	(void)copy;
	std::cout << "Why copy assignment? Nothing here!~" << std::endl;
	return (*this);
};

ScalarConverter::~ScalarConverter()
{
	std::cout << "This doesn't do anything." << std::endl;
};
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------


//const cause the value never changes here
void    ScalarConverter::convert(const std::string& value)
{
	size_t  strlen = value.length();
	std::string	value_type = "What's my type?";

	std::cout << "----------------------" << std::endl;
	std::cout << BLUE << "-ScalarConverter Start!!-" << RESET << std::endl;
	value_type = Scalar_value(value, strlen);//--Detect the type of value the string it passes

	std::cout << "value_type: " << MAG << value_type << RESET << std::endl;
	std::cout << BLUE << "**********************" << RESET << std::endl;
	//--Convert it from string to actual type!
	//--Once you have the value of Scalar, convert it 3 more times!
	//Scalar_type();

	// --Then print all four values out in std::cout!
	//Scalar_print();
	std::cout << "----------------------" << std::endl;
};



std::ostream& operator<<(std::ostream& os, const ScalarConverter& other)
{
	std::cout << "printing all form's information: " << std::endl;
	std::cout << "----------------------------------" << std::endl;
	(void)other;
/*
	std::cout << "Form's _name: " << GREEN << form.getName() << RESET \
	<< std::endl;
	if (form.getBool() == 0)
		std::cout << "Form's _isTheFormSigned: " << RED << "\"Not Signed\"" \
	    	<< RESET << std::endl;
	else
		std::cout << "Form's _isTheFormSigned: " << GREEN << "\"Signed\"" \
			<< RESET << std::endl;
	std::cout << "Form's _requiredGrades: " << GREEN << form.getrequiredGrades() \
	<< RESET << std::endl;
	std::cout << "Form's _execGrades: " << GREEN << form.getexecGrades() \
		<< RESET << std::endl;
*/
	std::cout << "----------------------------------" << std::endl;
	return (os);
};
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
























