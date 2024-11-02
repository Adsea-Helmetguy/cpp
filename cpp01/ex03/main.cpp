/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:34:13 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:34:18 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
    {
    	std::cout << YELLOW << "\n\nConstructor starts over here! humanA" << RESET << std::endl;
        Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	std::cout << YELLOW << "\n\nDEConstructor Now removes EVERYTHING!" << RESET << std::endl;
    }
    std::cout << YELLOW << "\n\n\n\n-------------------\n\n\n" << RESET << std::endl;
    {
	std::cout << YELLOW << "\n\nConstructor starts over here! humanB" << RESET << std::endl;
	Weapon club = Weapon("crude spiked club");

	HumanB jim("Jim");
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
	std::cout << YELLOW << "\n\nDEConstructor Now removes EVERYTHING!" << RESET << std::endl;
    }
    return 0;
}
