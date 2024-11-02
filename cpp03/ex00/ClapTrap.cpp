/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:34:28 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:34:30 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _Name("Default"), _Hit_points(10), _Energy_points(10), _Attack_damage(0)
{
	std::cout << "ClapTrap" << GREEN << " (Default constructor) " \
	<< RESET << "called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: _Name(name + ".copy"), _Hit_points(10), _Energy_points(10), _Attack_damage(0)
{
	std::cout << "ClapTrap with "<< GREEN << "(std::string& name constructor)" \
	<< RESET << "called" << std::endl;
}

//COPY CONSTRUCTOR
//COPY CONSTRUCTOR
ClapTrap::ClapTrap(ClapTrap& copyname)
	: _Name(copyname._Name), _Hit_points(copyname._Hit_points), \
	_Energy_points(copyname._Energy_points), _Attack_damage(copyname._Attack_damage)
{
	std::cout << "ClapTrap " << GREEN << "(COPY constructor) " << RESET << "called" << std::endl;
}

//why do we need a operator=()?
//OBJECTIVE AS WELL!
//std::cout << "ClapTrap Copy assignment constructor called\n";
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this == &other)//need to add & because 'this' is a pointer
	{
		std::cout << "Don't Self-assign!!" << std::endl;
		return *this; // handle self-assignment
	}
	this->_Name = other._Name;
	this->_Hit_points = other._Hit_points;
	this->_Energy_points = other._Energy_points;
	this->_Attack_damage = other._Attack_damage;
	std::cout << "ClapTrap" << GREEN << " EQUAL OPERATOR! " << RESET \
	"called" << std::endl;
	return (*this);
}
//
//
//

ClapTrap::~ClapTrap()
{
	std::cout << RED << "ClapTrap Deconstructor called" << RESET << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_Hit_points == 0 || this->_Energy_points == 0)
	{
		std::cout << "ClapTrap " << this->_Name \
		<< " can't attack, no energy or hit points left!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_Name << " attacks " << target \
	<< " causing " << GREEN << this->_Attack_damage << RESET \
	<< " points of damage" << std::endl;
//
//
	if (this->_Energy_points != 0)
		this->_Energy_points--;
	else
		this->_Energy_points = 0;
	std::cout << "ClapTrap " << this->_Name << " now has " << GREEN \
	<< this->_Energy_points << RESET << " energy points left." << std::endl;
//
//
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_Hit_points == 0)
	{
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << "|" << RED << " STAPH DUDE HE IS ALREADY DEDDDDDD!! >w<" << RESET \
		<< " |" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
		return;
	}
//
//
	if (amount > this->_Hit_points)
		this->_Hit_points = 0;
	else
		this->_Hit_points -= amount;
//
//
	std::cout << "ClapTrap " << this->_Name << " lost: " << RED << amount \
	<< RESET << " Hit_points!\n" <<"_Hit_points left: " << GREEN \
	<< this->_Hit_points << RESET << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_Hit_points == 0 || this->_Energy_points == 0)
	{
		std::cout << "ClapTrap " << this->_Name \
		<< " can't Repair, no energy or hit points left!" << std::endl;
		return;
	}
//
//
	this->_Hit_points += amount;
	std::cout << "ClapTrap " << this->_Name << " repairs itself for: " << amount \
	<< " _Hit_points left: " << this->_Hit_points << std::endl;
//
//
	if (this->_Energy_points != 0)
		this->_Energy_points--;
	else
		this->_Energy_points = 0;
	std::cout << "ClapTrap " << this->_Name << " now has " \
	<< this->_Energy_points << " energy points left." << std::endl;
//
//
}

unsigned int	ClapTrap::get_hit_points(void)
{
	return(this->_Hit_points);
}

unsigned int	ClapTrap::get_energy_points(void)
{
	return(this->_Energy_points);
}










