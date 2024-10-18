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
/*
	{
		const	Animal* jack = new Dog();
		const	Animal* ik = new Cat();
		int	total_animals = 50;
		int	half_dogs = total_animals / 2;
		int	half_cats = total_animals - half_dogs;
		//const Animal** animal_array = new const Animal*[total_animals];// Array of pointers to Animal
		const Animal *animal_array[total_animals];// Array of pointers to Animal
		int	index = 0;

		std::cout << "total_animals: " << half_dogs << std::endl;
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
*/
	{
		//Checking Deep copy
		Dog* jack = new Dog("Happy Doggo");
		Dog* jack2 = new Dog("Want to eat Takocat doggo");
		//Animal* jack2 = new Dog("Want to eat Takocat doggo");

		std::cout << YELLOW <<"\n\nChecking jack's values before copy" << RESET << std::endl;
		std::cout << jack->getType() << std::endl;
		std::cout << jack2->getType() << std::endl;
	//
		std::cout << YELLOW <<"\n\nAdding ideas to Jack" << RESET << std::endl;
		jack->edit_brain(0, "Jack, I have a dream!!");
		jack2->edit_brain(0, "Jack number 2, I have a dream!!");
		jack->get_brain(0);
		jack->get_brain(1);//what happens to stack memory here?
		jack->get_brain(2);//what happens to stack memory here?
	//
		std::cout << YELLOW <<"\n\nCOPY assignment constructor called here" << RESET << std::endl;
		*jack2 = *jack;
		std::cout << YELLOW <<"\n\nChecking ideas in jack(s)" << RESET << std::endl;
		jack->get_brain(0);
		jack2->get_brain(0);
		/*
		Explanation
		jack2 = jack; is pointer assignment,
			 meaning jack2 will now point to the same memory 
			 location as jack, effectively discarding the original 
			 jack2 object and causing a shallow copy.

		*jack2 = *jack; is object assignment, which will invoke 
			the copy assignment operator, and this is what you want 
			to achieve deep copying.
		*/
	//
		std::cout << YELLOW <<"\n\nChecking jack's NEW values" << RESET << std::endl;
		std::cout << jack->getType() << std::endl;
		std::cout << jack2->getType() << std::endl;
	//
	//
		std::cout << YELLOW <<"\n\nDeconstructor called here" << RESET << std::endl;
		delete jack2;
		delete jack;//this should not seg fault!
	}
	return (0);
}
//ctrl+F first, then ALT+Enter if you want to replace stuff
