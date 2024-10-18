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
	//Upon construction, Dog and Cat will create their Brain using new Brain();
	this->_Brain = new Brain();
	std::cout << RED << "Cat Default constructor called" << RESET << std::endl;
}

Cat::Cat(const std::string& name) : Animal(name)
{
	this->type = name;
	this->_Brain = new Brain();
	std::cout << RED << "Cat class with std::string& name constructor called" \
	<< RESET << std::endl;
	std::cout << "Cat class's type is called: " \
	<< RED << this->type << RESET << std::endl;
}

//COPY CONSTRUCTOR
Cat::Cat(const Cat &other) : Animal(other)
{
	*this = other;
	std::cout << RED << "Cat copy constructor called" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	this->_Brain = other._Brain;
	std::cout << RED << "Cat copy assignment constructor called" << RESET << std::endl;
	return (*this);
}

Cat::~Cat()
{
	//Upon destruction, Dog and Cat will delete their Brain.
	delete _Brain;
	std::cout << "Cat Deconstructor " << RED << this->type << RESET << \
	" called: " << std::endl;
}

std::string	Cat::getType(void) const
{
	return(this->type);
}

void	Cat::makeSound() const
{
	std::cout << BLUE << "Meow~" << RESET << std::endl;
}

