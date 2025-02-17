/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:35:16 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:35:18 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP


# include <iostream>
# include <fstream>//*new ex02* std::basic_ofstream
# include <string>//std::string
# include <exception>//std::exception, https://en.cppreference.com/w/cpp/header/exception

# include "Bureaucrat/Bureaucrat.hpp"


# define RESET	"\033[0m"
# define RED	"\033[31m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define GREEN	"\033[32m"
# define MAG	"\e[0;35m"
// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class ShrubberyCreationForm : public AForm
{
	//private:
	//	std::string		_target;
	
	public:
		ShrubberyCreationForm();												// default constructor
		ShrubberyCreationForm(const std::string& name);							// default constructor with name
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);				// copy constructor
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& form);	// copy assignment
		~ShrubberyCreationForm();												// destructor

		//create a file
		void	execute(Bureaucrat const & executor);
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& other);
#endif
