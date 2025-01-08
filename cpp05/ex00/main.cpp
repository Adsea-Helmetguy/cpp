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
		std::cout << "test\n" << std::endl;
		try
		{
			foo();
		}
		catch (const Exception& e)
		{
			std::cerr << "MyException: " << e.what() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << "std::exception: " << e.what() << std::endl;
		}
	}

	{
		try
		{
			Bureaucrat b("Alice");
			b.incrementGrade();
			b.decrementGrade();
		}
		catch (const Bureaucrat::Exception& e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
	
	std::cout << "personal test!\n" << std:endl;
	{
		try
		{
			Bureaucrat bob("Bob", 151); // Invalid grade, too low
		}
		catch (const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		
		try
		{
			Bureaucrat alice("Alice", 1);
			alice.incrementGrade(); // Invalid grade, too high
		}
		catch (const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}

		try
		{
			Bureaucrat charlie("Charlie", 150);
			charlie.decrementGrade(); // Invalid grade, too low
		}
		catch (const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	return (0);
}
/*
The thrown exceptions must be catchable using try and catch blocks:

	try
	{
		// do some stuff with bureaucrats
	}
	catch (std::exception & e)
	{
		// handle exception
	}

You will implement an overload of the insertion («) operator to print something like
(without the angle brackets):

	<name>, bureaucrat grade <grade>.
*/
