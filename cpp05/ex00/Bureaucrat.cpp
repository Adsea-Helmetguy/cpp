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

Bureaucrat::Bureaucrat() : _constant_name("Default_Bureaucrat"), _grade(150)
{
	std::cout << RED << "Bureaucrat Default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name) : _constant_name(name), _grade(150)
{
	std::cout << RED << "Bureaucrat" << this->_constant_name \
	<< " constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) 
	: _constant_name(other._constant_name), _grade(other._grade)
{
	std::cout << RED << "Bureaucrat copy constructor called" << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this == &other)
	{
		std::cout << "Don't Self-assign!!" << std::endl;
		return *this;
	}
	//since it's a constant name, it cannot be copied.
	this->_grade = other._grade;
	std::cout << RED << "Bureaucrat copy assignment constructor called" << RESET << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Deconstructor " << RED << this->_constant_name << RESET << \
	" called: " << std::endl;
}

std::string		Bureaucrat::getName(void) const
{
	return(this->_constant_name);
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

GradeTooHighException::GradeTooHighException()
{
	
}

std::string		Bureaucrat::getName() const
{
	return(this->_constant_name);
}

unsigned int	Bureaucrat::getGrade() const
{
	return(this->_grade);
}

void			Bureaucrat::incrementGrade()
{
    if (this->_grade <= 1)
        throw MyException("Grade is too high!");
    this->_grade--;
}

void			Bureaucrat::decrementGrade()
{
    if (this->_grade >= 150)
        throw MyException("Grade is too low!");
    this->_grade++;
}

/*
Exception Classes here!
class Exception : public std::exception
{
private:
	std::string			_message;
public:
	virtual std::string	what();
};
*/
void			Bureaucrat::GradeTooHighException::MyException(const std::string& message)
{
	
}








