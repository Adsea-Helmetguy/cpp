/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:18:17 by mlow              #+#    #+#             */
/*   Updated: 2024/11/05 19:18:18 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

/*
Copies the Materia passed as a parameter and store 
it in memory so it can be cloned later. Like the Character,
the MateriaSource can know at most 4 Materias.
They are not necessarily unique.
*/

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		this->_Materia_slot[i] = NULL;
	}
	std::cout << "MateriaSource Default Constructor called!!" << std::endl;
}

//COPY CONSTRUCTOR
MateriaSource::MateriaSource(const MateriaSource &copy)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_Materia_slot[i])
			delete (this->_Materia_slot[i]);
		this->_Materia_slot[i] = NULL;
		if (copy._Materia_slot[i])
			this->_Materia_slot[i] = copy._Materia_slot[i]->clone();
	}
	std::cout << "MateriaSource COPY Constructor called!!" << std::endl;
}

//COPY OPERATOR=()
MateriaSource	&MateriaSource::operator=(const MateriaSource &copy)
{
	if (this == &copy)
	{
		std::cout << "DON't SELF ASSIGN" << std::endl;
		return (*this);
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_Materia_slot[i])
			delete (this->_Materia_slot[i]);
		this->_Materia_slot[i] = NULL;
		if (copy._Materia_slot[i])
			this->_Materia_slot[i] = copy._Materia_slot[i]->clone();
	}
	std::cout << "MateriaSource operator=() " \
	<< "Called!!" << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_Materia_slot[i])
			delete (this->_Materia_slot[i]);
		this->_Materia_slot[i] = NULL;
	}
	std::cout << "MateriaSource Destructor called!!" << std::endl;
}

//Copies THE Materia (only one at the time it seems)
void	MateriaSource::learnMateria(AMateria* copy)
{
	//learns at most 4 Materias
	std::cout << GREEN << "learnMateria called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (!(this->_Materia_slot[i]))
		{
			this->_Materia_slot[i] = copy;
			//we don't need to copy the type, just print out the learnt.
			std::cout << BLUE << "----------------------------------" \
			<< RESET << std::endl;
			std::cout << "Materia " << BLUE << copy->getType() \
			<< RESET << " learned\n";
			std::cout << BLUE << "----------------------------------" \
			<< RESET << std::endl;
			return ;
		}
	}
	std::cout << "Can't learn more than 4 Materia" << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	AMateria	*replacement;

	std::cout << GREEN << "createMateria called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_Materia_slot[i])
		{
			if (this->_Materia_slot[i]->getType() == type)
			{
				replacement = this->_Materia_slot[i]->clone();
				return (replacement);
			}
		}
	}
	std::cout << RED << "The Materia does't Exist YOU FOOL!!!" \
	<< RESET << std::endl; 
	return (0);
}




