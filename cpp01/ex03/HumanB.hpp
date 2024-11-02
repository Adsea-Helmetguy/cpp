/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:06:48 by mlow              #+#    #+#             */
/*   Updated: 2024/10/21 12:06:51 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

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

class HumanB
{
private:
	std::string	_name;
	Weapon		*_weapon;
//You can change _weapon to a pointer instead of a reference, 
//allowing it to be assigned later in the code 
// (such as in your setWeapon method).
/*
How a pointer works:
A pointer holds MEMORY ADDRESS rather than the object itself.
So it stores the location/address of the object where it is located.

******IMPT******
You are not required to initialize a pointer at the point of declaration.
 you can leave it uninitialized or set it to nullptr.
*/

public:
	HumanB(std::string name);
	~HumanB();

	//attack!
	void	attack();
	void	setWeapon(Weapon& weapon);
};
#endif

