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
	const std::string	_constant_name const;
	unsigned int		_grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string& name);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat&	operator=(const Bureaucrat &other);
	virtual ~Bureaucrat();

//
//NEW FUNCTIONS
	std::string	GradeTooHighException();
	std::string	GradeTooLowException();
	std::string	getName() const;
	std::string	getGrade() const;
	void		incrementGrade();
	void		decrementGrade();
};

#endif
