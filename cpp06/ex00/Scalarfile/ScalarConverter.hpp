/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:35:16 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:35:18 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <iostream>
# include <string>//std::string && "<class>.size() /length();""
# include <cstdlib>//atoi() function to convert std::string to int
# include <sstream>//std::stringstream
# include <cstring>// For strcpy
# include <iomanip> // for std::fixed and std::setprecision
# include <limits.h>//INT_MIN/MAX
# include <limits>
# include <cfloat>//for floats min/max, infinityf and nanf
# include <cmath>// for std::isnan() to check for float value "nan"

# define RESET	"\033[0m"
# define RED	"\033[31m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define GREEN	"\033[32m"
# define MAG	"\e[0;35m"
// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class ScalarConverter
{
	public:
		ScalarConverter();											// default constructor
		ScalarConverter(const ScalarConverter& copy);				// copy constructor
		ScalarConverter& operator=(const ScalarConverter& copy);	// Copy assignment
		~ScalarConverter();											// destructor

	static void	convert(const std::string& value);//static method
};

std::string	Scalar_value(const std::string& value, const size_t strlen);
void	Scalar_type(const std::string& value, std::string value_type);

void	printValue_char(size_t index, char *charValue, std::string& charImpossible);
void	printValue_int(long intValue, std::string& charImpossible);
void	printValue_float(float floatValue, std::string& charImpossible, const std::string& value);
void	printValue_double(double doubleValue, std::string& charImpossible, const std::string& value);

std::ostream& operator<<(std::ostream& os, const ScalarConverter& other);
#endif

