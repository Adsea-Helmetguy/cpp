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
		Bureaucrat a1;
		std::cout << a1 << std::endl;
		try
		{
			a1 = Bureaucrat(150, "Bureaucrat_shawn2");
			a1.incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << YELLOW << "GradeTooHighException: " << a1.getName() <<
			" failed: " << RED << e.what() << RESET << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << YELLOW << "GradeTooLowException: " << a1.getName() <<
			" failed: " << RED << e.what() << RESET << std::endl;
		}
		catch (const std::exception & e)
		{
		 	std::cerr << "general issue found " << YELLOW
		 	<< RED << e.what() << RESET << std::endl;
		}

		ShrubberyCreationForm f1("Shrub1");
		std::cout << a1 << std::endl;
		try
		{
			a1.signAForm(f1);
			a1.executeAForm(f1);
		}
		/*
		catch(const AForm::GradeTooHighException& e)
		{
			std::cerr << RED << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		catch(const AForm::GradeTooLowException& e)
		{
			std::cerr << RED << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		*/
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
	}
	return (0);
}
/*
try
		{
			a2 = new Bureaucrat(152, "Bureaucrat_shawn2");
		}
		catch (const std::exception & e)
		{
			std::cerr << "Custom Exception obtained: " << YELLOW \
				<< RED << e.what() << RESET << std::endl;
		}
*/
//
//
/*
	std::cout << MAG << "\n\nFirst test commence!" << RESET << std::endl;
	{
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;

		//--Check if form is signed and correct exec value to do function.--
		//1) Shrubbery
		// -------------------------------------------------------
		Bureaucrat a1(25);
		ShrubberyCreationForm f1("Shrub1");
		std::cout << a1 << std::endl;
		try
		{
			a1.signAForm(f1);
			a1.executeAForm(f1);
		}
		catch(const AForm::GradeTooHighException& e)
		{
			std::cerr << RED << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		catch(const AForm::GradeTooLowException& e)
		{
			std::cerr << RED << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
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
		Bureaucrat a2(149);
		RobotomyRequestForm f2("Robotomy1");
		std::cout << a2 << std::endl;
		try
		{
			a2.signAForm(f2);
			a2.executeAForm(f2);
		}
		catch(const AForm::GradeTooHighException& e)
		{
			std::cerr << RED << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		catch(const AForm::GradeTooLowException& e)
		{
			std::cerr << RED << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		catch(const std::exception & e)//hang on, the std::exception doesnt catch all?
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
			a3.signAForm(f3);
			a3.executeAForm(f3);
		}
		catch(const AForm::GradeTooHighException& e)
		{
			std::cerr << RED << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		catch(const AForm::GradeTooLowException& e)
		{
			std::cerr << RED << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		catch(const std::exception & e)
		{
			std::cerr << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		f3.execute(a3);
		std::cout << f3 << std::endl;
		std::cout << "\n\n" << std::endl;
		// -------------------------------------------------------
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
	}















	std::cout << MAG << "\n\n\n\n\n\n\n\n\n\n\n\n\n\nSecond test commence!" \
		<< RESET << std::endl;
	{
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;

		//1) Shrubbery
		// -------------------------------------------------------
		Bureaucrat a1(137, "Bureaucrat_shawn");
		ShrubberyCreationForm f1("Shrub2");
		std::cout << a1 << std::endl;
		try
		{
			a1.signAForm(f1);
			a1.executeAForm(f1);
		}
		catch(const AForm::GradeTooHighException& e)
		{
			std::cerr << RED << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		catch(const AForm::GradeTooLowException& e)
		{
			std::cerr << RED << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
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
		Bureaucrat a2(33, "Bureaucrat_shawn2");
		RobotomyRequestForm f2("Robotomy2");
		std::cout << a2 << std::endl;
		try
		{
			a2.signAForm(f2);
			a2.executeAForm(f2);
		}
		catch(const AForm::GradeTooHighException& e)
		{
			std::cerr << RED << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		catch(const AForm::GradeTooLowException& e)
		{
			std::cerr << RED << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
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
		Bureaucrat a3(3, "Bureaucrat_shawn3");
		PresidentalPardonForm f3("PresidentalPardon2");
		std::cout << a3 << std::endl;
		try
		{
			a3.signAForm(f3);
			a3.executeAForm(f3);
		}
		catch(const AForm::GradeTooHighException& e)
		{
			std::cerr << RED << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		catch(const AForm::GradeTooLowException& e)
		{
			std::cerr << RED << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		catch(const std::exception & e)
		{
			std::cerr << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		f3.execute(a3);
		std::cout << f3 << std::endl;
		std::cout << "\n\n" << std::endl;
		// -------------------------------------------------------
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
	}
	
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
	std::cout << MAG << "Third all fail test commence!" \
		<< RESET << std::endl;
	{
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;

		//1) Shrubbery
		// -------------------------------------------------------
		Bureaucrat a1(150, "Bureaucrat_shawn");
		ShrubberyCreationForm f1("Shrub2");
		std::cout << a1 << std::endl;
		try
		{
			a1.signAForm(f1);
			a1.executeAForm(f1);
		}
		catch(const AForm::GradeTooHighException& e)
		{
			std::cerr << RED << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		catch(const AForm::GradeTooLowException& e)
		{
			std::cerr << RED << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
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

		Bureaucrat a2(149, "Bureaucrat_shawn2");
		RobotomyRequestForm f2("Robotomy2");
		std::cout << a2 << std::endl;
		try
		{
			a2.signAForm(f2);
			a2.executeAForm(f2);
		}
		catch(const AForm::GradeTooHighException& e)
		{
			std::cerr << RED << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		catch(const AForm::GradeTooLowException& e)
		{
			std::cerr << RED << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
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
		Bureaucrat a3(150, "Bureaucrat_shawn3");
		PresidentalPardonForm f3("PresidentalPardon2");
		std::cout << a3 << std::endl;
		try
		{
			a3.signAForm(f3);
			a3.executeAForm(f3);
		}
		catch(const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << RED << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		catch(const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << RED << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		catch(const AForm::GradeTooHighException& e)
		{
			std::cerr << RED << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		catch(const AForm::GradeTooLowException& e)
		{
			std::cerr << RED << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		catch(const std::exception & e)
		{
			std::cerr << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		f3.execute(a3);
		std::cout << f3 << std::endl;
		std::cout << "\n\n" << std::endl;
		// -------------------------------------------------------
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
	}
*/

