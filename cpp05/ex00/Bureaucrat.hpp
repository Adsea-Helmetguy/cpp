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
	class GradeTooHighException : public std::exception
	{
	private:
		std::string			_message;
	public:
		void	MyException(const std::string& message);
	};

	class GradeTooLowException : public std::exception
	{
	private:
		std::string			_message;
	public:
		void	MyException(const std::string& message);
	};

private:
	const std::string	_constant_name;
	unsigned int		_grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string& name);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat&	operator=(const Bureaucrat &other);
	virtual ~Bureaucrat();

//
//NEW FUNCTIONS
	std::string		getName() const;
	unsigned int	getGrade() const;
	void			incrementGrade();
	void			decrementGrade();
};
/*
To use an exception class, you 
first need to define the class by deriving it from 
the standard exception class 
"std::exception"
*/

#endif
