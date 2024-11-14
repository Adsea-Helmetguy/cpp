/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:21:54 by mlow              #+#    #+#             */
/*   Updated: 2024/11/05 15:21:54 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria()
{
	this->_type = "cure";
	std::cout << "\"" << GREEN << this->getType() << RESET \
	<< "\"  Cure Default constructor called" << std::endl;
}

Cure::Cure(const std::string& name) : AMateria(name)
{
	std::cout << "\"" << GREEN << this->getType() << RESET << "\"" \
	<< " Cure copy constructor called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	std::cout << GREEN << "Cure copy constructor called" << RESET << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	if (this == &other)
	{
		std::cout << "Don't SELF-ASSIGN!!!" << std::endl;
		return (*this);
	}
	std::cout << GREEN << "Cure copy assignment constructor called" << RESET << std::endl;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "@Cure Destructor: "<< "\"" << RED << this->getType() << RESET \
	<< "\"" << " DESTROY DESTRUCTION!!!!!!" << std::endl;
}

//https://isocpp.org/wiki/faq/virtual-functions#:~:text=A%20pure%20virtual%20function%20is,using%20the%20curious%20%3D0%20syntax.
//also from topic:
//if you clone an Ice Materia, you will get a "new" Ice Materia. hint hint, "new".
Cure	*Cure::clone() const
{
	std::cout << GREEN << "Cure clone function called" << RESET << std::endl;
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{	
	
	std::cout << GREEN << "* heals " \
	<< YELLOW << target.getName() << RESET \
	<< GREEN << "'s wounds *" << RESET << std::endl;
}






















