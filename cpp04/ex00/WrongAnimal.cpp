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

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Default_WrongAnimal")
{
	std::cout << RED << "WrongAnimal Default constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& name) : type(name)
{
	std::cout << RED << "WrongAnimal class with std::string& name constructor called" \
	<< RESET << std::endl;
	std::cout << "WrongAnimal class's type is called: " \
	<< RED << this->type << RESET << std::endl;
}

//COPY CONSTRUCTOR
WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
	//*this = other;
	std::cout << RED << "WrongAnimal copy constructor called" << RESET << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this == &other)//need to add & because 'this' is a pointer
	{
		std::cout << "Don't Self-assign!!" << std::endl;
		return *this; // handle self-assignment
	}
	this->type = other.type;
	std::cout << RED << "WrongAnimal copy assignment constructor called" << RESET << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Deconstructor " << RED << this->type << RESET << \
	" called: " << std::endl;
}

//
//
//
//New function added!
std::string	WrongAnimal::getType(void) const
{
	return(this->type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << BLUE << "Default WrongAnimal noises." << RESET << std::endl;
}





//a method virtual, c++ will perform runtime polymorphism
// a method to call the base class on the actual object type not the pointer.






















