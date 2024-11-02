/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:42:44 by mlow              #+#    #+#             */
/*   Updated: 2024/10/14 12:42:45 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_Name = "Default";
	this->_Hit_points = 100;
	this->_Energy_points = 50;
	this->_Attack_damage = 20;
    std::cout << RED << "ScavTrap Default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	this->_Name = name;
	this->_Hit_points = 100;
	this->_Energy_points = 50;
	this->_Attack_damage = 20;
	std::cout << RED << "ScavTrap constructor called for " << name << RESET << std::endl;
}

//COPY CONSTRUCTOR
ScavTrap::ScavTrap(ScavTrap& copyname) : ClapTrap(copyname)
{
	std::cout << RED << "ScavTrap COPY constructor called" << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this == &other)//need to add & because 'this' is a pointer
	{
		std::cout << "Don't Self-assign!!" << std::endl;
		return *this;// handle self-assignment
	}
	std::cout << "ScavTrap Copy assignment constructor called" << std::endl;
	this->_Name = other._Name;
	this->_Hit_points = other._Hit_points;
	this->_Energy_points = other._Energy_points;
	this->_Attack_damage = other._Attack_damage;
	std::cout << "ScavTrap" << GREEN << " EQUAL OPERATOR! " << RESET \
	"called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Deconstructor called for: " << this->_Name << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_Hit_points == 0 || this->_Energy_points == 0)
	{
		std::cout << RED << "ScavTrap " << this->_Name \
		<< " can't attack, no energy or hit points left!" << RESET << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->_Name << " attacks " << target \
	<< " causing " << this->_Attack_damage << " points of damage! " \
	<< GREEN << "\"SCAVTRAP PUNCH!!!!!\"" << RESET << std::endl;

	if (this->_Energy_points != 0)
		this->_Energy_points--;
	else
		this->_Energy_points = 0;
	std::cout << "ScavTrap " << this->_Name << " now has " \
	<< this->_Energy_points << " energy points left." << std::endl;
}

//
//
//
//New functions added
void	ScavTrap::guardGate()
{
	if (this->_Hit_points == 0 || this->_Energy_points == 0)
	{
		std::cout << "\nScavTrap " << GREEN << this->_Name << RED \
		<< " can't guardGate cause no energy. Wow.\n" << RESET << std::endl;
		return;
	}
	std::cout << "ScavTrap " << GREEN << this->_Name << BLUE \
	<< " is now in Gatekeeper mode!" << RESET << std::endl;
}
//
//
//
