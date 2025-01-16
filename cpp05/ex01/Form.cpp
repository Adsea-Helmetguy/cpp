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

#include "Bureaucrat.hpp"

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

Bureaucrat::Bureaucrat() : _name("Default Bureaucrat"), _grade(150)
{
	std::cout << "default constructor, Created: " << GREEN \
		<< this->_name << YELLOW \
		<< " with = " << GREEN << this->_grade \
		<< YELLOW << " grade." << RESET << std::endl;
};

Bureaucrat::Bureaucrat(const std::string& name) : _name(name), _grade(150)
{
	std::cout << "default constructor with name, Created: " \
		<< GREEN << this->_name << YELLOW \
		<< " with = " << GREEN << this->_grade \
		<< YELLOW << " grade." << RESET << std::endl;
};

Bureaucrat::Bureaucrat(const Bureaucrat &copy) 
	: _name(copy._name), _grade(copy._grade)
{
	std::cout << "copy constructor, Created: " \
		<< GREEN << this->_name << YELLOW \
		<< " with = " << GREEN << this->_grade \
		<< YELLOW << " grade." << RESET << std::endl;
};

Bureaucrat::Bureaucrat(int value) : _name("Default Bureaucrat"), _grade(value)
{
	std::cout << "default constructor with int, Created: " \
		<< GREEN << this->_name << YELLOW \
		<< " with = " << GREEN << this->_grade \
		<< YELLOW << " grade." << RESET << std::endl;
};

Bureaucrat::Bureaucrat(int value, const std::string& name) : _name(name), _grade(value)
{
	std::cout << "constructor with int && name, Created: " \
		<< GREEN << this->_name << YELLOW \
		<< " with = " << GREEN << this->_grade \
		<< YELLOW << " grade." << RESET << std::endl;
};

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& copy)
{
	if (this == &copy) //checks the address of copy
	{
		std::cout << RED << "Don't SELF-ASSIGN!!!" << RESET << std::endl;
		return (*this); // dereference pointer to give back actual object(Bureacucrat&)
	}
	//since it's a constant name, it cannot be copied.
	//this->_name = other.getName();
	this->_grade = copy.getGrade();
	std::cout << YELLOW << "Copy assignment(operator=) called" << RESET << std::endl;
	return (*this);
};

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Destructor(time) Begins" << RESET << std::endl;
};
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------











//-----------------------------------------------------------------------
//getters and setters
//-----------------------------------------------------------------------

std::string	Bureaucrat::getName() const
{
	return (this->_name);
};

unsigned int	Bureaucrat::getGrade() const
{
	return (this->_grade);
};

void	Bureaucrat::setGrade(int value)
{
	this->_grade = value;
};


//increment && decrement
//-----------------------------------------------------------------------
void		Bureaucrat::incrementGrade()
{
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException("GRADE HIGH ENOUGH ALREADY!");
	this->_grade--;
};

void		Bureaucrat::decrementGrade()
{
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException("STOP~ HE SO Lowww ALREADY.");
	this->_grade++;
};
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

















//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& message) : _msg(message)
{
};

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& message) : _msg(message)
{
};
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------



















//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//what() implementation
const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return (this->_msg.c_str());
};

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return (this->_msg.c_str());
};

//Destructors happening here
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
	std::cout << RED << "Destructor for (GradeTooHigh)" << RESET << std::endl;
};

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
	std::cout << RED << "Destructor for (GradeTooLow)" << RESET << std::endl;
};
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

















//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const Bureaucrat& other)
{
	std::cout << other.getName() << ", bureaucrat grade " \
	<< other.getGrade() << "." << std::endl;
	// write obj to stream
	return (os);
};
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------






























