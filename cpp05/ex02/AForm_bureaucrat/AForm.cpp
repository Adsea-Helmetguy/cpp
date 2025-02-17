/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:34:28 by mlow              #+#    #+#             */
/*   Updated: 2025/02/14 15:30:16 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//-----------------------------------------------------------------------
AForm::AForm(unsigned int required, unsigned int exec)
	: _name("Default Form Name"), _isTheFormSigned(false), _requiredGrades(required), _execGrades(exec)
{
	std::cout << "AForm Created: " << GREEN << this->_name << RESET << std::endl;
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
	else
		std::cout << "DON'T DO ZAT! Don't self-assign!!!" << std::endl;
	return (*this);
};

AForm::~AForm()
{
	std::cout << RED << "AForm_Destructor: \"" << YELLOW \
		<< this->_name << RED << "\" done" << RESET << std::endl;
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

void			AForm::setBool(bool value)
{
	this->_isTheFormSigned = value;
};

unsigned int	AForm::getrequiredGrades() const
{
	return (this->_requiredGrades);
};

unsigned int	AForm::getexecGrades() const
{
	return (this->_execGrades);
};
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------










//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//what() implementation
const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too High, FAIL.");
};

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low, FAIL.");
};
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------







//-----------------------------------------------------------------------
//signFroms--------------------------------------------------------------

void	AForm::besigned(const Bureaucrat& user)
{
	std::cout << YELLOW << "Checking if this form can be signed." \
		<< RESET << std::endl;
	std::cout << "User grade: " << user.getGrade() << std::endl;
	std::cout << "RequiredGrades to sign: " << this->_requiredGrades << std::endl;
	if (user.getGrade() > this->_requiredGrades)
		throw GradeTooLowException();
	std::cout << GREEN << "Congratz! You passed!" << RESET << std::endl;
		this->_isTheFormSigned = true;
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
	if (form.getBool() == 0)
		std::cout << "Form's _isTheFormSigned: " << RED << "\"Not Signed\"" \
	    	<< RESET << std::endl;
	else
		std::cout << "Form's _isTheFormSigned: " << GREEN << "\"Signed\"" \
			<< RESET << std::endl;
	std::cout << "Form's _requiredGrades: " << GREEN << form.getrequiredGrades() \
	<< RESET << std::endl;
	std::cout << "Form's _execGrades: " << GREEN << form.getexecGrades() \
		<< RESET << std::endl;
	std::cout << "----------------------------------" << std::endl;
	return (os);
};
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

