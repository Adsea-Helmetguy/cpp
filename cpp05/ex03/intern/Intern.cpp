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
#include "presidentialPardonForm/PresidentialPardonForm.hpp"

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
	return (new ShrubberyCreationForm(form_target));	
};

AForm*	Intern::Robotomy_requested(std::string form_target)
{
	return (new RobotomyRequestForm(form_target));
};

AForm*	Intern::Presidential_requested(std::string form_target)
{
	return (new PresidentialPardonForm(form_target));
};

//refer to notion about: "Pointers to member functions"
//https://en.cppreference.com/w/cpp/language/pointer
AForm*	Intern::makeForm(std::string form_name, std::string form_target)
{
	const std::string	form_array[] =
	{
		"shrubbery request", 
		"robotomy request", 
		"presidential request"
	};

	//requires exact function arguments and returns.
	//Cannot perform stuff like ++ or --. (increment or decrement).
	AForm*	(Intern::*form_name_array[])(const std::string) =
	{
		&Intern::Shrubbery_requested, 
		&Intern::Robotomy_requested, 
		&Intern::Presidential_requested
	};//these are all the address of the function

	for (int index = 0; index < 3; index++)
	{
		if (form_array[index] == form_name)
		{
			std::cout << GREEN <<  "Intern creates " << MAG \
				<< form_name << RESET << std::endl;
			return ((this->*form_name_array[index])(form_target));
		}	
	}
	// If no match is found
	std::cout << RED << "Check your naming again, can't find them" \
		<< RESET << std::endl;
	return (NULL);
};
//  -----------------------------------------------------------------

























