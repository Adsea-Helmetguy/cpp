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

#include "Animal.hpp"

Animal::Animal() : type("Default_Animal")
{
	std::cout << RED << "Animal Default constructor called" << RESET << std::endl;
}

Animal::Animal(const std::string& name) : type(name)
{
	std::cout << RED << "Animal with std::string& name constructor called" \
	<< RESET << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << RED << "Animal copy constructor called" << RESET << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this == &other)//need to add & because 'this' is a pointer
	{
		std::cout << "Don't Self-assign!!" << std::endl;
		return *this; // handle self-assignment
	}
	this->type = other.type;
	std::cout << RED << "Animal copy assignment constructor called" << RESET << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Deconstructor " << BLUE << this->type << RESET << \
	" called" << std::endl;
}

std::string		Animal::getType(void) const
{
	return(this->type);
}

void	Animal::makeSound() const
{
	std::cout << BLUE << "Default Animal noises." << RESET << std::endl;
}























