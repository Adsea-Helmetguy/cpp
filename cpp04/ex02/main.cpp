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
		//The compiler expects that only 
		//const member functions will be called on these
		//BECAUSE of "const" Animal, when you declare an object as const
		std::cout << YELLOW << "Calling Constructor functions here" << RESET << std::endl;
		const	Animal* meta = new Animal();//Animal constructor called
		const	Animal* j = new Dog();//Animal + Dog Constructor called
		const	Animal* i = new Cat();//Animal + Cat Constructor called

		std::cout << YELLOW << "\nUsing getType function" << RESET << std::endl;
		std::cout << "j's getType value: " << j->getType() << " " << std::endl;
		std::cout << "i's getType value: " << i->getType() << " " << std::endl;
		std::cout << YELLOW << "\nUsing makesound() function here" << RESET << std::endl;
		i->makeSound();//will output the cat sound!
		j->makeSound();//will output the Dog sound!
		meta->makeSound();

		std::cout << YELLOW << "\nCalling delete here (cause \"New\" Allocation)" \
		<< RESET << std::endl;
		delete meta;
		delete j;
		delete i;
	}

	{
		std::cout << YELLOW << "\n\n------------\n\n\n\nCalling Constructor functions here" \
		<< RESET << std::endl;
		std::cout << YELLOW << "From PDF but exchanged with WrongAnimal and WrongCat" \
		<< RESET << std::endl;
		const	WrongAnimal* meta = new WrongAnimal();
		const	WrongAnimal* j = new WrongCat();

		std::cout << YELLOW << "\nUsing getType function" << RESET << std::endl;
		std::cout << "j's getType value: " << j->getType() << " " << std::endl;
		std::cout << YELLOW << "\nUsing makesound() function here" << RESET << std::endl;
		j->makeSound();//will output the Dog sound!
		meta->makeSound();

		std::cout << YELLOW << "\nCalling delete here (cause \"New\" Allocation)" \
		<< RESET << std::endl;
		delete meta;
		delete j;
	}
	//
	/*
	{
		const Animal* jack = new Dog();
		const Animal* ik = new Cat();
		int	total_animals = 50;
		int half_dogs = total_animals / 2;
		int half_cats = total_animals - half_dogs;
		const Animal** animal_array = new const Animal*[total_animals];// Array of pointers to Animal
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
		for (int i = 0; i < total_animals; i++)
		{
			delete animal_array[i]; // Properly deletes each animal (virtual destructor calls Cat/Dog then Animal)
		}
		delete[] animal_array;

		delete jack;//should not create a leak
		delete ik;
	}
	*/
	return (0);
}
//ctrl+F first, then ALT+Enter if you want to replace stuff
