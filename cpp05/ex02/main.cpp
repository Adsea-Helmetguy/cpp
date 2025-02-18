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
#include "presidentialPardonForm/PresidentialPardonForm.hpp"

int	main()
{
	srand(time(0));
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
	std::cout << MAG << "\n\nFirst test commence!" << RESET << std::endl;
	{
		//1) Shrubbery
		// -------------------------------------------------------
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
		Bureaucrat a1;
		std::cout << a1 << std::endl;
		try
		{
			a1 = Bureaucrat(150, "Bureaucrat_shawnShrubbery");
			a1.incrementGrade();
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
		}
		catch (const std::exception & e)
		{
		 	std::cerr << RED << a1.getName() << MAG << " couldn’t sign " \
		 		<< YELLOW << f1.getName() << MAG << " because " \
				<< RED << e.what() << RESET << std::endl;
		}
		try
		{

			a1.executeForm(f1);
		}
		catch (const std::exception & e)
		{
		 	std::cerr << RED << a1.getName() << MAG << " couldn’t execute " \
		 		<< YELLOW << f1.getName() << MAG << " because " \
				<< RED << e.what() << RESET << std::endl;
		}
		f1.execute(a1);
		std::cout << YELLOW << "----------------------------\n\n" \
			<< RESET << std::endl;
		std::cout << f1 << std::endl;


		//2) Robotomy
		// -------------------------------------------------------
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
		Bureaucrat a2;
		std::cout << a2 << std::endl;
		try
		{
			a2 = Bureaucrat(150, "Bureaucrat_shawnRobot");
			a2.incrementGrade();
		}
		catch (const std::exception & e)
		{
		 	std::cerr << "general issue found " << YELLOW
		 	<< RED << e.what() << RESET << std::endl;
		}

		RobotomyRequestForm f2("Robotomy1");
		std::cout << a2 << std::endl;
		try
		{
			a2.signAForm(f2);
		}
		catch (const std::exception & e)
		{
		 	std::cerr << RED << a2.getName() << MAG << " couldn’t sign " \
		 		<< YELLOW << f2.getName() << MAG << " because " \
				<< RED << e.what() << RESET << std::endl;
		}
		try
		{

			a2.executeForm(f2);
		}
		catch (const std::exception & e)
		{
		 	std::cerr << RED << a2.getName() << MAG << " couldn’t execute " \
		 		<< YELLOW << f2.getName() << MAG << " because " \
				<< RED << e.what() << RESET << std::endl;
		}
		f2.execute(a2);
		std::cout << YELLOW << "----------------------------\n\n" \
			<< RESET << std::endl;
		std::cout << f2 << std::endl;
		
		//3) Presidential
		//------------------------------------------------------
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
		Bureaucrat a3;
		std::cout << a3 << std::endl;
		try
		{
			a3 = Bureaucrat(150, "Bureaucrat_shawnPresident");
			a3.incrementGrade();
		}
		catch (const std::exception & e)
		{
		 	std::cerr << "general issue found " << YELLOW
		 	<< RED << e.what() << RESET << std::endl;
		}

		PresidentialPardonForm f3("PresidentialPardon1");
		std::cout << a3 << std::endl;
		try
		{
			a3.signAForm(f3);
		}
		catch (const std::exception & e)
		{
		 	std::cerr << RED << a3.getName() << MAG << " couldn’t sign " \
		 		<< YELLOW << f2.getName() << MAG << " because " \
				<< RED << e.what() << RESET << std::endl;
		}
		try
		{

			a3.executeForm(f3);
		}
		catch (const std::exception & e)
		{
		 	std::cerr << RED << a3.getName() << MAG << " couldn’t execute " \
		 		<< YELLOW << f2.getName() << MAG << " because " \
				<< RED << e.what() << RESET << std::endl;
		}
		f3.execute(a3);
		std::cout << YELLOW << "----------------------------\n\n" \
			<< RESET << std::endl;
		std::cout << f3 << std::endl;
	}
	





































	srand(time(0));
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
	std::cout << MAG << "Second test commence!(sign but no execute)" << RESET << std::endl;
	{
		//1) Shrubbery
		// -------------------------------------------------------
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
		Bureaucrat a1;
		std::cout << a1 << std::endl;
		try
		{
			a1 = Bureaucrat(140, "Bureaucrat_shawnShrubbery");
			a1.incrementGrade();
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
		}
		catch (const std::exception & e)
		{
		 	std::cerr << RED << a1.getName() << MAG << " couldn’t sign " \
		 		<< YELLOW << f1.getName() << MAG << " because " \
				<< RED << e.what() << RESET << std::endl;
		}
		try
		{

			a1.executeForm(f1);
		}
		catch (const std::exception & e)
		{
		 	std::cerr << RED << a1.getName() << MAG << " couldn’t execute " \
		 		<< YELLOW << f1.getName() << MAG << " because " \
				<< RED << e.what() << RESET << std::endl;
		}
		f1.execute(a1);
		std::cout << YELLOW << "----------------------------\n\n" \
			<< RESET << std::endl;
		std::cout << f1 << std::endl;


		//2) Robotomy
		// -------------------------------------------------------
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
		Bureaucrat a2;
		std::cout << a2 << std::endl;
		try
		{
			a2 = Bureaucrat(66, "Bureaucrat_shawnRobot");
			a2.incrementGrade();
		}
		catch (const std::exception & e)
		{
		 	std::cerr << "general issue found " << YELLOW
		 	<< RED << e.what() << RESET << std::endl;
		}

		RobotomyRequestForm f2("Robotomy1");
		std::cout << a2 << std::endl;
		try
		{
			a2.signAForm(f2);
		}
		catch (const std::exception & e)
		{
		 	std::cerr << RED << a2.getName() << MAG << " couldn’t sign " \
		 		<< YELLOW << f2.getName() << MAG << " because " \
				<< RED << e.what() << RESET << std::endl;
		}
		try
		{

			a2.executeForm(f2);
		}
		catch (const std::exception & e)
		{
		 	std::cerr << RED << a2.getName() << MAG << " couldn’t execute " \
		 		<< YELLOW << f2.getName() << MAG << " because " \
				<< RED << e.what() << RESET << std::endl;
		}
		f2.execute(a2);
		std::cout << YELLOW << "----------------------------\n\n" \
			<< RESET << std::endl;
		std::cout << f2 << std::endl;
		

		//3) Presidential
		// -------------------------------------------------------
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
		Bureaucrat a3;
		std::cout << a3 << std::endl;
		try
		{
			a3 = Bureaucrat(20, "Bureaucrat_shawnPresident");
			a3.incrementGrade();
		}
		catch (const std::exception & e)
		{
		 	std::cerr << "general issue found " << YELLOW
		 	<< RED << e.what() << RESET << std::endl;
		}

		PresidentialPardonForm f3("PresidentialPardon1");
		std::cout << a3 << std::endl;
		try
		{
			a3.signAForm(f3);
		}
		catch (const std::exception & e)
		{
		 	std::cerr << RED << a3.getName() << MAG << " couldn’t sign " \
		 		<< YELLOW << f3.getName() << MAG << " because " \
				<< RED << e.what() << RESET << std::endl;
		}
		try
		{

			a3.executeForm(f3);
		}
		catch (const std::exception & e)
		{
		 	std::cerr << RED << a3.getName() << MAG << " couldn’t execute " \
		 		<< YELLOW << f3.getName() << MAG << " because " \
				<< RED << e.what() << RESET << std::endl;
		}
		f3.execute(a3);
		std::cout << YELLOW << "----------------------------\n\n" \
			<< RESET << std::endl;
		std::cout << f3 << std::endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	
	
	
	
	
	
	srand(time(0));
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
	std::cout << MAG << "Third test commence!(sign && execute~)" << RESET << std::endl;
	{
		//1) Shrubbery
		// -------------------------------------------------------
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
		Bureaucrat *a1 = NULL;
		try
		{
			a1 = new Bureaucrat(5, "Bureaucrat_shawnShrubbery");
		}
		catch (const std::exception & e)
		{
		 	std::cerr << "general issue found " << YELLOW
		 		<< RED << e.what() << RESET << std::endl;
		}

		ShrubberyCreationForm f1("Shrub1");
		std::cout << *a1 << std::endl;
		try
		{
			a1->signAForm(f1);
		}
		catch (const std::exception & e)
		{
		 	std::cerr << RED << a1->getName() << MAG << " couldn’t sign " \
		 		<< YELLOW << f1.getName() << MAG << " because " \
				<< RED << e.what() << RESET << std::endl;
		}
		try
		{

			a1->executeForm(f1);
		}
		catch (const std::exception & e)
		{
		 	std::cerr << RED << a1->getName() << MAG << " couldn’t execute " \
		 		<< YELLOW << f1.getName() << MAG << " because " \
				<< RED << e.what() << RESET << std::endl;
		}
		f1.execute(*a1);
		std::cout << YELLOW << "----------------------------\n\n" \
			<< RESET << std::endl;
		std::cout << f1 << std::endl;
		delete a1;


		//2) Robotomy
		// -------------------------------------------------------
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
		Bureaucrat *a2 = NULL;
		try
		{
			a2 = new Bureaucrat(5, "Bureaucrat_shawnRobot");
		}
		catch (const std::exception & e)
		{
		 	std::cerr << "general issue found " << YELLOW
		 	<< RED << e.what() << RESET << std::endl;
		}

		RobotomyRequestForm f2("Robotomy1");
		try
		{
			a2->signAForm(f2);
		}
		catch (const std::exception & e)
		{
		 	std::cerr << RED << a2->getName() << MAG << " couldn’t sign " \
		 		<< YELLOW << f2.getName() << MAG << " because " \
				<< RED << e.what() << RESET << std::endl;
		}
		try
		{

			a2->executeForm(f2);
		}
		catch (const std::exception & e)
		{
		 	std::cerr << RED << a2->getName() << MAG << " couldn’t execute " \
		 		<< YELLOW << f2.getName() << MAG << " because " \
				<< RED << e.what() << RESET << std::endl;
		}
		f2.execute(*a2);
		std::cout << YELLOW << "----------------------------\n\n" \
			<< RESET << std::endl;
		std::cout << f2 << std::endl;
		delete a2;
		

		//3) Presidential
		// -------------------------------------------------------
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
		Bureaucrat *a3 = NULL;
		try
		{
			a3 = new Bureaucrat(5, "Bureaucrat_shawnPresident");
		}
		catch (const std::exception & e)
		{
		 	std::cerr << "general issue found " << YELLOW
		 	<< RED << e.what() << RESET << std::endl;
		}

		PresidentialPardonForm f3("PresidentialPardon1");
		std::cout << a3 << std::endl;
		try
		{
			a3->signAForm(f3);
		}
		catch (const std::exception & e)
		{
		 	std::cerr << RED << a3->getName() << MAG << " couldn’t sign " \
		 		<< YELLOW << f3.getName() << MAG << " because " \
				<< RED << e.what() << RESET << std::endl;
		}
		try
		{

			a3->executeForm(f3);
		}
		catch (const std::exception & e)
		{
		 	std::cerr << RED << a3->getName() << MAG << " couldn’t execute " \
		 		<< YELLOW << f3.getName() << MAG << " because " \
				<< RED << e.what() << RESET << std::endl;
		}
		f3.execute(*a3);
		std::cout << YELLOW << "----------------------------\n\n" \
			<< RESET << std::endl;
		std::cout << f3 << std::endl;
		delete a3;
	}
	
	
	std::cout << "\n\n\n\n\n\n\n\n\n" << std::endl;
	return (0);
};
