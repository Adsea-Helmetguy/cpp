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
	{
		std::cout << BLUE << "Constructing" << RESET << std::endl;
		Bureaucrat *a = new Bureaucrat();
		std::cout << std::endl;

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
			std::cerr << "General Exception happened" << std::endl;
		}

		std::cout << RED << "Deconstructing " << RESET << std::endl;
		delete a;
		std::cout << std::endl;
	}
/*
		//--------------------------------------------------------
		//--------------------------------------------------------
		//--------------------------------------------------------
		//std::cout << a;
		//
		try
		{
			a->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << YELLOW << "Decrementing grade of " << a->getName() <<
			" failed: " << e.what() << RESET << std::endl;
		}
		//--------------------------------------------------------
		std::cout << YELLOW << "checking address: " << RESET << a << std::endl;
		//
		try
		{
			a->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << YELLOW << "Decrementing grade of " << a->getName() <<
			" failed: " << e.what() << RESET << std::endl;
		}
		//--------------------------------------------------------
		std::cout << YELLOW << "checking address: " << RESET << a << std::endl;
		//
		std::cout << std::endl;
		//--------------------------------------------------------
		//--------------------------------------------------------
		//--------------------------------------------------------
		
		
		
		
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat(1);
		std::cout << std::endl;
		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;

		try
		{
		a->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33mDecrementing grade of " << a->getName() <<
			" failed: " << e.what() << "\033[0m" << std::endl;
		}

		std::cout << a;

		try
		{
		a->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "\033[33mIncrementing grade of " << a->getName() <<
			" failed: " << e.what() << "\033[0m" << std::endl;
		}

		std::cout << a;

		try
		{
		a->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "\033[33mIncrementing grade of " << a->getName() <<
			" failed: " << e.what() << "\033[0m" << std::endl;
		}

		std::cout << a;
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = NULL;

		try
		{
			a = new Bureaucrat(0);
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "\033[33mConstructing default failed: " <<
			e.what() << "\033[0m" << std::endl;
		}

		if (a != NULL)
		{
			std::cout << std::endl;

			std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
			delete a;
		}

		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
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
			std::cerr << "\033[33mConstructing default failed: " <<
			e.what() << "\033[0m" << std::endl;
		}

		if (a != NULL)
		{
			std::cout << std::endl;
			std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
			delete a;
		}
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
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

		std::cout << std::endl;
	}
	*/
	return (0);
}
