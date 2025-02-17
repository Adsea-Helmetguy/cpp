/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:34:13 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:34:18 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm_bureaucrat/AForm.hpp"
#include "shrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "robotomyRequestForm/RobotomyRequestForm.hpp"
#include "presidentalPardonForm/PresidentalPardonForm.hpp"
#include "intern/Intern.hpp"

int	main()
{
	std::cout << MAG << "\n\n\nTEST 1" << RESET << std::endl;
	{
		Intern	someRandomIntern;
		AForm*	rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bob");
		std::cout << *rrf << std::endl;
		delete rrf;
		std::cout << "---------------------------------" << std::endl;
	}

	std::cout << MAG << "\n\n\nTEST 2" << RESET << std::endl;
	{
		Intern	someRandomIntern;
		AForm*	rrf;

		rrf = someRandomIntern.makeForm("shrubbery request", "Dwayn");
		std::cout << *rrf << std::endl;
		delete rrf;
		std::cout << "---------------------------------" << std::endl;
	}
	
	std::cout << MAG << "\n\n\nTEST 3" << RESET << std::endl;
	{
		Intern	someRandomIntern;
		AForm*	rrf;

		rrf = someRandomIntern.makeForm("presidental request", "Damn");
		std::cout << *rrf << std::endl;
		delete rrf;
		std::cout << "---------------------------------" << std::endl;
	}
	return (0);
}

