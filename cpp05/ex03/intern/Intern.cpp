/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:34:28 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:34:30 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "form/Form.hpp"
#include "AForm_bureaucrat/AForm.hpp"
#include "shrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "robotomyRequestForm/RobotomyRequestForm.hpp"
#include "presidentalPardonForm/PresidentalPardonForm.hpp"

Intern::Intern()
{

};

Intern::Intern(const Intern& copy)
{
	(void)copy;
};

Intern&	Intern::operator=(const Intern& copy)
{
	if (this != &copy)
		std::cout << YELLOW << "Copy assignment(operator=) called" << RESET << std::endl;
	else
		std::cout << YELLOW << "DON'T DO ZAT! Don't self-assign!!!" << RESET << std::endl;
	(void)copy;
	return (*this);
};

Intern::~Intern()
{
	std::cout << RED << "Destructor called for Intern" << RESET << std::endl;
};






//  ---------Intern Form Creation------------------------------------

AForm*	Intern::Shrubbery_requested(std::string form_target)
{
	AForm*	f1 = new ShrubberyCreationForm(form_target);

	return (f1);
};

AForm*	Intern::Robotomy_requested(std::string form_target)
{
	return (new RobotomyRequestForm(form_target));
};

AForm*	Intern::Presidental_requested(std::string form_target)
{
	return (new PresidentalPardonForm(form_target));
};

//  -----------------------------------------------------------------















AForm*	Intern::makeForm(std::string form_name, std::string form_target)
{
	
	AForm*	newForm;

	if (form_name == "shrubbery request")
	{
		newForm = Shrubbery_requested(form_target);
	}
	else if (form_name == "robotomy request")
	{
		newForm = Robotomy_requested(form_target);
	}
	else if(form_name == "presidental request")
	{
		newForm = Presidental_requested(form_target);
	}
	else
	{
		std::cout << RED << "Check your naming again, can't find them" \
			<< RESET << std::endl;
		return (NULL);
	};

	std::cout << GREEN <<  "Intern creates " << MAG \
		<< newForm->getName() << RESET << std::endl;
	return (newForm);
};














/*
//  -----------------------------------------------------------------
//  -----------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const AForm& form)
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
//  -----------------------------------------------------------------
//  -----------------------------------------------------------------
*/























