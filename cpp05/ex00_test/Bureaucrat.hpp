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
		const std::string	_name;
		unsigned int		_grade;
	public:
		Bureaucrat();					// default constructor
		Bureaucrat(const std::string& name);		// default constructor with name
		Bureaucrat(const Bureaucrat &other);		// copy constructor
		Bureaucrat(int value);				// default constructor with name)
		Bureaucrat(int value, const std::string& name);	// default constructor with name and value
		Bureaucrat& operator=(const Bureaucrat&)	// copy assignment
		~Bureaucrat();					// destructor
	
	//getters and setters:
	std::string	getName();
	unsigned int	getGrade();
	unsigned int	setGrade(int value);
	void			incrementGrade();
	void			decrementGrade();
	
	//exception classes
	class GradeTooHighException
	{
		
	};
	class GradeTooLowException
	{
		
	};
	
}

#endif
