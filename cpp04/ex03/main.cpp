/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:34:13 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:34:18 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

//clear && make re && clear && valgrind ./amateria
int main(void)
{
	{
		std::cout << YELLOW << "\n\n----- Personal Tests -----" << RESET << std::endl;
		std::cout << BLUE << "----- Constructor -----" << RESET << std::endl;
		AMateria *Ice1 = new Ice();
		AMateria *Cure1 = new Cure();
		std::cout << BLUE << "\n----- Test every function -----" << RESET << std::endl;
		std::cout << "Ice1  type: " << Ice1->getType() << std::endl;
		std::cout << "Cure1 type: " << Cure1->getType() << std::endl;
		
		
		
		
		
		//start here marcus
		std::cout << YELLOW << "==Creating new Character==" << RESET << std::endl;
		ICharacter* mc = new Character("\"Curry man\"");
		std::cout << "mc's name: " << mc->getName() << std::endl;
		mc->equip(Cure1);
		//mc->use
		
		
		
		
		
		
		std::cout << " " << std::endl;
		std::cout << BLUE <<"\n----- Destructor called here -----" << RESET << std::endl;
		delete Ice1;
		delete Cure1;
		return (0);
	}

//	{
//		std::cout << BLUE << "----- PDF Test: -----\n" << std::endl;
//
//		IMateriaSource* src = new MateriaSource();
//		src->learnMateria(new Ice());
//		src->learnMateria(new Cure());
//		ICharacter* me = new Character("me");
//		AMateria* tmp;
//		tmp = src->createMateria("ice");
//		me->equip(tmp);
//		tmp = src->createMateria("cure");
//		me->equip(tmp);
//		ICharacter* bob = new Character("bob");
//		me->use(0, *bob);
//		me->use(1, *bob);
//		std::cout << YELLOW <<"\n\nDestructor called here" << RESET << std::endl;
//		delete bob;
//		delete me;
//		delete src;
//	}
//
/*
	{
		std::cout << GREEN \
		<< "\n----- Overfilling Character with Materias: -----\n" << std::endl

		IMateriaSource* materia_source = new MateriaSource();
		materia_source->learnMateria(new Cure());
		ICharacter* alf = new Character("Alf");
		for (int i = 0; i < 56; i++)
		{
			alf->equip(materia_source->createMateria("cure"));
		}
		delete materia_source;
		delete alf;

		std::cout << YELLOW \
		<< "\n----- Copy costructor and assignment operator shinenigans -----\n" << std::endl;

		IMateriaSource* ms = new MateriaSource();
		AMateria *cure = new Cure();
		ms->learnMateria(cure);
		AMateria* temp_materia = ms->createMateria("cure");
		Character* bert = new Character("Bert");
		bert->equip(temp_materia);
		Character *casper = new Character(*bert);
		casper->use(0, *bert);
		casper->use(0, *bert);
		Character *dobby = new Character("Dobby");
		*dobby = *bert;
		dobby->use(0, *bert);
		std::cout << YELLOW <<"\n\nDestructor called here" << RESET << std::endl;
		delete ms;
		delete bert;
		delete casper;
		delete dobby;
	}
*/
}
