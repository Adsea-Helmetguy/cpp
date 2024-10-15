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

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << RED << "Dog Default constructor called" << RESET << std::endl;
}

Dog::Dog(const std::string& name) : Animal(name)
{
	std::cout << RED << "Dog with std::string& name constructor called" \
	<< RESET << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Deconstructor called for: " << this->type << std::endl;
}

//
//
//
//New function added!
std::string		Dog::getType(void) const
{
	return(this->type);
}

