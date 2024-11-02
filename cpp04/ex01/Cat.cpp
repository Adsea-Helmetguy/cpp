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
	//Upon construction, Cat and Cat will create their Brain using new Brain();
	this->_Brain = new Brain();
	std::cout << RED << "Cat Default constructor called" << RESET << std::endl;
}

Cat::Cat(const std::string& name) : Animal(name)
{
	this->type = name;
	this->_Brain = new Brain();
	std::cout << RED << "Catgo class with std::string& name constructor called" \
	<< RESET << std::endl;
	std::cout << "Catgo class's type is called: " \
	<< GREEN << this->type << RESET << std::endl;
}

//COPY CONSTRUCTOR
Cat::Cat(const Cat &other) : Animal(other)
{
	*this = other;
	std::cout << RED << "Cat copy constructor called" << RESET << std::endl;
}

//Shallow Copy in the Assignment Operator (operator=):
//You are copying the Brain* from other without 
// creating a new Brain object, 
//  so both objects end up pointing to the same Brain.
//
//cause when you free jack2, you also freed the first jack due to
// shallow copy, causing seg fault when you tried to free both jacks
//  cause the other one is already freed >w<.
Cat &Cat::operator=(const Cat &other)
{
	if (this == &other)//need to add & because 'this' is a pointer
	{
		std::cout << "Don't Self-assign!!" << std::endl;
		return *this; // handle self-assignment
	}
	delete this->_Brain;
	this->_Brain = new Brain(*other._Brain);
	this->type = other.type;
	std::cout << RED << "Cat copy assignment constructor called" << RESET << std::endl;
	return (*this);
}

Cat::~Cat()
{
	//Upon destruction, Cat and Cat will delete their Brain.
	delete _Brain;
	std::cout << "Cat Deconstructor " << BLUE << this->type << RESET << \
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

void	Cat::edit_brain(int idea_number, std::string input_ideas)
{
	std::cout << "inside Function edit_brain for Cat!" << std::endl;
	//assign new brain ideas for the Cat.
	if (idea_number > 100)
	{
		std::cout << "Don't input values more than 100!!" << std::endl;
		std::cout << "RETURNING!" << std::endl;
		return ;
	}
	this->_Brain->idea_member(idea_number, input_ideas);
}

void	Cat::get_brain(int idea_number)
{
	std::cout << "inside Cat's: " << BLUE << this->type \
	<< RESET << " get_brain function!" << std::endl;
	this->_Brain->obtain_idea(idea_number);
}

/*
#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	//Upon construction, Cat and Cat will create their Brain using new Brain();
	this->_Brain = new Brain();
	std::cout << RED << "Cat Default constructor called" << RESET << std::endl;
}

Cat::Cat(const std::string& name) : Animal(name)
{
	this->type = name;
	this->_Brain = new Brain();
	std::cout << RED << "Catgo class with std::string& name constructor called" \
	<< RESET << std::endl;
	std::cout << "Catgo class's type is called: " \
	<< GREEN << this->type << RESET << std::endl;
}

//COPY CONSTRUCTOR
Cat::Cat(const Cat &other) : Animal(other)
{
	*this = other;
	std::cout << RED << "Cat copy constructor called" << RESET << std::endl;
}

//Shallow Copy in the Assignment Operator (operator=):
//You are copying the Brain* from other without 
// creating a new Brain object, 
//  so both objects end up pointing to the same Brain.
//
//cause when you free jack2, you also freed the first jack due to
// shallow copy, causing seg fault when you tried to free both jacks
//  cause the other one is already freed >w<.
Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		delete this->_Brain;
		this->_Brain = new Brain(*other._Brain);
		this->type = other.type;
	}
	std::cout << RED << "Cat copy assignment constructor called" << RESET << std::endl;
	return (*this);
}

Cat::~Cat()
{
	//Upon destruction, Cat and Cat will delete their Brain.
	delete _Brain;
	std::cout << "Cat Deconstructor " << BLUE << this->type << RESET << \
	" called: " << std::endl;
}

std::string		Cat::getType(void) const
{
	return(this->type);
}

void	Cat::makeSound() const
{
	std::cout << BLUE << "BORK BORK BORKKKK" << RESET << std::endl;
}

void	Cat::edit_brain(int idea_number, std::string input_ideas)
{
	std::cout << "inside Function edit_brain for Cat!" << std::endl;
	//assign new brain ideas for the Cat.
	if (idea_number > 100)
	{
		std::cout << "Don't input values more than 100!!" << std::endl;
		std::cout << "RETURNING!" << std::endl;
		return ;
	}
	this->_Brain->idea_member(idea_number, input_ideas);
}

void	Cat::get_brain(int idea_number)
{
	std::cout << "inside Cat's: " << BLUE << this->type \
	<< RESET << " get_brain function!" << std::endl;
	this->_Brain->obtain_idea(idea_number);
}
*/
