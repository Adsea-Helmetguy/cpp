/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:34:28 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:34:30 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << RED << "Cat Default constructor called" << RESET << std::endl;
}

Cat::Cat(const std::string& name) : Animal(name)
{
	std::cout << RED << "Cat class with std::string& name constructor called" \
	<< RESET << std::endl;
	std::cout << RED << "Cat class's type is called: " \
	<< RESET << this->type << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Deconstructor called for: " << this->type << std::endl;
}

//
//
//
//New function added!
std::string	Cat::getType(void) const
{
	return(this->type);
}



