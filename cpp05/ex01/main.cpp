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
	std::cout << MAG << "First test commence!" << RESET << std::endl;
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
		catch (const std::exception & e)
		{
		 	std::cerr << "First test found: " << YELLOW
		 	<< RED << e.what() << RESET << std::endl;
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
		catch (const std::exception & e)
		{
		 	std::cerr << "First test found: " << YELLOW
		 	<< RED << e.what() << RESET << std::endl;
		}
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
	}

	std::cout << MAG << "\n\n2nd test commence!" << RESET << std::endl;
	{
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
		std::cout << GREEN << "Constructing new Bureaucrat" << RESET << std::endl;
		Bureaucrat *a1 = new Bureaucrat(40, "Billy");
		Bureaucrat *a2 = new Bureaucrat(50, "Keith");
		Bureaucrat *a3 = new Bureaucrat(99, "Jim boy");
		Form f2;

		try
		{
			a1->signForm(f2);
			a2->signForm(f2);
			a3->signForm(f2);
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
		catch (const std::exception & e)
		{
		 	std::cerr << "Second test found: " << YELLOW
		 	<< RED << e.what() << RESET << std::endl;
		}
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
		std::cout << GREEN << "Destructors here." << RESET << std::endl;
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
		delete a1;
		delete a2;
		delete a3;
	}

	std::cout << MAG << "\n\n2.5th test commence!" << RESET << std::endl;
	{
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
		std::cout << GREEN << "Constructing new Bureaucrat" << RESET << std::endl;
		Bureaucrat a1(40, "Billy");
		Bureaucrat a2(50, "Keith");
		Bureaucrat a3(99, "Jim boy");
		Form f2;

		try
		{
			a1.signForm(f2);
			a2.signForm(f2);
			a3.signForm(f2);
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
		catch (const std::exception & e)
		{
		 	std::cerr << "2.5 test found: " << YELLOW
		 	<< RED << e.what() << RESET << std::endl;
		}
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
		std::cout << GREEN << "Destructors here." << RESET << std::endl;
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
	}

	std::cout << MAG << "\n\nthird test commence!(supposed to fail)" << RESET << std::endl;
	{
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
		std::cout << GREEN << "Constructing new Bureaucrat" << RESET << std::endl;
		Bureaucrat a1(149, "Billy");
		Bureaucrat a2(149, "Keith");
		Bureaucrat a3(149, "Jim boy");
		Form f2;
		try
		{
			a1.signForm(f2);
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
		catch (const std::exception & e)
		{
		 	std::cerr << "3rd test found: " << YELLOW
		 	<< RED << e.what() << RESET << std::endl;
		}
		
		try
		{
			a2.signForm(f2);
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
		catch (const std::exception & e)
		{
		 	std::cerr << "3rd test found: " << YELLOW
		 	<< RED << e.what() << RESET << std::endl;
		}
		
		try
		{
			a3.signForm(f2);
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
		catch (const std::exception & e)
		{
		 	std::cerr << "3rd test found: " << YELLOW
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

