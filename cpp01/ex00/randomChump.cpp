/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:55:55 by mlow              #+#    #+#             */
/*   Updated: 2024/08/15 16:55:56 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
//this method also works
void	randomChump(std::string name)
{
	Zombie*		newZombie_creating;

	newZombie_creating = new Zombie(name);
	newZombie_creating->announce();
	std::cout << YELLOW << "\n\nRandomChump doesn't return zombie" << RESET << std::endl;
	delete newZombie_creating;
}
*/
void	randomChump(std::string name)
{
	Zombie		newZombie_creating(name);

	newZombie_creating.announce();
//
//
	std::cout << YELLOW << "\nRandomChump doesn't return zombie\n" \
	<< "Self destruction from deconstruction after stack memory\n" \
	"since no heap memory (using new Zombie) were done here" \
	<< RESET << std::endl;
}

/*
Now, what is the actual point of the exercise? 
You have to determine in what case
it’s better to allocate the zombies on the stack or heap
*/

