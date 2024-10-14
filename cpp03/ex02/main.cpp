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

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	std::cout << YELLOW << std::endl << "Tests for FragTrap constructor" << RESET << std::endl;
	FragTrap default_tom;
	FragTrap tom("Tom");
//
//
//
//
//
//
    std::cout << YELLOW << std::endl << "Checking FragTrap's values" << RESET << std::endl;
    std::cout << "The current name for this FragTrap is: " << BLUE << tom.get_name() << RESET << std::endl;
	std::cout << "It's current _Hit_points: " << BLUE << tom.get_hit_points() << RESET << std::endl;
    std::cout << "It's current _Energy_points: " << BLUE <<tom.get_energy_points() << RESET << std::endl;
	std::cout << "It's current _Attack_damage: " << BLUE << tom.get_attack_damage() << RESET << std::endl;
//
//
//
//
//
//
	std::cout << YELLOW << std::endl << "Tests for FragTrap functions" << RESET << std::endl;
	tom.highFivesGuys();
	tom.highFivesGuys();
	tom.attack("a car");
	std::cout << tom.get_name() << " has " << tom.get_hit_points() << " hit points and " << tom.get_energy_points() << " energy points left" << std::endl;
//
//
//
//
//
//
	std::cout << YELLOW << std::endl << "Tests for FragTrap copy constructor" << RESET << std::endl;
	FragTrap copytom(tom);
	std::cout << copytom.get_name() << " has " << copytom.get_hit_points() << " hit points and " << copytom.get_energy_points() << " energy points left" << std::endl;
//
//
//
//
//
//
//
	std::cout << YELLOW << std::endl << "Tests for FragTrap copy assignment constructor" << RESET << std::endl;
	tom.attack("a car");
	std::cout << tom.get_name() << " has " << tom.get_hit_points() << " hit points and " << tom.get_energy_points() << " energy points left" << std::endl;
	FragTrap thirdtom("ThirdTom");
	std::cout << thirdtom.get_name() << " has " << thirdtom.get_hit_points() << " hit points and " << thirdtom.get_energy_points() << " energy points left" << std::endl;
	//thirdtom = tom;
	//std::cout << thirdtom.get_name() << " has " << thirdtom.get_hit_points() << " hit points and " << thirdtom.get_energy_points() << " energy points left" << std::endl;
//
//
//
//
//
//
	std::cout << YELLOW << std::endl << "Tests for more FragTrap functions" << RESET << std::endl;
	tom.takeDamage(2);
	std::cout << tom.get_name() << " has " << tom.get_hit_points() << " hit points and " << tom.get_energy_points() << " energy points left" << std::endl;
	tom.beRepaired(2);
	std::cout << tom.get_name() << " has " << tom.get_hit_points() << " hit points and " << tom.get_energy_points() << " energy points left" << std::endl;
//
//
//
//
//
//
	std::cout << YELLOW << std::endl << "Deconstructor calling" << RESET << std::endl;

	return (0);
}
// ctrl+F first, then ALT+Enter
