/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:03:33 by mlow              #+#    #+#             */
/*   Updated: 2024/05/26 18:03:45 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//https://elearning.intra.42.fr/notions/piscine-c-d00-c-basics/subnotions

Zombie::Zombie()
{
	this->name = "Zombie in birthpod";
	std::cout << RED << this->name << RESET << " created in constructor" << std::endl;
}

/*
Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "Zombie (" << this->name << ") created" << std::endl;
}
*/

Zombie::~Zombie()
{
	std::cout << RED <<  "Zombie (" << this->name << ") destroyed" << RESET << std::endl;
//Zombies must be destroyed when you don’t need them anymore. The destructor must
//print a message with the name of the zombie for debugging purposes.
}

void	Zombie::announce(void)
{
	std::cout << RED << this->name << RESET << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

//function to init the name of zombie
void	Zombie::name_init(std::string name)
{
	this->name = name;
	std::cout << "Zombie (" << GREEN << this->name << RESET << ") created" << std::endl;
	this->announce();
}
