/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:34:50 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:34:50 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUAMNB_HPP
#define HUAMNB_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>//std::string
# include <cctype>
# include <iomanip> //for std::setw
# include <sstream>
# include <new>


// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class HumanB
{
public:
	HumanB(std::string name);
	~HumanB();

	void	attack();
	void	setWeapon(Weapon& weapon);

private:
	std::string	_name;
	Weapon		*_weapon;
};

#endif
