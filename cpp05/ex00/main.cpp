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
	std::cout << "Ex00" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	std::cout << GREEN << "--PERSONAL TEST CASE--" << RESET << std::endl;
	{
		try
		{
			Bureaucrat b(160, "failing dude");
		}
		catch (const std::exception & e)
		{
			std::cerr << "Custom Exception obtained: " << YELLOW \
				<< RED << e.what() << RESET << std::endl;
		}
	}















	std::cout << "-------------------------------" << std::endl;
	std::cout << "\n\n\n" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	std::cout << GREEN << "--PERSONAL TEST CASE 2--" << RESET << std::endl;
	{
		Bureaucrat *b = NULL;
		try
		{
			b = new Bureaucrat(160, "failing dude");
		}
		catch (const std::exception & e)
		{
			std::cerr << "std::exception obtained: " << YELLOW \
				<< RED << e.what() << RESET << std::endl;
		}
		if (b)
			delete b;
	}















	std::cout << "-------------------------------" << std::endl;
	std::cout << "\n\n\n\n\n" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	std::cout << GREEN << "--TEST CASE 1--" << RESET << std::endl;
	{
		Bureaucrat b;
		try
		{
			b = Bureaucrat(0, "failing dude");
		}
		catch (const std::exception & e)
		{
			std::cerr << "std::exception obtained: " << YELLOW \
				<< RED << e.what() << RESET << std::endl;
		}
	}
	
	{
		Bureaucrat b;
		try
		{
			b = Bureaucrat(160, "failing dude");
		}
		catch (const std::exception & e)
		{
			std::cerr << "std::exception obtained: " << YELLOW \
				<< RED << e.what() << RESET << std::endl;
		}
	}
	














	std::cout << "-------------------------------" << std::endl;
	std::cout << "\n\n\n\n\n" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	std::cout << GREEN << "--TEST CASE 2 (with pointers(and fail))--" << std::endl;
	{
		std::cout << BLUE << "Constructing" << RESET << std::endl;
		Bureaucrat *a = NULL;
		try
		{
			a = new Bureaucrat(160, "failing dude");
		}
		catch (const std::exception & e)
		{
			std::cerr << "std::exception obtained: " << YELLOW \
				<< RED << e.what() << RESET << std::endl;
		}
		std::cout << std::endl;
		if (a)
			delete a;
	}
	
	std::cout << GREEN << "\n\n--TEST CASE 2.5(part1)--" << std::endl;
	{
		std::cout << BLUE << "Constructing" << RESET << std::endl;
		Bureaucrat *b = new Bureaucrat(140, "passing dude");
		std::cout << YELLOW << "checking address: " << RESET << b << std::endl;
		try
		{
			b->incrementGrade();
		}
		catch (const std::exception & e)
		{
		 	std::cerr << "general issue found " << YELLOW
		 	<< RED << e.what() << RESET << std::endl;
		}
		if (b)
			delete b;
	}
	
	std::cout << GREEN << "\n\n--TEST CASE 2.5(part2)--" << std::endl;
	{
		std::cout << BLUE << "Constructing" << RESET << std::endl;
		Bureaucrat *a = new Bureaucrat(150);
		std::cout << std::endl;
		
		std::cout << BLUE << "Testing" << RESET << std::endl;
		std::cout << YELLOW << "checking address: " << RESET << a << std::endl;

		try
		{
			a->decrementGrade();
		}
		catch (const std::exception & e)
		{
		 	std::cerr << "general issue found " << YELLOW
		 	<< RED << e.what() << RESET << std::endl;
		}
		delete a;
	}
	
	std::cout << GREEN << "\n\n--TEST CASE 2.5(part3)--" << std::endl;
	{
		std::cout << BLUE << "Constructing" << RESET << std::endl;
		Bureaucrat *a = new Bureaucrat(1);
		std::cout << std::endl;
		
		std::cout << BLUE << "Testing" << RESET << std::endl;
		std::cout << YELLOW << "checking address: " << RESET << a << std::endl;

		try
		{
			a->incrementGrade();
		}
		catch (const std::exception & e)
		{
		 	std::cerr << "general issue found " << YELLOW
		 	<< RED << e.what() << RESET << std::endl;
		}
		delete a;
	}














	std::cout << "-------------------------------" << std::endl;
	std::cout << "\n\n\n\n\n" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	std::cout << GREEN << "--TEST CASE 3--" << RESET << std::endl;
	{
		std::cout << std::endl;
		std::cout << BLUE << "Constructing" << RESET << std::endl;
		Bureaucrat *a = new Bureaucrat(1);
		std::cout << std::endl;
		std::cout << BLUE << "Testing start" << RESET << std::endl;
		std::cout << "Address: " << BLUE << a << RESET \
			<< "\n\tValue = " << BLUE << *a << RESET << std::endl;

		try
		{
			a->decrementGrade();
		}
		catch (const std::exception & e)
		{
		 	std::cerr << "general issue found " << YELLOW
		 	<< RED << e.what() << RESET << std::endl;
		}

		std::cout << YELLOW << "Results after decrement->" << RESET << std::endl;
		std::cout << "Address: " << BLUE << a << RESET \
			<< "\n\tValue = " << BLUE << *a << RESET << std::endl;

		try
		{
			a->incrementGrade();
		}
		catch (const std::exception & e)
		{
		 	std::cerr << "general issue found " << YELLOW
		 	<< RED << e.what() << RESET << std::endl;
		}

		std::cout << YELLOW << "Results after increment->" << RESET << std::endl;
		std::cout << "Address: " << BLUE << a << RESET \
			<< "\n\tValue = " << BLUE << *a << RESET << std::endl;

		try
		{
			a->incrementGrade();
		}
		catch (const std::exception & e)
		{
		 	std::cerr << "general issue found " << YELLOW
		 	<< RED << e.what() << RESET << std::endl;
		}

		std::cout << YELLOW << "Results after increment->" << RESET << std::endl;
		std::cout << "Address: " << BLUE << a << RESET \
			<< "\n\tValue = " << BLUE << *a << RESET << std::endl;

		std::cout << a << std::endl;
		std::cout << BLUE << "Deconstructing" << RESET << std::endl;
		delete a;
	}
	














	std::cout << "-------------------------------" << std::endl;
	std::cout << "\n\n\n\n\n" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	std::cout << GREEN << "--TEST CASE 4--(start with \"0\")" << RESET << std::endl;
	{
		std::cout << std::endl;
		std::cout << BLUE << "Constructing" << RESET << std::endl;
		Bureaucrat *a = NULL;

		try
		{
			a = new Bureaucrat(0);
		}
		catch (const std::exception & e)
		{
		 	std::cerr << "general issue found " << YELLOW
		 	<< RED << e.what() << RESET << std::endl;
		}

		if (a != NULL)
		{
			std::cout << std::endl;

			std::cout  << BLUE << "Deconstructing b" << RESET << std::endl;
			delete a;
		}

	}
	














	std::cout << "-------------------------------" << std::endl;
	std::cout << "\n\n\n\n\n" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	std::cout << GREEN << "--TEST CASE 5--(start with \"160\")" << RESET << std::endl;
	{
		std::cout << std::endl;
		std::cout << BLUE << "Constructing" << RESET << std::endl;
		Bureaucrat *a = NULL;

		try
		{
			a = new Bureaucrat(160);
		}
		catch (const std::exception & e)
		{
		 	std::cerr << "general issue found " << YELLOW
		 	<< RED << e.what() << RESET << std::endl;
		}

		if (a != NULL)
		{
			std::cout << std::endl;
			std::cout  << BLUE << "Deconstructing b" << RESET << std::endl;
			delete a;
		}
	}
	














	std::cout << "-------------------------------" << std::endl;
	std::cout << "\n\n\n\n\n" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	return (0);
}
