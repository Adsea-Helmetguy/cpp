/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
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
# include <string>//std::string
# include <exception>//std::exception, https://en.cppreference.com/w/cpp/header/exception
# include <cstdlib>//atoi() function to convert std::string to int


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
		ScalarConverter();												// default constructor
		ScalarConverter(const ScalarConverter& copy);					// copy constructor
		ScalarConverter& operator=(const ScalarConverter& copy);		// Copy assignment
		~ScalarConverter();												// destructor

	//ex00 requirment. One static method.
	//static, meaning a member function without instantiating the class.
	static void	convert(const std::string& str);
	
};

std::ostream& operator<<(std::ostream& os, const ScalarConverter& other);
#endif

