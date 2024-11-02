/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:34:28 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:34:30 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : type("Default_Bureaucrat")
{
	std::cout << RED << "Bureaucrat Default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name) : type(name)
{
	std::cout << RED << "Bureaucrat with std::string& name constructor called" \
	<< RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : type(other.type)
{
	std::cout << RED << "Bureaucrat copy constructor called" << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this == &other)//need to add & because 'this' is a pointer
	{
		std::cout << "Don't Self-assign!!" << std::endl;
		return *this; // handle self-assignment
	}
	type = other.type;
	std::cout << RED << "Bureaucrat copy assignment constructor called" << RESET << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Deconstructor " << RED << this->type << RESET << \
	" called: " << std::endl;
}

std::string		Bureaucrat::getName(void) const
{
	return(this->type);
}

/*
The thrown exceptions must be catchable using try and catch blocks:

	try
	{
		// do some stuff with bureaucrats
	}
	catch (std::exception & e)
	{
		// handle exception
	}

You will implement an overload of the insertion («) operator to print something like
(without the angle brackets):

	<name>, bureaucrat grade <grade>.
*/
void			Bureaucrat::GradeTooHighException()
{
	std::cout << BLUE << "Default Bureaucrat noises." << RESET << std::endl;
}
void			Bureaucrat::GradeTooLowException()
{
	std::cout << BLUE << "Default Bureaucrat noises." << RESET << std::endl;
}

std::string		getName() const
{
	return(this->_constant_name);
}

std::string		getGrade() const
{
	return(this->_constant_name);
}

void		incrementGrade()
{
	this->_grade++;
}

void		decrementGrade()
{
	this->_grade--;
}
















