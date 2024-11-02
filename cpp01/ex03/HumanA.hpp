/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:06:41 by mlow              #+#    #+#             */
/*   Updated: 2024/10/21 12:06:45 by mlow             ###   ########.fr       */
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

# define RESET		"\033[0m"
# define RED		"\033[31m"//Red
# define GREEN		"\033[32m"//Green
# define YELLOW		"\033[33m"//Yellow
# define BLUE		"\033[34m"//Blue

// ************************************************************************** //
//                                  Class                                     //
// ************************************************************************** //

class HumanA
{
private:
	std::string	_name;
	Weapon&		_weapon;

public:
	HumanA(std::string name, Weapon &w);
	~HumanA();

	void	attack();
};
#endif

