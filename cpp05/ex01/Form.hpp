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
		Form();
		Form(const std::string& name);
		Form(const Form& copy);
		Form& operator=(const Form& copy);
		~Form();
	
	//setters and getters
	
};
#endif
/*
--links to learn structure of Exception classes:--
https://rollbar.com/blog/cpp-custom-exceptions
https://diginode.in/cpp/custom-exception-classes/
https://peterforgacs.github.io/2017/06/25/Custom-C-Exceptions-For-Beginners

--links to learn--
*/
