#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>//std::string
# include <cmath>

// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class ScavTrap : public ClapTrap
{
private:
	std::string			_Name;
	unsigned int		_Hit_points;
	unsigned int		_Energy_points;
	unsigned int		_Attack_damage;
public:
	ScavTrap();//(init fixed point to 0) : _fixedpoint_value(0);
	ScavTrap(const std::string& name);
	ScavTrap(ScavTrap& copyname);//COPY CONSTRUCTOR
	ScavTrap&	operator=(const ScavTrap& other);
	~ScavTrap();
//
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	unsigned int	get_hit_points(void);
	unsigned int	get_energy_points(void);
//
//New function added!
	void	guardGate(void);
//
};

#endif