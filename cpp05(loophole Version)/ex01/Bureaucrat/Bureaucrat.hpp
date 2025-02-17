/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:35:16 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:35:18 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <string>//std::string
# include <exception>//std::exception, https://en.cppreference.com/w/cpp/header/exception

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define GREEN   "\033[32m"

# include "Form.hpp"

class Form;

// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int		_grade;
	public:
		Bureaucrat();					// default constructor
		Bureaucrat(const std::string& name);		// default constructor with name
		Bureaucrat(const Bureaucrat &other);		// copy constructor
		Bureaucrat(int value);				// default constructor with int
		Bureaucrat(int value, const std::string& name);	// constructor with name and int
		Bureaucrat& operator=(const Bureaucrat& copy);	// copy assignment
		~Bureaucrat();					// destructor
	
	//getters and setters:
	std::string		getName() const;//const means not allow to change private value
	unsigned int	getGrade() const;//const means not allow to change private value
//note: You will get a compilation error if u don't put const, because the compiler 
// cannot guarantee that the function won't modify the object, 
// and calling non-const functions on const objects is disallowed.
	void			setGrade(int value);
	void			incrementGrade();
	void			decrementGrade();
	void			signForm(Form& form_tosign);
	
	//exception classes
	class GradeTooHighException : public std::exception
	{
		private:
			std::string _msg;
		public:
			GradeTooHighException(const std::string& message);
			virtual const char* what() const throw();
			//virtual | const char* | what() | const | throw;//throw here means 
			//u can't make what() throw an exception.
			//note, the const here ("const" throw) means u 
			//are not allowed to change the class of what();
			virtual ~GradeTooHighException() throw();
			 
	};
	class GradeTooLowException : public std::exception
	{
		private:
			std::string _msg;
		public:
			GradeTooLowException(const std::string& message);
			virtual const char* what() const throw();
			virtual ~GradeTooLowException() throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);
#endif
/*
--links to learn structure of Exception classes:--
https://rollbar.com/blog/cpp-custom-exceptions
https://diginode.in/cpp/custom-exception-classes/
https://peterforgacs.github.io/2017/06/25/Custom-C-Exceptions-For-Beginners
*/

