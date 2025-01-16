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

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "\n\n" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	std::cout << GREEN << "--TEST CASE 1--" << RESET << std::endl;
	{
		try
		{
			throw Bureaucrat::GradeTooHighException("testing for high value");
		}
		catch (const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << "Custom Exception obtained: " << YELLOW \
			<< e.what() << RESET << std::endl;
		}
	}
	
	{
		try
		{
			throw Bureaucrat::GradeTooLowException("testing for low value");
		}
		catch (const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << "Custom Exception obtained: " << YELLOW \
			<< e.what() << RESET << std::endl;
		}
	}
	std::cout << "-------------------------------\n\n" << std::endl;








	std::cout << BLUE << "Constructing" << RESET << std::endl;
	Bureaucrat *a = new Bureaucrat();
	std::cout << std::endl;








	std::cout << "-------------------------------" << std::endl;
	std::cout << GREEN << "--TEST CASE 2--" << std::endl;
	{
		std::cout << BLUE << "Testing" << RESET << std::endl;
		std::cout << YELLOW << "checking address: " << RESET << a << std::endl;

		try
		{
			a->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << YELLOW << "Incrementing grade of " << a->getName() <<
			" failed: " << e.what() << RESET << std::endl;
		}
		catch(...)
		{
			std::cerr << "general issue found " << YELLOW \
			<< e.what() << RESET << std::endl;
		}
	}
	std::cout << "-------------------------------\n\n" << std::endl;
	std::cout << "\n\n" << std::endl;
	
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << GREEN << "--TEST CASE 3--" << RESET << std::endl;
	{
		std::cout << std::endl;
		std::cout << BLUE << "Constructing" << RESET << std::endl;
		Bureaucrat *a = new Bureaucrat(1);
		std::cout << std::endl;
		std::cout << BLUE << "Testing\033[0m" << RESET << std::endl;
		std::cout << a << std::endl;

		try
		{
			a->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << YELLOW << "Decrementing grade of " << a->getName() <<
			" failed: " << e.what() << RESET << std::endl;
		}

		std::cout << a << std::endl;

		try
		{
			a->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << YELLOW << "Incrementing grade of " << a->getName() <<
			" failed: " << e.what() << RESET << std::endl;
		}

		std::cout << a << std::endl;

		try
		{
			a->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << YELLOW << "Incrementing grade of " << a->getName() <<
			" failed: " << e.what() << RESET << std::endl;
		}

		std::cout << a << std::endl;
		std::cout << BLUE << "Deconstructing" << RESET << std::endl;
		delete a;
	}
	std::cout << "-------------------------------\n\n" << std::endl;
	std::cout << "\n\n" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << GREEN << "--TEST CASE 4--" << RESET << std::endl;
	{
		std::cout << std::endl;
		std::cout << BLUE << "Constructing" << RESET << std::endl;
		Bureaucrat *a = NULL;

		try
		{
			a = new Bureaucrat(0);
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr  << YELLOW << "Constructing default failed: " <<
			e.what() << RESET << std::endl;
		}

		if (a != NULL)
		{
			std::cout << std::endl;

			std::cout  << BLUE << "Deconstructing b" << RESET << std::endl;
			delete a;
		}

	}
	std::cout << "-------------------------------\n\n" << std::endl;
	std::cout << "\n\n" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << GREEN << "--TEST CASE 5--" << RESET << std::endl;
	{
		std::cout << std::endl;
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = NULL;

		try
		{
			a = new Bureaucrat(160);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr  << YELLOW << "Constructing default failed: " <<
			e.what() << RESET << std::endl;
		}

		if (a != NULL)
		{
			std::cout << std::endl;
			std::cout  << BLUE << "Deconstructing b" << RESET << std::endl;
			delete a;
		}
	}
	std::cout << "-------------------------------\n\n" << std::endl;
	std::cout << "\n\n" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
/*
	std::cout << GREEN << "--TEST CASE 6--" << RESET << std::endl;
	{
		std::cout << std::endl;
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Peter", 120);
		std::cout << std::endl;

		std::cout << "\033[34mTesting a\033[0m" << std::endl;
		std::cout << a;

		a->decrementGrade();

		std::cout << a;
		std::cout << std::endl;

		std::cout << "\033[34mConstructing b\033[0m" << std::endl;
		Bureaucrat *b = new Bureaucrat(*a);
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing a\033[0m" << std::endl;
		delete a;
		std::cout << std::endl;

		std::cout << "\033[34mTesting b\033[0m" << std::endl;
		std::cout << b;
		b->decrementGrade();
		std::cout << b;
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
		delete b;
	}
*/
	return (0);
}
