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
	std::cout << "Animal copy constructor called\n";
}

Animal &Animal::operator=(const Animal &other)
{
	type = other.type;
	std::cout << "Animal copy assignment constructor called\n";
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Deconstructor called for: " << this->type << std::endl;
}

std::string		Animal::getType(void) const
{
	return(this->type);
}

void	Animal::makeSound() const
{
	if (this->type == "Dog")
	{
		std::cout << YELLOW << "BORK BORK BORKKKK" << std::endl;
		return ;
	}
	else if (this->type == "Cat")
	{
		std::cout << YELLOW << "Meow~" << std::endl;
		return ;
	}
	std::cout << YELLOW << "Default Animal noises." << std::endl;
}





//a method virtual, c++ will perform runtime polymorphism
// a method to call the base class on the actual object type not the pointer.






















