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

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm(72, 45)
{

};

RobotomyRequestForm::RobotomyRequestForm(const std::string& name) : AForm(name, 72, 45)
{

};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy)
{

};

RobotomyRequestForm&    RobotomyRequestForm::operator=(const RobotomyRequestForm& form)
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

RobotomyRequestForm::~RobotomyRequestForm()
{

};




void	RobotomyRequestForm::execute(Bureaucrat const & executor)
{
    if (executor.getGrade() > 45 || this->getBool() != true)
    {
		std::cout << "Sad but i won't let you execute order 66 for Robotomy dumbass" \
			<< std::endl;
	   	std::cout << RED << executor.getName() << " failed to executeform: " \
			<< this->getName() << RESET << std::endl;
		return ;
    }
    std::cout << MAG << "*DRILL CLANK CLANK DRILL*" << RESET << std::endl;
    //to do 50% chance of robot:
    //https://cplusplus.com/forum/beginner/79626/
    //https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/ ---this is for
    // why rand() gives the same value again and again
    std::string    race;
    int    random_number;

    //srand(time(0));
    random_number = rand();//you will need
    std::cout << YELLOW << "value of random_number: " << random_number % 2 \
    	<< RESET << std::endl;
    if ((random_number % 2) == 0)
    {
        std::cout << YELLOW << "Unforunate, the robotomy failed, Race is set to \"Human\"." \
            << RESET << std::endl;
        race = "Human";
    }
    else
    {
        std::cout << GREEN << "Yey! You now is Robo, Race is set to \"Robot\"." \
            << RESET << std::endl;
        race = "Robot";
    }
};

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
std::ostream&	operator<<(std::ostream& os, const RobotomyRequestForm& form)
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
