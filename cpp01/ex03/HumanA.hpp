/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:34:38 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:34:39 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

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

class HumanA
{
public:
	HumanA(std::string name, Weapon& w);
	~HumanA();

	void	attack();

private:
	std::string	_name;
	Weapon&		_weapon;
};

#endif
