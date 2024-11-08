/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:12:19 by mlow              #+#    #+#             */
/*   Updated: 2024/11/05 14:13:33 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/*
	AMateria();
 	AMateria(std::string const & type);
	AMateria(const AMateria &copy);
	virtual ~AMateria();// Destructor
*/
AMateria::AMateria() : _type("Default_AMaterial")
{
	std::cout << "\"" << GREEN << this->getType() << RESET << "\"" \
	<< " AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const std::string &type) : _type(type)
{
	std::cout << "\"" << GREEN << this->getType() << RESET << "\"" \
	<< " AMateria copy constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &type) : _type(type._type)
{
	std::cout << RED << "AMateria copy constructor called" << RESET << std::endl;
}

//Not finished
AMateria	&AMateria::operator=(const AMateria &copy)
{
	if (this == &copy)//"this" is a pointer
	{
		std::cout << "Don't SELF-ASSIGN!!!" << std::endl;
		return (*this);
	}
	//While assigning a Materia to another, copying the type doesn’t make sense.
	//this->_type = copy.type;//Do not uncomment cause it is wrong!
	std::cout << "AMateria copy assignment \"operator=()\" called" << std::endl;
	return (*this);//(*this) because '&'AMateria
}

AMateria::~AMateria()
{
	std::cout << YELLOW << "\"AMateria: " << RED \
	<< this->getType() << YELLOW << "\"" \
	<< RESET << " Destructor called" << std::endl;
}

//
//
//
//
// Getters & Setters
std::string	const &AMateria::getType() const//Returns the materia type
{
	return (this->_type);
}


void	AMateria::use(ICharacter& target)
{
	std::cout << GREEN << "* AMateria: " << YELLOW << target.getName() \
	<< RESET <<" is used on Target wounds *" << GREEN << std::endl;
}










































