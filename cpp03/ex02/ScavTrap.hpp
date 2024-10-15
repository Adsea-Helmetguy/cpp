/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:42:49 by mlow              #+#    #+#             */
/*   Updated: 2024/10/14 12:42:51 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>//std::string

// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class ScavTrap : public ClapTrap
{
private:

public:
	ScavTrap();//(init fixed point to 0) : _fixedpoint_value(0);
	ScavTrap(const std::string& name);
	ScavTrap(ScavTrap& copyname);//COPY CONSTRUCTOR
	ScavTrap&	operator=(const ScavTrap& other);
	~ScavTrap();
//
	void	attack(const std::string& target);
//	std::string		get_name(void);
//
//
//New function added!
	void	guardGate(void);
};

#endif
