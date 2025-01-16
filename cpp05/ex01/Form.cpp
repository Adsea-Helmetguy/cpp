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

#include "Form.hpp"

//-----------------------------------------------------------------------
Form::Form()
	: _name("Default Form Name"), _isTheFormSigned(false), _gradeToSign(70), _gradeToExecute(40)
{
	
};

Form::Form(const std::string& name)
	: _name(name), _isTheFormSigned(false), _gradeToSign(70), _gradeToExecute(40)
{
	
};

Form::Form(const Form& copy)
	: _name(copy._name), _isTheFormSigned(copy._isTheFormSigned), 
	_gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	
};

Form&	Form::operator=(const Form& copy)
{
	if (this != &copy)
	{
		//const _name cannot be copied over
		this->_getBool;
		std::cout << YELLOW << "Copy assignment(operator=) called" << RESET << std::endl;
	}
	return (*this);
};

Form::~Form()
{
	std::cout << RED << "Destructor(time) Begins" << RESET << std::endl;
};
//-----------------------------------------------------------------------


//-----------------------------------------------------------------------
//Getters and setters----------------------------------------------------
const std::string	Form::getName()
{
	return (this->_name);
};


//     -------------others-------------
const std::string	Form::getBool()
{
	return (this->_isTheFormSigned);
};

const std::string	Form::getGradeToSign()
{
	return (this->_gradeToSign);
};

const std::string	Form::getGradeToExecute()
{
	return (this->_gradeToExecute);
};
//     -------------others-------------

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------










//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
Form::GradeTooHighException::GradeTooHighException(const std::string& message) : _msg(message)
{
};

Form::GradeTooLowException::GradeTooLowException(const std::string& message) : _msg(message)
{
};

//what() implementation
const char*	Form::GradeTooHighException::what() const throw()
{
	return (this->_msg.c_str());
};

const char*	Form::GradeTooLowException::what() const throw()
{
	return (this->_msg.c_str());
};
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------







//-----------------------------------------------------------------------
//signFroms--------------------------------------------------------------

void	Form::besigned(const Bureaucrat& user)
{
	std::cout << YELLOW << "Checking if this form can be signed." \
		<< RESET << std::endl
	if (user->_grade > this->_gradeToSign)
	{
		throw GradeTooLowException("Grade too low to sign, \"FAIL\".");
		return ;
	}
	std::cout << GREEN << "Congratz! You passed!" << RESET << std::endl;
	this->_isTheFormSigned(true);
	return (*this);
};

void	Form::signForm(const Bureaucrat& user)
{
	if (this->_isTheFormSigned == false)
	{
		std::cout << YELLOW << user->_name << " couldn’t sign " \
			<< this->_name << " because " << RED \
			<< user._msg << RESET << std::endl;
		return ;
	}
	std::cout << user->_name << " signed " \
			<< this->_name << RESET << std::endl;
};

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------








//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
std::ostream&	operator<<(std::ostream& os, const Form& form)
{
	std::cout << "printing all form's information: " << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Form's _name: " << GREEN << form.getName() << RESET \
	<< std::endl;
	std::cout << "Form's _isTheFormSigned: " << GREEN << form.getBool() \
	<< RESET << std::endl;
	std::cout << "Form's _gradeToSign: " << GREEN << form.getGradeToSign() \
	<< RESET << std::endl;
	std::cout << "Form's _gradeToExecute: " << GREEN << form.getGradeToExecute() \
		<< RESET << std::endl;
	std::cout << "----------------------------------" << std::endl;
	return (os);
};
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

