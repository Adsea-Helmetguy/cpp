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

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int	main(void)
{
	{
		std::cout << YELLOW << "Creating Constructor" << RESET << std::endl;
		const	Animal* jack = new Dog();
		const	Animal* ik = new Cat();
		int	total_animals = 50;
		int	half_dogs = total_animals / 2;
		int	half_cats = total_animals - half_dogs;
		//const Animal** animal_array = new const Animal*[total_animals];// Array of pointers to Animal
		const Animal *animal_array[total_animals];// Array of pointers to Animal
		int	index = 0;

		std::cout << YELLOW << "values of dogs & cats" << RESET << std::endl;
		std::cout << "total_animals: " << total_animals << std::endl;
		std::cout << "total_dogs: " << half_dogs << std::endl;
		std::cout << "total_cats: " << half_cats << std::endl;
		std::cout << YELLOW << "\n\nCreating Dogs and Cats!" << RESET << std::endl;
		while(index < half_dogs)// 0 to 24
		{
			animal_array[index] = new Dog();
			std::cout << "Filled space for Dog Animal:" << RED \
			<< "[" << index  << "]" << RESET << std::endl;
			index++; //by end of loop your index will 25
		}
		std::cout << "\n\n----------\n" << std::endl;
		while(index < (half_dogs + half_cats)) //25 to 49
		{
			animal_array[index] = new Cat();
			std::cout << "Filled space for Cat Animal:" << RED \
			<< "[" << index  << "]" << RESET << std::endl;
			index++; //by end of loop your index will 50
		}
		std::cout << "\n\n\n\n\n----------" << std::endl;
		std::cout << YELLOW << "Deconstructor happening here, BYE BYE DOGS AND CATS" \
		<< RESET << std::endl;
		// Properly deletes each animal (virtual destructor calls Cat/Dog then Animal)
		for (int i = 0; i < total_animals; i++)
			delete animal_array[i];
		//delete[] animal_array;
		delete jack;//should not create a leak
		delete ik;
	}

	{
		//Checking Deep copy
		std::cout << YELLOW << "\n\n\n\n\n\n\n\n\nTest 2nd, DEEP COPY " << \
		"\n------------------------------------------" << RESET << std::endl;
		std::cout << YELLOW << "Creating Constructor" << RESET << std::endl;
		Cat* jacky = new Cat("Happy Doggo");
		Cat* jack2 = new Cat("Want to eat Takocat Doggo");
		//Animal* jack2 = new Dog("Want to eat Takocat doggo");

		std::cout << YELLOW <<"\n\nChecking jack's values before copy" << RESET << std::endl;
		std::cout << GREEN << jacky->getType() << RESET << std::endl;
		std::cout << GREEN << jack2->getType() << RESET << std::endl;
	//
		std::cout << YELLOW <<"\n\nAdding ideas to Jack(s)" << RESET << std::endl;
		jacky->edit_brain(0, "Jack oh boy, I have a dream!!");
		jacky->edit_brain(1, "Jack oh boy, I have a dream2!!");
		jacky->edit_brain(2, "Jack oh boy, I have a dream3!!");
		jacky->edit_brain(3, "Jack oh boy, I have a dream4!!");
		jack2->edit_brain(0, "Jack number 2, I have a dream!!");
		jack2->edit_brain(1, "Jack number 2, I have a dream2!!");
		jack2->edit_brain(2, "Jack number 2, I have a dream3!!");
		jack2->edit_brain(3, "Jack number 2, I have a dream4!!");
		std::cout << YELLOW <<"Checking ideas inside jack(s)" << RESET << std::endl;
		jacky->get_brain(0);
		jacky->get_brain(1);
		jacky->get_brain(2);
		jacky->get_brain(3);
		jack2->get_brain(0);
		jack2->get_brain(1);
		jack2->get_brain(2);
		jack2->get_brain(3);
		//jack->get_brain(1);//what happens to stack memory here?
		//jack->get_brain(2);//what happens to stack memory here?
	//
		std::cout << YELLOW <<"\n\nCOPY assignment constructor called here" << RESET << std::endl;
		*jack2 = *jacky;
	//
		std::cout << YELLOW <<"\n\nChecking ideas in jack(s)" << RESET << std::endl;
		jacky->get_brain(0);
		jacky->get_brain(1);
		jacky->get_brain(2);
		jacky->get_brain(3);
		jack2->get_brain(0);
		jack2->get_brain(1);
		jack2->get_brain(2);
		jack2->get_brain(3);
		//Explanation
		//jack2 = jack; is pointer assignment,
		//	 meaning jack2 will now point to the same memory 
		//	 location as jack, effectively discarding the original 
		//	 jack2 object and causing a shallow copy.
		//	 Basically you are copying the memory address of jack.
//
		// *jack2 = *jack; is object assignment, which will invoke 
		//	the copy assignment operator, and this is what you want 
		//	to achieve deep copying.
		//	Basically, you are copying the items of the jack.
	//
		std::cout << YELLOW <<"\n\nChecking jack's NEW values" << RESET << std::endl;
		std::cout << jacky->getType() << std::endl;
		std::cout << jack2->getType() << std::endl;
	//
	//
	//	std::cout << YELLOW <<"\n\nDeconstructor called here" << RESET << std::endl;
	//	delete jack2;
	//	delete jacky;//this should not seg fault!
	}

	std::cout << YELLOW <<"\n--------------\nTesting Animal" << RESET << std::endl;
	const	Animal* ika = new Animal();
	std::cout << GREEN << ika->getType() << RESET << std::endl;
	ika->makeSound();
	delete ika;
	std::cout << YELLOW <<"--------------\n" << RESET << std::endl;
	return (0);
}
//ctrl+F first, then ALT+Enter if you want to replace stuff
