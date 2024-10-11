/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:35:02 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:35:04 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

//https://elearning.intra.42.fr/notions/piscine-c-d00-c-basics/subnotions

Weapon::Weapon(std::string name)
{
	std::cout << "Weapon " << name << " created" << std::endl;
	this->_type = name;
}

Weapon::~Weapon()
{
	std::cout << "(Weapon destroyed)" << std::endl;
}

//returns CONST REFERENCE "const &"
const std::string &Weapon::getType(void) const
{
	return (this->_type);
}

void	Weapon::setType(const std::string &type)
{
	this->_type = type;
}
