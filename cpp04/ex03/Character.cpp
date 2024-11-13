/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:04:44 by mlow              #+#    #+#             */
/*   Updated: 2024/11/06 09:04:45 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

int	Character::_discarded_slot = 0;

/*
The use(ICharacter&) member function will display:
• Ice: "* shoots an ice bolt at <name> *"
• Cure: "* heals <name>’s wounds *"

<name> is the name of the Character passed as parameter. Don’t print the angle
brackets (< and >).
*/
Character::Character() : _name("From ICharacter")
{
	for (int i = 0; i < 4; i++)
	{
		_Materia_slot[i] = NULL;
	}
	for (int i = 0; i < 50; i++)
	{
		_discarded_Materia[i] = NULL;
	}
	std::cout << "Character: " << this->_name \
	<< " Created @ Default constructor" << std::endl;
}

Character::Character(const std::string &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
	{
		this->_Materia_slot[i] = NULL;
	}
	for (int i = 0; i < 50; i++)
	{
		_discarded_Materia[i] = NULL;
	}
	std::cout << "Character: " << this->_name << " Created" << std::endl;
}











//COPY CONSTRUCTOR
Character::Character(const Character &copy)
{
	this->_name = copy.getName();
	for (int i = 0; i < 4; i++)
	{
		this->_Materia_slot[i] = NULL;
		if (copy._Materia_slot[i])
			this->_Materia_slot[i] = copy._Materia_slot[i]->clone();
	}
	for (int i = 0; i < 50; i++)
	{
		this->_discarded_Materia[i] = NULL;
	}
	std::cout << "Character COPY CONSTRUCTOR " << this->_name << " Called!!" << std::endl;
}



Character	&Character::operator=(const Character &copy)
{
	if (this == &copy)//"this" is a pointer
	{
		std::cout << RED << "Don't SELF-ASSIGN!!!" << RESET << std::endl;
		return (*this);
	}
	std::cout << RED << "Test that OPERATOR=() WORKS!!" << RESET << std::endl;
	this->_name = copy.getName();
	for (int i = 0; i < 4; i++)
	{
		if (this->_Materia_slot[i])
			delete (this->_Materia_slot[i]);
		this->_Materia_slot[i] = NULL;
		if (copy._Materia_slot[i])
			this->_Materia_slot[i] = copy._Materia_slot[i]->clone();
	}
	for (int i = 0; i < 50; i++)
	{
		if (this->_discarded_Materia[i])
			delete (this->_discarded_Materia[i]);
		this->_discarded_Materia[i] = NULL;
		if (copy._discarded_Materia[i])
			this->_discarded_Materia[i] = copy._discarded_Materia[i]->clone();
	}
	std::cout << "Character operator=() " << this->_name << " Called!!" << std::endl;
	return (*this);
}






































Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_Materia_slot[i])
		{
			delete (this->_Materia_slot[i]);
			this->_Materia_slot[i] = NULL;
		}		
	}
	for (int i = 0; i < 50; i++)
	{
		if (this->_discarded_Materia[i])
		{
			delete (this->_discarded_Materia[i]);
			this->_discarded_Materia[i] = NULL;
		}
	}
	std::cout << "Character: " << this->_name \
	<< "........... DESTRUCTION!!!!" << std::endl;
}

std::string const	&Character::getName() const
{
	return (this->_name);
}


void 			Character::equip(AMateria* m)
{
	if (!m)//check if 'm' exists
	{
		std::cout << "This AMateria doesn't exist!!!" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!(this->_Materia_slot[i]))
		{
			this->_Materia_slot[i] = m;
			std::cout << this->getName() << " equipped with: \"" \
			GREEN << m->getType() << RESET << "\" @ slot(" << i << ")" << std::endl;
			return ;
		}
	}
	std::cout << this->_name << "'s slots are full, unable to add:\"" << GREEN \
	<< m->getType() << RESET << "\" to any slot. " \
	<< "Materia falls to the ground." << std::endl;

	//Replaces the OLDEST Materia with the latest one!
	_discarded_slot %= 50;
	this->_discarded_Materia[_discarded_slot] = m;
	std::cout << this->_name << " added to discard pile(" \
	<< RED << _discarded_slot << RESET << ") successfully" << std::endl;
	_discarded_slot += 1;

	//delete m; //but do we need this?
}

void 			Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << RED << "Invalid inventory index!" << RESET << std::endl;
		return ;
	}
	if (this->_Materia_slot[idx])
	{
		std::cout << this->getName() << RED << " discarded: \"" \
		GREEN << this->_Materia_slot[idx]->getType() << RED << "\" " \
		<< RESET << "@ slot(" << idx << ") into " << RED << "Discard pile." \
		<< GREEN << " slot(0) can now be used." << RESET << std::endl;


		_discarded_slot %= 50;
		this->_discarded_Materia[_discarded_slot] = this->_Materia_slot[idx];
		_discarded_slot += 1;
		this->_Materia_slot[idx] = NULL;
		return ;
	}
	//no empty slots Materia falls to ground.
	std::cout << "There's Nothing to unequip!" << std::endl;
}

//mc->use(0, *bob);
void 			Character::use(int idx, ICharacter& target)
{
	//no need to do (!target) as references are always valid once created.
	if (!(this->_Materia_slot[idx]))
	{
		if (!(this->_Materia_slot[idx]))
			std::cout << "There is nothing to use in this slot!" << std::endl;
		else
			std::cout << "something is very wrong.......check codes!" << std::endl;
		return;
	}
	this->_Materia_slot[idx]->use(target);
}













