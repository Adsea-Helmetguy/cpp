#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : _Name("Default"), _Hit_points(100), _Energy_points(50), _Attack_damage(20)
{
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name), \
	_Name(name), _Hit_points(100), _Energy_points(50), _Attack_damage(0)
{
	std::cout << "ScavTrap constructor called for " << name << std::endl;
}

//COPY CONSTRUCTOR
ScavTrap::ScavTrap(ScavTrap& copyname) : ClapTrap(copyname), \
	_Name(copyname._Name), _Hit_points(10), _Energy_points(10), _Attack_damage(20)
{
	std::cout << "ScavTrap COPY constructor called" << std::endl;
}

//why do we need a operator=()?
//OBJECTIVE AS WELL!
//std::cout << "ClapTrap Copy assignment constructor called\n";
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this == &other)//need to add & because 'this' is a pointer
	{
		std::cout << "Don't Self-assign!!" << std::endl;
        return *this; // handle self-assignment
	}
	std::cout << "ScavTrap Copy assignment constructor called" << std::endl;
	this->_Name = other._Name;
	this->_Hit_points = other._Hit_points;
	this->_Energy_points = other._Energy_points;
	this->_Attack_damage = other._Attack_damage;
	return (*this);
}
//
//
//

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Deconstructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_Hit_points == 0 || this->_Energy_points == 0)
	{
		std::cout << "ScavTrap " << this->_Name \
		<< " can't attack, no energy or hit points left!" << std::endl;
		return;
	}
	std::cout << "ScavTrap" << this->_Name << " attacks " << target \
	<< " causing " << this->_Attack_damage << " points of damage" << std::endl;
//
//
	if (this->_Energy_points != 0)
		this->_Energy_points--;
	else
		this->_Energy_points = 0;
	std::cout << "ScavTrap " << this->_Name << " now has " \
	<< this->_Energy_points << " energy points left." << std::endl;
//
//
}

//
//
//New function added
void	ScavTrap::guardGate()
{
	std::cout << RED << "ScavTrap " << this->_Name \
	<< " is now in Gatekeeper mode!" << RESET << std::endl;
}
