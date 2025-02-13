/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:35:16 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:35:18 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

# include <iostream>
# include <string>//std::string
# include <exception>//std::exception, https://en.cppreference.com/w/cpp/header/exception

# include "../form/Form.hpp"

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define GREEN   "\033[32m"

// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class Intern
{
	public:
		Intern();
		Intern(const Intern& copy);
		Intern&	operator=(const Intern& copy);
		~Intern();
	
	AForm*	Shrubbery_requested(std::string form_target);
	AForm*	Robotomy_requested(std::string form_target);
	AForm*	Presidental_requested(std::string form_target);
	
	AForm* makeForm(std::string form_name, std::string form_target);
	//they asked for returning pointer, if reference it would be:
	//"AForm&" makeform()
};
//
//std::ostream& operator<<(std::ostream& os, const AForm& form);
#endif
/*
--links to learn structure of Exception classes:--
https://rollbar.com/blog/cpp-custom-exceptions
https://diginode.in/cpp/custom-exception-classes/
https://peterforgacs.github.io/2017/06/25/Custom-C-Exceptions-For-Beginners
*/

