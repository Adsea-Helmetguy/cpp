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

int	main(void)
{
	// Dog *a = new Dog();
	// Dog *b = new Dog(*a);
	// delete a;
	// delete b;
	// return 0;
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
	return (0);
}
/*
To ensure you understood how it works, implement a WrongCat class that inherits
from a WrongAnimal class. If you replace the Animal and the Cat by the wrong ones
in the code above, the WrongCat should output the WrongAnimal sound
*/
//ctrl+F first, then ALT+Enter if you want to replace stuff
