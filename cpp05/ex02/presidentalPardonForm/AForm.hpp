/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:35:16 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:35:18 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

# include <iostream>
# include <string>//std::string
# include <exception>//std::exception, https://en.cppreference.com/w/cpp/header/exception

# include "Bureaucrat/Bureaucrat.hpp"

class Bureaucrat;

# define RESET	"\033[0m"
# define RED	"\033[31m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define GREEN	"\033[32m"
# define MAG	"\e[0;35m"
// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class Form
{
	private:
		const std::string	_name;
		bool				_isTheFormSigned;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExecute;

	public:
		Form();										// default constructor
		Form(const std::string& name);				// default constructor with name
		Form(const Form& copy);						// copy constructor
		Form& operator=(const Form& copy);			// copy assignment
		~Form();									// destructor
	
	//  -------------getters and setters-------------
	const std::string	getName() const;
	bool				getBool() const;
	unsigned int		getGradeToSign() const;
	unsigned int		getGradeToExecute() const;
	//  -------------getters and setters-------------

	//signFroms
	void	besigned(const Bureaucrat& user);



	class GradeTooHighException
	{
		private:
			std::string	_msg;

		public:
			GradeTooHighException(const std::string& message);
			virtual const char* what() const throw();
			virtual ~GradeTooHighException() throw();
	};
	
	class GradeTooLowException
	{
		private:
			std::string	_msg;

		public:
			GradeTooLowException(const std::string& message);
			virtual const char* what() const throw();
			virtual ~GradeTooLowException() throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& other);
#endif
