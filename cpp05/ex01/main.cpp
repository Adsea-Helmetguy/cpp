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

int	main()
{
	std::cout << MAG << "\n\nFirst test commence!" << RESET << std::endl;
	{
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
		try
		{
			throw Form::GradeTooHighException("testing for high value");
		}
		catch(const Form::GradeTooHighException& e)
		{
			std::cerr << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		std::cout << "*****   *****" << std::endl;
		try
		{
			throw Bureaucrat::GradeTooHighException("testing for high value");
		}
		catch(const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
	}

	std::cout << MAG << "\n\nSecond test commence!" << RESET << std::endl;
	{
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
		std::cout << GREEN << "Constructing new Bureaucrat" << RESET << std::endl;
		Bureaucrat *a1 = new Bureaucrat(40, "Billy");
		Bureaucrat *a2 = new Bureaucrat(50, "Keith");
		Bureaucrat *a3 = new Bureaucrat(99, "Jim boy");
		Form *f1 = new Form();
		Form f2;
		f2.signForm(*a3);
		try
		{
			//get several bureaucrats to sign form
			f1->besigned(*a1);
			f1->besigned(*a2);
			f1->besigned(*a3);
		}
		catch(const Form::GradeTooHighException& e)
		{
			std::cerr << RED << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		catch(const Form::GradeTooLowException& e)
		{
			std::cerr << RED << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		f1->signForm(*a1);
		f1->signForm(*a2);
		f1->signForm(*a3);
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
	}
/*
	std::cout << MAG << "\n\nThird test commence!" << RESET << std::endl;
	{
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
		try
		{
			throw Form::GradeTooHighException("testing for high value");
		}
		catch(const Form::GradeTooHighException& e)
		{
			std::cerr << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		std::cout << "*****   *****" << std::endl;
		try
		{
			throw Form::GradeTooHighException("testing for high value");
		}
		catch(const Form::GradeTooHighException& e)
		{
			std::cerr << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
	}
*/
	std::cout << "\n" << std::endl;
	return (0);
}

