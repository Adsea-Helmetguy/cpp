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

/*
The use(ICharacter&) member function will display:
• Ice: "* shoots an ice bolt at <name> *"
• Cure: "* heals <name>’s wounds *"

<name> is the name of the Character passed as parameter. Don’t print the angle
brackets (< and >).
*/
//void	Cure::use(ICharacter& target)
/*
	public:
		Character();
		Character(std::string const &type);
		Character(const AMateria &type);
		~Character();//ICharacter virtual destructor
*/
Character::Character() : _name("From ICharacter")
{
	for (int i = 0; i < 4; i++)
	{
		_Materia_slots[i] = NULL;
	}
	std::cout << "Character: " << this->_name \
	<< " Created @ Default constructor" << std::endl;
}

Character::Character(const std::string &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
	{
		this->_Materia_slots[i] = NULL;
	}
	std::cout << "Character: " << this->_name << " Created" << std::endl;
}

//COPY CONSTRUCTOR
Character::Character(const Character &copy)
{
	this->_name = copy.getName();
	for (int i = 0; i < 4; i++)
	{
		this->_Materia_slots[i] = NULL;
	}
	for (int i = 0; i < 4; i++)
	{
		if (copy._Materia_slots[i])
			this->_Materia_slots[i] = copy._Materia_slots[i];
	}
	std::cout << "Character COPY CONSTRUCTOR " << this->_name << " Called!!" << std::endl;
}

Character::~Character()
{
	std::cout << "Character: " << this->_name \
	<< " Destruction!!!!!" << std::endl;
}




//
//
//
//
//Functions to code!
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
		if (!(this->_Materia_slots[i]))
		{
			this->_Materia_slots[i] = m;
			std::cout << this->getName() << " equipped with: \"" \
			GREEN << m->getType() << RESET << "\" @ slot(" << i << ")" << std::endl;
			return ;
		}
	}
	std::cout << "ALL the slots are full, unable to add: " \
	<< m->getType() << " to any slot." << std::endl;
}
/*
void 			Character::unequip(int idx)
{
}


void 			Character::use(int idx, ICharacter& target)
{
}
*/



/*
std::string const & getName() const;
void equip(AMateria* m);
void unequip(int idx);
void use(int idx, ICharacter& target);
*/













