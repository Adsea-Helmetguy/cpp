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
	//Upon construction, Dog and Cat will create their Brain using new Brain();
	this->_Brain = new Brain();
	std::cout << RED << "Dog Default constructor called" << RESET << std::endl;
}

Dog::Dog(const std::string& name) : Animal(name)
{
	this->type = name;
	this->_Brain = new Brain();
	std::cout << RED << "Doggo class with std::string& name constructor called" \
	<< RESET << std::endl;
	std::cout << "Doggo class's type is called: " \
	<< RED << this->type << RESET << std::endl;
}

//COPY CONSTRUCTOR
Dog::Dog(const Dog &other) : Animal(other)
{
	*this = other;
	std::cout << RED << "Dog copy constructor called" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	this->_Brain = other._Brain;
	std::cout << RED << "Dog copy assignment constructor called" << RESET << std::endl;
	return (*this);
}

Dog::~Dog()
{
	//Upon destruction, Dog and Cat will delete their Brain.
	delete _Brain;
	std::cout << "Dog Deconstructor " << RED << this->type << RESET << \
	" called: " << std::endl;
}

std::string		Dog::getType(void) const
{
	return(this->type);
}

void	Dog::makeSound() const
{
	std::cout << BLUE << "BORK BORK BORKKKK" << RESET << std::endl;
}
