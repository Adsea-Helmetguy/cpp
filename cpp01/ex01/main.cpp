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
	int		total_zombies;

	total_zombies = 5;
	newZombie1 = zombieHorde(total_zombies, "zombiehorde");
	delete[] newZombie1;
	return (0);
}
/*
Zombie*	zombieHorde(int N, std::string name)
{
	Zombie		*newZombie_creation;

	newZombie_creation = new Zombie[N];
	for (int loop = 0; loop < N; loop++)
	{
		newZombie_creation[loop] = Zombie(name);
	}
	return (newZombie_creation);
}

int	main(void) 
{
	Zombie		*newZombie1;
	std::string	name = "";
	int		total_zombies;

	total_zombies = 5;
	newZombie1 = zombieHorde(total_zombies, "zombiehorde");
	delete[] newZombie1;
	return (0);
}
*/
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
