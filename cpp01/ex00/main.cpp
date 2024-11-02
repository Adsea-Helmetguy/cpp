/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:33:42 by mlow              #+#    #+#             */
/*   Updated: 2024/05/26 17:40:20 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) 
{
	Zombie		*newZombie1;
	Zombie		*newZombie2;

	std::cout << YELLOW << "\n\nCreation of Constructors" << RESET << std::endl;
	std::cout << YELLOW << "assignment of Zombies and their names" \
	<< RESET << std::endl;
	newZombie1 = new Zombie();
	newZombie1->announce();
	newZombie2 = newZombie("Foo");
	randomChump("randomChump_Zombie");
	std::cout << YELLOW << "\n\nDeconstruction" << RESET << std::endl;
	delete newZombie1;
	delete newZombie2;
	return (0);

}
//https://cplusplus.com/reference/iomanip/
//https://cplusplus.com/reference/string/string/
//bascially new causes contact Constructor to activate,
//detele causes contact destructor to activate.
/*
If you dynamically allocate an object using new, 
 its destructor is called when the object is destroyed using delete.
 If you have a static object, its destructor is called 
 when the program terminates (if the program terminates normally).
*/
