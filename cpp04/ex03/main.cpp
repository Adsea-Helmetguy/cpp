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
#include "MateriaSource.hpp"

//clear && make re && clear && valgrind ./amateria
int main(void)
{
	{
		std::cout << BLUE << "\n\n1)" \
		<< "----- PDF Test: -----" << RESET << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		
		std::cout << YELLOW << "\n\n----- RESULT -----" << RESET << std::endl;
		me->use(0, *bob);
		me->use(1, *bob);
		std::cout << YELLOW << "----- RESULT -----\n\n" << RESET << std::endl;

		std::cout << YELLOW << "\n----- Destructor called here -----" << RESET << std::endl;
		delete bob;
		delete me;
		delete src;
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" <<  std::endl;
	}























	{
		std::cout << BLUE << "2)" \
		<< "----- Create/LearnMateria test: -----" << RESET << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("cure");
		//me->equip(tmp);
		delete tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		ICharacter* v1 = new Character("victim1");
		me->use(0, *v1);
		me->use(1, *v1);
		std::cout << YELLOW <<"\nDestructor called here" << RESET << std::endl;
		//delete tmp;//if you delete tmp, there is nothing else 'me' or v1' left
		delete me;
		delete v1;
		delete src;
		std::cout << "\n\n" <<  std::endl;
	}





















	{
		std::cout << BLUE << "3)" \
		<< "----- Testing if \"USE\" works: -----" << std::endl;
		ICharacter* me = new Character("Doggo");
		AMateria *Ice1 = new Ice();
	 	AMateria *Cure1 = new Cure();
		std::cout << "Ice1  type: " << Ice1->getType() << std::endl;
	 	std::cout << "Cure1 type: " << Cure1->getType() << std::endl;
	 	ICharacter* yx = new Character("Yun Xuan");
	 	yx->equip(Cure1);
	 	yx->equip(Ice1);
	 	for (int i = 0; i < 10; i++)
	 	{
	 		yx->use(1, *me);
	 		yx->use(0, *me);
	 	}
	 	std::cout << YELLOW << "\n----- Destructor called here -----" << RESET << std::endl;
	 	delete yx;
	 	delete me;
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" <<  std::endl;
	}

















	{
		std::cout << BLUE << "4)" \
		<< "----- Personal Tests -----" << RESET << std::endl;
		std::cout << YELLOW << "----- Constructor -----" << RESET << std::endl;
		AMateria *Ice1 = new Ice();
		AMateria *Cure1 = new Cure();
		std::cout << BLUE << "\n----- Test every function -----" << RESET << std::endl;
		std::cout << "Ice1  type: " << Ice1->getType() << std::endl;
		std::cout << "Cure1 type: " << Cure1->getType() << std::endl;
		
		
		
		
		
		std::cout << YELLOW << "==Creating new Character==" << RESET << std::endl;
		ICharacter* mc = new Character("\"Curry man\"");
		std::cout << "mc's name: " << mc->getName() << std::endl;
		std::cout << YELLOW << "\n==============Equip or Unequip==============" << RESET << std::endl;
		mc->equip(Cure1);// or mc->equip(Cure1->clone())
		mc->equip(Ice1);//DON'T FORGET TO TEST WITH ICE TOO
		mc->equip(Cure1->clone());
		mc->equip(Cure1->clone());
		mc->equip(Cure1->clone());
		mc->equip(Cure1->clone());
		mc->equip(Cure1->clone());
		std::cout << YELLOW << "===========================================" << RESET << std::endl;
		std::cout << YELLOW << "\n\n\n==Testing function \"use\"==" << RESET << std::endl;
		ICharacter* bob = new Character("bob the Curry lover");
		mc->use(0, *bob);
		Character *bert = new Character("Bert");
		AMateria *temp_materia = new Cure();
		bert->equip(temp_materia);
		//this calls the copy Constructor!? HOWWWW!
		//Character(*bert) "Char("something here")"<- copy constructor
		Character *casper = new Character(*bert);
		
		
		
		casper->use(0, *bert);
		casper->use(0, *bert);
		casper->use(1, *bert);//should not do anything
		casper->use(2, *bert);//should not do anything
		casper->use(3, *bert);//should not do anything
		Character *dobby = new Character("Dobby");
		*dobby = *bert;
		//dobby = bert;//wrong cause this means address = address.
		dobby->use(0, *bert);
		dobby->use(0, *bert);
		dobby->use(1, *bert);
		dobby->use(2, *bert);
		/*
		Remember back in animal for ex01:
			Cat *a = new Cat();
			Cat *b(a);
			delete a;
			delete b;
			return 0;
		we cannot do Character *dobby(bert); because that's copying pointer,
		we are copying the address that means if we do this, all we need
		to delete is bert since dobby POINTS to bert.
		*/
		//Now unequip
		mc->unequip(0);//mc->unequip(idx); int idx is the slot number
		mc->use(0, *bert);//discard pile = 0
		std::cout << YELLOW << "\n----- Destructor called here -----" << RESET << std::endl;
		delete dobby;
		delete casper;
		delete bert;
		delete bob;
		delete mc;
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" <<  std::endl;
	}

















	{
		std::cout << BLUE << "5)" \
		<< "----- Overfilling Character with Materias: -----\n" << std::endl;
		IMateriaSource* materia_source = new MateriaSource();
		materia_source->learnMateria(new Cure());
		ICharacter* alf = new Character("Alf");
		for (int i = 0; i < 120; i++)
		{
			alf->equip(materia_source->createMateria("cure"));
		}
		std::cout << YELLOW \
		<< "\n----- invalid index of Materia & discard slots-----\n" << std::endl;
		std::cout << "check slot[0-4]: " << RESET << std::endl;
		alf->use(-10, *alf);
		alf->use(-1, *alf);
		alf->use(0, *alf);
		alf->unequip(0);
		//alf->use(0, *alf);
		alf->use(2, *alf);
		alf->use(4, *alf);
		std::cout << YELLOW << "\n----- Destructor called here -----" << RESET << std::endl;
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
		std::cout << YELLOW << "\n----- Destructor called here -----" << RESET << std::endl;
		delete ms;
		delete bert;
		delete casper;
		delete dobby;
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" <<  std::endl;
	}

















	{
		std::cout << BLUE << "6)" \
		<< "----- checking if ice != cure: -----" << std::endl;
		AMateria	*ice = new Ice();
		AMateria	*ice2 = new Ice();
		AMateria	*cure = new Cure();

		*ice = *cure;
		*ice = *ice;
		*ice = *ice2;
		std::cout << "Ice _type = " << ice->getType() <<std::endl;
		std::cout << "Cure _type = " << cure->getType() <<std::endl;
		std::cout << "\n" <<  std::endl;
		std::cout << YELLOW <<"\nDestructor called here" << RESET << std::endl;
		delete ice;
		delete ice2;
		delete cure;
	}
	return (0);
}
