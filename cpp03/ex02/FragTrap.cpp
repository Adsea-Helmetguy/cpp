/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:42:44 by mlow              #+#    #+#             */
/*   Updated: 2024/10/14 16:14:31 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_Name = "Default";
	this->_Hit_points = 100;
	this->_Energy_points = 100;
	this->_Attack_damage = 30;
    std::cout << RED << "FragTrap Default constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	this->_Name = name;
	this->_Hit_points = 100;
	this->_Energy_points = 100;
	this->_Attack_damage = 30;
	std::cout << RED << "FragTrap constructor called for " << name << RESET << std::endl;
}

//COPY CONSTRUCTOR
FragTrap::FragTrap(FragTrap& copyname) : ClapTrap(copyname)
{
	std::cout << RED << "FragTrap COPY constructor called" << RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this == &other)//need to add & because 'this' is a pointer
	{
		std::cout << "Don't Self-assign!!" << std::endl;
        return *this;// handle self-assignment
	}
	std::cout << "FragTrap Copy assignment constructor called" << std::endl;
	this->_Name = other._Name;
	this->_Hit_points = other._Hit_points;
	this->_Energy_points = other._Energy_points;
	this->_Attack_damage = other._Attack_damage;
	std::cout << "FRAGTrap" << GREEN << " EQUAL OPERATOR! " << RESET \
	"called" << std::endl;
	return (*this);
}
//
//
//

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Deconstructor called for: " << this->_Name << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (this->_Hit_points == 0 || this->_Energy_points == 0)
	{
		std::cout << RED << "FragTrap " << this->_Name \
		<< " can't attack, no energy or hit points left!" << RESET << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->_Name << " attacks " << target \
	<< " causing " << this->_Attack_damage << " points of damage" << std::endl;

	if (this->_Energy_points != 0)
		this->_Energy_points--;
	else
		this->_Energy_points = 0;
	std::cout << "FragTrap " << this->_Name << " now has " \
	<< this->_Energy_points << " energy points left." << std::endl;
}

//
//
//
//New functions added
void	FragTrap::highFivesGuys(void)
{
	if (this->_Hit_points == 0 || this->_Energy_points == 0)
	{
		std::cout << "FragTrap" << this->_Name << RED \
		<< " can't High fives >w< cause no energy. Wow." << RESET << std::endl;
		return;
	}
	std::cout << "FRAGTRAP: "<< YELLOW << "High fives🙌 FragTrap~" \
	<< RESET << std::endl;
}
//
//
//
