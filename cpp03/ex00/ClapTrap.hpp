/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:35:16 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:35:18 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>
# include <string>//std::string
# include <cmath>

// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class ClapTrap
{
private:

	std::string			_Name;
	unsigned int		_Hit_points;
	unsigned int		_Energy_points;
	unsigned int		_Attack_damage;
public:
	ClapTrap();//(init fixed point to 0) : _fixedpoint_value(0);
	ClapTrap(const std::string& name);
	ClapTrap(ClapTrap& copyname);//COPY CONSTRUCTOR
	ClapTrap&	operator=(const ClapTrap& other);
	~ClapTrap();
//
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
//
//Other created member functions
	unsigned int	get_hit_points(void);
	unsigned int	get_energy_points(void);
//
//
};

#endif
