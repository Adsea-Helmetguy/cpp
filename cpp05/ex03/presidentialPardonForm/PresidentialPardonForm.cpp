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

#include "PresidentialPardonForm.hpp"

//-----------------------------------------------------------------------
PresidentialPardonForm::PresidentialPardonForm() : AForm(25, 5)
{
	
};

PresidentialPardonForm::PresidentialPardonForm(const std::string& name) : AForm(name, 25, 5)
{
	
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy)
{
	
};

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& form)
{
	if (this != &form)
	{
		//const _name, cannot be copied over
		this->setBool(form.getBool());
		std::cout << YELLOW << "RobotomyRequestForm Copy assignment(operator=) called" \
            << RESET << std::endl;
	}
    else
		std::cout << "DON'T DO ZAT! Don't self-assign!!!" << std::endl;
	return (*this);
};

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "Destructor(PresidentialPardonForm) Begins" << RESET << std::endl;
};
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------



void	PresidentialPardonForm::execute(Bureaucrat const & executor)
{
	//Informs that <target> has been pardoned by Zaphod Beeblebrox
	std::cout << YELLOW << "The target: \"" << GREEN << executor.getName() \
		<< YELLOW << "\" has been pardoned by Zaphod Beeblebrox." \
		<< RESET << std::endl;
};




//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
std::ostream&	operator<<(std::ostream& os, const PresidentialPardonForm& form)
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

