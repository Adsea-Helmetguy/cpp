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

int	main()
{
	srand(time(0));
	std::cout << MAG << "\n\nFirst test commence!" << RESET << std::endl;
	{
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;

		//Check if form is signed and correct exec value to do function.
		//1) Shrubbery
		// -------------------------------------------------------
		Bureaucrat a1(137);
		ShrubberyCreationForm f1("Shrub1");
		std::cout << a1 << std::endl;
		std::cout << f1 << std::endl;

		a1.signForm(f1);
		f1.execute(a1);
		std::cout << YELLOW << "----------------------------\n\n" \
			<< RESET << std::endl;
		std::cout << "\n\n\n" << std::endl;
		// -------------------------------------------------------


		//2) Robotomy
		// -------------------------------------------------------
		Bureaucrat a2(44);
		RobotomyRequestForm f2("Robotomy1");
		std::cout << a2 << std::endl;
		std::cout << f2 << std::endl;
		a2.signForm(f2);
		f2.execute(a2);
		// -------------------------------------------------------


		//3) Presidental
		// -------------------------------------------------------
		Bureaucrat a3(44);
		PresidentalPardonForm f3("PresidentalPardon1");
		std::cout << a3 << std::endl;
		std::cout << f3 << std::endl;
		a3.signForm(f3);
		f3.execute(a3);
		// -------------------------------------------------------




		std::cout << YELLOW << "----------------------------\n\n" \
			<< RESET << std::endl;
	}
	return (0);
}

