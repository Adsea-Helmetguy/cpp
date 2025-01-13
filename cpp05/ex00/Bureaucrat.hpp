/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
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
# define RED     "\033[31m"//Red
# define YELLOW  "\033[33m"//Yellow
# define BLUE    "\033[34m"//Blue

// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class Bureaucrat
{	
	private:
		const std::string	_constant_name;
		unsigned int		_grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name);
		Bureaucrat(int grade);
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat&	operator=(const Bureaucrat &other);
		~Bureaucrat();

//
//NEW FUNCTIONS
	std::string		getName() const;
	unsigned int	getGrade() const;
	unsigned int	setGrade(int value);
	void			incrementGrade();
	void			decrementGrade();

//
//Exceptions
	class GradeTooHighException : public std::exception
	{
		private:
			std::string	_message;
		public:
			GradeTooHighException(const std::string& message);
			virtual const char* what() const throw();
			virtual ~GradeTooHighException() throw();
	};

	class GradeTooLowException : public std::exception
	{
		private:
			std::string	_message;
		public:
			GradeTooLowException(const std::string& message);
			virtual const char* what() const throw();
			virtual ~GradeTooLowException() throw();
	};
};
/*
To use an exception class, you 
first need to define the class by deriving it from 
the standard exception class 
"std::exception"
*/

#endif
