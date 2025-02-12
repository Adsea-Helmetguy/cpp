/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
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

# define RESET		"\033[0m"
# define RED		"\033[31m"//Red
# define GREEN		"\033[32m"//Green
# define YELLOW		"\033[33m"//Yellow
# define BLUE		"\033[34m"//Blue

// ************************************************************************** //
//                                    Class                                   //
// ************************************************************************** //

class ClapTrap
{
protected:
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
	unsigned int	get_attack_damage(void);
//
//
	std::string		get_name(void);

};

#endif
