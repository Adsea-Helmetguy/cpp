/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:06:55 by mlow              #+#    #+#             */
/*   Updated: 2024/10/21 12:06:56 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& w) : _name(name), _weapon(w)//how to add Weapon?
{
	std::cout << "HumanA Created: " << GREEN << name << RESET;
	std::cout << " WITH A WEAPON: " << GREEN << w.getType() << RESET << std::endl;
}

/*
This also works if your HumanA.hpp file has this:
private:
	std::string	_name;
	Weapon		*_weapon; //pointer instead of '&' reference.

Now replace the above with these:
HumanA::HumanA(std::string name, Weapon& w) : _name(name)//, _weapon(w)//how to add Weapon?
{
	this->_weapon = &w;
	std::cout << "HumanA Created: " << GREEN << name << RESET;
	std::cout << " WITH A WEAPON: " << GREEN << w.getType() << RESET << std::endl;
}

The reason why the *_weapon works is because when you do '&', the _weapon MUST
be init above, however with the '*', it does not need to be init at constructor
even through its the first thing the program will encounter.

In this exercise However, its better to do with '&' because this exercise is 
trying to teach you how the init works. This compared to HumanB is a good 
teaching example to compare with.
*/

HumanA::~HumanA()
{
	std::cout << RED << this->_name << RESET << " DEconstructor created here" \
	<< std::endl;
}

void	HumanA::attack()
{
	std::cout << GREEN << this->_name << RESET << " attacks with their " \
	<< GREEN << this->_weapon.getType() << RESET << std::endl;
/*
	std::cout << RED << this->_name << YELLOW << " attacks with their " \
	<< RED << this->_weapon << RESET << std::endl;
	
	This is wrong because you cannot access the _weapon side which belongs to
	weapon.hpp since it is private. However you can add .getType to obtain it's
	public function to get their type from there.
*/
}

