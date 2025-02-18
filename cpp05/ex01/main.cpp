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

#include "Form.hpp"

// _gradeToSign(70), _gradeToExecute(40)
int	main()
{
	std::cout << " \n\n_gradeToSign(70), _gradeToExecute(40)" << std::endl;
	std::cout << MAG << "First test commence!(failing at third)" << RESET << std::endl;
	{
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
//------------------------------------------------------------------
		Bureaucrat *a1;// = new Bureaucrat(40, "Billy");
		std::cout << GREEN << "Constructing new Bureaucrat a1" << RESET << std::endl;
		try
		{
			a1 = new Bureaucrat(40, "Billy");
			a1->incrementGrade();
		}
		catch (const std::exception & e)
		{
		 	std::cerr << "general issue found " << YELLOW \
		 		<< RED << e.what() << RESET << std::endl;
		}

		Bureaucrat *a2;
		try
		{
			a2 = new Bureaucrat(1, "Keith");
			a2->incrementGrade();
		}
		catch (const std::exception & e)
		{
		 	std::cerr << "general issue found " << YELLOW \
		 		<< RED << e.what() << RESET << std::endl;
		}
		
		Bureaucrat *a3;
		try
		{
			a3 = new Bureaucrat(99, "Jim boy");
			a3->incrementGrade();
		}
		catch (const std::exception & e)
		{
		 	std::cerr << "general issue found " << YELLOW \
		 		<< RED << e.what() << RESET << std::endl;
		}
//------------------------------------------------------------------

		Form f2("f2");
		try
		{
			a1->signForm(f2);
		}
		catch (const std::exception & e)
		{
		 	std::cerr << RED << a1->getName() << MAG << " couldn’t sign " \
		 		<< YELLOW << f2.getName() << MAG << " because " \
				<< RED << e.what() << RESET << std::endl;
		}
		
		try
		{
			a2->signForm(f2);
		}
		catch (const std::exception & e)
		{
		 	std::cerr << RED << a2->getName() << MAG << " couldn’t sign " \
		 		<< YELLOW << f2.getName() << MAG << " because " \
				<< RED << e.what() << RESET << std::endl;
		}
		
		try
		{
			a3->signForm(f2);
		}
		catch (const std::exception & e)
		{
		 	std::cerr << RED << a3->getName() << MAG << " couldn’t sign " \
		 		<< YELLOW << f2.getName() << MAG << " because " \
				<< RED << e.what() << RESET << std::endl;
		}
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
		std::cout << GREEN << "Destructors here." << RESET << std::endl;
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
		if (a1)
			delete a1;
		if (a2)
			delete a2;
		if (a3)
			delete a3;
	}
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n" << std::endl;

















	std::cout << MAG << "2nd test commence!(failing second sign)" << RESET << std::endl;
	{
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
//------------------------------------------------------------------
		Bureaucrat *a1;// = new Bureaucrat(40, "Billy");
		std::cout << GREEN << "Constructing new Bureaucrat a1" << RESET << std::endl;
		try
		{
			a1 = new Bureaucrat(40, "Billy");
			a1->incrementGrade();
		}
		catch (const std::exception & e)
		{
		 	std::cerr << "general issue found " << YELLOW \
		 		<< RED << e.what() << RESET << std::endl;
		}

		Bureaucrat *a2;
		try
		{
			a2 = new Bureaucrat(99, "Keith");
			a2->incrementGrade();
		}
		catch (const std::exception & e)
		{
		 	std::cerr << "general issue found " << YELLOW \
		 		<< RED << e.what() << RESET << std::endl;
		}
		
		Bureaucrat *a3;
		try
		{
			a3 = new Bureaucrat(40, "Jim boy");
			a3->incrementGrade();
		}
		catch (const std::exception & e)
		{
		 	std::cerr << "general issue found " << YELLOW \
		 		<< RED << e.what() << RESET << std::endl;
		}
//------------------------------------------------------------------

		Form f2;
		try
		{
			a1->signForm(f2);
		}
		catch (const std::exception & e)
		{
		 	std::cerr << RED << a1->getName() << MAG << " couldn’t sign " \
		 		<< YELLOW << f2.getName() << MAG << " because " \
				<< RED << e.what() << RESET << std::endl;
		}
		
		try
		{
			a2->signForm(f2);
		}
		catch (const std::exception & e)
		{
		 	std::cerr << RED << a2->getName() << MAG << " couldn’t sign " \
		 		<< YELLOW << f2.getName() << MAG << " because " \
				<< RED << e.what() << RESET << std::endl;
		}
		
		try
		{
			a3->signForm(f2);
		}
		catch (const std::exception & e)
		{
		 	std::cerr << RED << a3->getName() << MAG << " couldn’t sign " \
		 		<< YELLOW << f2.getName() << MAG << " because " \
				<< RED << e.what() << RESET << std::endl;
		}
		
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
		std::cout << GREEN << "Destructors here." << RESET << std::endl;
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
		if (a1)
			delete a1;
		if (a2)
			delete a2;
		if (a3)
			delete a3;
	}
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n" << std::endl;




























	std::cout << MAG << "\n\nthird test commence!(supposed to fail)" << RESET << std::endl;
	{
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
		std::cout << GREEN << "Constructing new Bureaucrat" << RESET << std::endl;
		Bureaucrat a1(149, "Billy");
		Form f2;
		try
		{
			a1.signForm(f2);
		}
		catch (const std::exception & e)
		{
		 	std::cerr << RED << a1.getName() << MAG << " couldn’t sign " \
		 		<< YELLOW << f2.getName() << MAG << " because " \
				<< RED << e.what() << RESET << std::endl;
		}

		Bureaucrat a2(149, "Keith");
		try
		{
			a2.signForm(f2);
		}
		catch (const std::exception & e)
		{
		 	std::cerr << RED << a2.getName() << MAG << " couldn’t sign " \
		 		<< YELLOW << f2.getName() << MAG << " because " \
				<< RED << e.what() << RESET << std::endl;
		}

		Bureaucrat a3(149, "Jim boy");
		try
		{
			a3.signForm(f2);
		}
		catch (const std::exception & e)
		{
		 	std::cerr << RED << a3.getName() << MAG << " couldn’t sign " \
		 		<< YELLOW << f2.getName() << MAG << " because " \
				<< RED << e.what() << RESET << std::endl;
		}
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
		std::cout << GREEN << "Destructors here." << RESET << std::endl;
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
	}
	std::cout << "\n" << std::endl;
	return (0);
}

