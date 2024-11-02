/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:49:49 by mlow              #+#    #+#             */
/*   Updated: 2024/10/21 11:50:02 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	std::cout << YELLOW << "Default constructor created here" << RESET << std::endl;
}

Weapon::Weapon(std::string name)
{
	this->_type = name;
	std::cout << "Weapon " << RED << name << RESET \
	<< " created here!" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << RED << this->_type << RESET << " (Weapon destroyed)" \
	<< std::endl;
}

const std::string&	Weapon::getType() const
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

