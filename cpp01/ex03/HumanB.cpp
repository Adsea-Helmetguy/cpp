/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:34:45 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:34:46 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)//how to add Weapon?
{
	std::cout << "HumanB Created: " << name;
	std::cout << " WITHOUT A WEAPON!!!!?" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB " << this->_name << " destroyed....?" << std::endl;
}

void	HumanB::attack()
{
	std::cout << this->_name << " attacks with their " << \
		this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)//*weapon
{
	this->_weapon = &weapon;
}
