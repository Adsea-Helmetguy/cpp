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

#include "AForm.hpp"

//-----------------------------------------------------------------------
AForm::AForm(unsigned int required, unsigned int exec))
	: _name("Default Form Name"), _isTheFormSigned(false), _requiredGrades(70), _execGrades(40)
{
	
};

AForm::AForm(const std::string& name, unsigned int required, unsigned int exec)
	: _name(name), _isTheFormSigned(false), _requiredGrades(required), _execGrades(exec)
{
	
};

AForm::AForm(const AForm& copy)
	: _name(copy._name), _isTheFormSigned(copy._isTheFormSigned), 
	_requiredGrades(copy._requiredGrades), _execGrades(copy._execGrades)
{
	
};

AForm&	AForm::operator=(const AForm& copy)
{
	if (this != &copy)
	{
		//const _name, cannot be copied over
		this->_isTheFormSigned = copy.getBool();
		std::cout << YELLOW << "Copy assignment(operator=) called" << RESET << std::endl;
	}
	return (*this);
};

AForm::~AForm()
{
	std::cout << RED << "Destructor(form) Begins" << RESET << std::endl;
};
//-----------------------------------------------------------------------


//-----------------------------------------------------------------------
//Getters and setters----------------------------------------------------
const std::string	AForm::getName() const
{
	return (this->_name);
};

//     -------------others-------------
bool			AForm::getBool() const
{
	return (this->_isTheFormSigned);
};

unsigned int	AForm::getGradeToSign() const
{
	return (this->_requiredGrades);
};

unsigned int	AForm::getGradeToExecute() const
{
	return (this->_execGrades);
};
//     -------------others-------------

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------










//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
AForm::GradeTooHighException::GradeTooHighException(const std::string& message) : _msg(message)
{
};

AForm::GradeTooLowException::GradeTooLowException(const std::string& message) : _msg(message)
{
};

//what() implementation
const char*	AForm::GradeTooHighException::what() const throw()
{
	return (this->_msg.c_str());
};

const char*	AForm::GradeTooLowException::what() const throw()
{
	return (this->_msg.c_str());
};

AForm::GradeTooHighException::~GradeTooHighException() throw()
{
	std::cout << RED << "Destructor form (GradeTooHigh)" << RESET << std::endl;
};

AForm::GradeTooLowException::~GradeTooLowException() throw()
{
	std::cout << RED << "Destructor form (GradeTooLow)" << RESET << std::endl;
};
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------







//-----------------------------------------------------------------------
//signFroms--------------------------------------------------------------

void	AForm::besigned(const Bureaucrat& user)
{
	std::cout << YELLOW << "Checking if this form can be signed." \
		<< RESET << std::endl;
	if (user.getGrade() > this->_requiredGrades)
	{
		throw GradeTooLowException("Grade too low to sign, \"FAIL\".");
		return ;
	}
	std::cout << GREEN << "Congratz! You passed!" << RESET << std::endl;
		this->_isTheFormSigned = true;
/*
	if (this->_isTheFormSigned == false)
	{
		std::cout << YELLOW << user.getName() << " couldn’t sign " \
			<< this->_name << " because " << RED \
			<< GradeTooLowException("Score too low").what() \
			<< RESET << std::endl;
		return ;
	}
*/
};

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------








//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
std::ostream&	operator<<(std::ostream& os, const AForm& form)
{
	std::cout << "printing all form's information: " << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Form's _name: " << GREEN << form.getName() << RESET \
	<< std::endl;
	std::cout << "Form's _isTheFormSigned: " << GREEN << form.getBool() \
	<< RESET << std::endl;
	std::cout << "Form's _requiredGrades: " << GREEN << form.getGradeToSign() \
	<< RESET << std::endl;
	std::cout << "Form's _execGrades: " << GREEN << form.getGradeToExecute() \
		<< RESET << std::endl;
	std::cout << "----------------------------------" << std::endl;
	return (os);
};
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

