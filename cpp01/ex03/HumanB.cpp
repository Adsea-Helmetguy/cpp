/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:07:00 by mlow              #+#    #+#             */
/*   Updated: 2024/10/21 12:07:01 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// : _name(name) are initializer list. They are all init here first!
HumanB::HumanB(std::string name) : _name(name)
{
	std::cout << "HumanB Created: " << GREEN << name << RESET;
	std::cout << " WITHOUT A WEAPON!!!!?" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << RED << this->_name << RESET << " DEconstructor destroyed here" \
	<< std::endl;
}

void	HumanB::attack()
{
	std::cout << GREEN << this->_name << RESET << " attacks with their " \
	<< GREEN << this->_weapon->getType() << RESET << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}
