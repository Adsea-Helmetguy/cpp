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
	//Upon construction, Dog and Dog will create their Brain using new Brain();
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
	<< GREEN << this->type << RESET << std::endl;
}

//COPY CONSTRUCTOR
Dog::Dog(const Dog &other)  : Animal(other), _Brain(NULL)
{
	//*this = other;
	this->_Brain = new Brain(*other._Brain);
	this->type = other.type;
	std::cout << RED << "Dog copy constructor called" << RESET << std::endl;
}

//Shallow Copy in the Assignment Operator (operator=):
//You are copying the Brain* from other without 
// creating a new Brain object, 
//  so both objects end up pointing to the same Brain.
//
//cause when you free jack2, you also freed the first jack due to
// shallow copy, causing seg fault when you tried to free both jacks
//  cause the other one is already freed >w<.
Dog &Dog::operator=(const Dog &other)
{
	if (this == &other)//need to add & because 'this' is a pointer
	{
		std::cout << "Don't Self-assign!!" << std::endl;
		return *this; // handle self-assignment
	}
	if (this->_Brain)
		delete this->_Brain;
	this->_Brain = new Brain(*other._Brain);
	this->type = other.type;
	std::cout << RED << "Dog copy assignment constructor called" << RESET << std::endl;
	return (*this);
}

Dog::~Dog()
{
	//Upon destruction, Dog and Dog will delete their Brain.
	if (this->_Brain)
		delete this->_Brain;
	std::cout << "Dog Deconstructor " << BLUE << this->type << RESET << \
	" called: " << std::endl;
}

std::string	Dog::getType(void) const
{
	return(this->type);
}

void	Dog::makeSound() const
{
	std::cout << BLUE << "Meow~" << RESET << std::endl;
}

void	Dog::edit_brain(int idea_number, std::string input_ideas)
{
	std::cout << "inside Function edit_brain for Dog!" << std::endl;
	//assign new brain ideas for the Dog.
	if (idea_number > 100)
	{
		std::cout << "Don't input values more than 100!!" << std::endl;
		std::cout << "RETURNING!" << std::endl;
		return ;
	}
	this->_Brain->idea_member(idea_number, input_ideas);
}

void	Dog::get_brain(int idea_number)
{
	std::cout << "inside Dog's: " << BLUE << this->type \
	<< RESET << " get_brain function!" << std::endl;
	this->_Brain->obtain_idea(idea_number);
}

void	Dog::get_brain_address()
{
	std::cout << GREEN << "THIS ADDRESS: " << BLUE << this \
	<< RESET << std::endl;
	std::cout << GREEN << "Brain's address: " << BLUE << this->_Brain \
	<< RESET << std::endl;
}
