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

#ifndef SCALAR_HPP
#define SCALAR_HPP

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

class Scalar
{
	private:
		const std::string	_name;

	public:
		Scalar();								// default constructor
		Scalar(const Scalar& copy);				// copy constructor
		Scalar& operator=(const Scalar& copy);	// Copy assignment
		~Scalar();								// destructor

	char	convert(std::string words);
	int		convert(std::string integer);
	float	convert(std::string float_num);
	double	convert(std::string double_num);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);
#endif

