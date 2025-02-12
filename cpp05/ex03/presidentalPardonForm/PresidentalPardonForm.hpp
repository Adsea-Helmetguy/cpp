/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentalPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:35:16 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:35:18 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTALPARDONFORM_HPP
#define PRESIDENTALPARDONFORM_HPP

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

class PresidentalPardonForm : public AForm
{
	public:
		PresidentalPardonForm();
		PresidentalPardonForm(const std::string& name);
		PresidentalPardonForm(const PresidentalPardonForm& copy);
		PresidentalPardonForm& operator=(const PresidentalPardonForm& form);
		~PresidentalPardonForm();

		//create a file
		void	execute(Bureaucrat const & executor);
};

std::ostream& operator<<(std::ostream& os, const PresidentalPardonForm& other);
#endif
