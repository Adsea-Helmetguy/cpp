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

		//--Check if form is signed and correct exec value to do function.--
		//1) Shrubbery
		// -------------------------------------------------------
		Bureaucrat a1(137);
		ShrubberyCreationForm f1("Shrub1");
		std::cout << a1 << std::endl;
		try
		{
			a1.signForm(f1);
			a1.executeForm(f1);
		}
		catch(const std::exception & e)//yes u can make more than 1 catch
		{
			std::cerr << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		f1.execute(a1);
		std::cout << YELLOW << "----------------------------\n\n" \
			<< RESET << std::endl;
		std::cout << f1 << std::endl;
		std::cout << "\n\n\n\n\n\n\n\n\n" << std::endl;
		// -------------------------------------------------------


		//2) Robotomy
		// -------------------------------------------------------
		Bureaucrat a2(33);
		RobotomyRequestForm f2("Robotomy1");
		std::cout << a2 << std::endl;
		try
		{
			a2.signForm(f2);
			a2.executeForm(f2);
		}
		catch(const std::exception & e)
		{
			std::cerr << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		f2.execute(a2);
		std::cout << f2 << std::endl;
		std::cout << "\n\n\n\n\n\n\n\n\n" << std::endl;
		// -------------------------------------------------------


		//3) Presidental
		// -------------------------------------------------------
		Bureaucrat a3(25);
		PresidentalPardonForm f3("PresidentalPardon1");
		std::cout << a3 << std::endl;
		try
		{
			a3.signForm(f3);
			a3.executeForm(f3);
		}
		catch(const std::exception & e)
		{
			std::cerr << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		f3.execute(a3);
		std::cout << f3 << std::endl;
		std::cout << "\n\n\n\n\n\n\n\n\n" << std::endl;
		// -------------------------------------------------------
		std::cout << YELLOW << "----------------------------\n\n" \
			<< RESET << std::endl;
	}
	return (0);
}

