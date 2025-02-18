/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
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

class AForm
{
	private:
		const std::string	_name;
		bool				_isTheFormSigned;
		const unsigned int	_requiredGrades;
		const unsigned int	_execGrades;

	public:
		AForm(unsigned int required, unsigned int exec);							// default constructor
		AForm(const std::string& name, unsigned int required, unsigned int exec);	// default constructor with name
		AForm(const AForm& copy);													// copy constructor
		AForm& operator=(const AForm& copy);										// copy assignment
		virtual ~AForm();															// destructor
	
	//  -------------getters and setters-------------
	const std::string	getName() const;
	bool				getBool() const;
	void				setBool(bool value);
	unsigned int		getrequiredGrades() const;
	unsigned int		getexecGrades() const;
	//  -------------getters and setters-------------

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};

//  ------------------------------------------------------------
	//signFroms
	void	besigned(const Bureaucrat& user);
	
	//create a file
	virtual void	execute(Bureaucrat const & executor) = 0;
//  ------------------------------------------------------------
};

std::ostream& operator<<(std::ostream& os, const AForm& other);
#endif
