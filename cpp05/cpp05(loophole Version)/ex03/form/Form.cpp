/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
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
		//const _name, cannot be copied over
		this->_isTheFormSigned = copy.getBool();
		std::cout << YELLOW << "Copy assignment(operator=) called" << RESET << std::endl;
	}
	return (*this);
};

Form::~Form()
{
	std::cout << RED << "Form_Destructor: \"" << YELLOW \
		<< this->_name << RED << "\" done" << RESET << std::endl;
};
//-----------------------------------------------------------------------


//-----------------------------------------------------------------------
//Getters and setters----------------------------------------------------
const std::string	Form::getName() const
{
	return (this->_name);
};

//     -------------others-------------
bool			Form::getBool() const
{
	return (this->_isTheFormSigned);
};

unsigned int	Form::getGradeToSign() const
{
	return (this->_gradeToSign);
};

unsigned int	Form::getGradeToExecute() const
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

Form::GradeTooHighException::~GradeTooHighException() throw()
{
	std::cout << RED << "Destructor for (" << YELLOW << "Form::" << RESET \
		<< RED << "GradeTooHighException)" << RESET << std::endl;
};

Form::GradeTooLowException::~GradeTooLowException() throw()
{
	std::cout << RED << "Destructor for (" << YELLOW << "Form::" << RESET \
		<< RED << "GradeTooLowException)" << RESET << std::endl;
};
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------







//-----------------------------------------------------------------------
//signFroms--------------------------------------------------------------

void	Form::besigned(const Bureaucrat& user)
{
	std::cout << YELLOW << "Checking if this form can be signed." \
		<< RESET << std::endl;
	if (user.getGrade() > this->_gradeToSign)
	{
		throw GradeTooLowException("Grade too low to sign, \"FAIL\".");
		return ;
	}
	std::cout << GREEN << "Congratz! You passed!" << RESET << std::endl;
		this->_isTheFormSigned = true;
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

