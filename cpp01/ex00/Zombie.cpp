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
Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "Zombie (" << this->name << ") created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie (" << this->name << ") destroyed" << std::endl;
//Zombies must be destroyed when you don’t need them anymore. The destructor must
//print a message with the name of the zombie for debugging purposes.
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}