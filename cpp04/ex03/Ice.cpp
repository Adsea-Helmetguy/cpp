/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:21:49 by mlow              #+#    #+#             */
/*   Updated: 2024/11/05 15:21:50 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria()
{
	this->_type = "ice";
	std::cout << "\"" << GREEN << this->getType() << RESET \
	<< "\"  Ice Default constructor called" << std::endl;
}

Ice::Ice(const std::string& name) : AMateria(name)
{
	std::cout << "\"" << GREEN << this->getType() << RESET << "\"" \
	<< " Ice copy constructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << RED << "Ice copy constructor called" << RESET << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	if (this == &other)
	{
		std::cout << "Don't SELF-ASSIGN!!!" << std::endl;
		return (*this);
	}
	this->_type = other._type;
	std::cout << GREEN << "Ice copy assignment constructor called" << RESET << std::endl;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "@Ice Destructor: " << "\"" << RED \
	<< this->getType() << RESET << "\"" << " called" << std::endl;
}

std::string	const &Ice::getType() const//Returns the materia type
{
	return (this->_type);
}

Ice	*Ice::clone() const
{
	std::cout << GREEN << "Ice clone function called" << RESET << std::endl;
	return (new Ice(*this));
}























