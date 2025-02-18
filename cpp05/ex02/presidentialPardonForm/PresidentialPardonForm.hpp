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

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

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

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& name);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& form);
		~PresidentialPardonForm();

		//create a file
		void	execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& other);
#endif
