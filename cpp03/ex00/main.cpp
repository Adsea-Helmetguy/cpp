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

int main(void)
{
	std::cout << YELLOW << std::endl << "Showing ClapTrap constructors" << RESET << std::endl;

	ClapTrap default_clap;
	ClapTrap tim("Tim");
	ClapTrap copy_tim(tim);// Calls the copy constructor
	ClapTrap bernd("Bernd");


	//Note to self. Get_hit_points and Get_energy_points are required 
	// because these are in private and without functions, we cannot access them!
	std::cout << YELLOW << std::endl << "Tests for ClapTrap functions" \
	<< RESET << std::endl;
	std::cout << "Tim has " << tim.get_hit_points() << " hit points and " \
	<< tim.get_energy_points() << " energy points left" << std::endl;
	tim.attack("a bear");
	tim.takeDamage(2);
	std::cout << "Tim has " << tim.get_hit_points() << " hit points and " \
	<< tim.get_energy_points() << " energy points left" << std::endl;


	std::cout << YELLOW << std::endl << "Tests for being dead" << RESET << std::endl;
	std::cout << "Bernd has " << bernd.get_hit_points() << " hit points and " \
	<< bernd.get_energy_points() << " energy points left" << std::endl;
	bernd.takeDamage(11);
	bernd.attack("house");
	bernd.beRepaired(5);
	bernd.takeDamage(5);
	std::cout << "Bernd has " << bernd.get_hit_points() << " hit points and " \
	<< bernd.get_energy_points() << " energy points left" << std::endl;
	

	std::cout << YELLOW << std::endl \
	<< "Tests for ClapTrap copy constructor and assignment operator" << RESET << std::endl;
	std::cout << "CopyTim has " << copy_tim.get_hit_points() << " hit points and " \
	<< copy_tim.get_energy_points() << " energy points left" << std::endl;
	copy_tim = bernd;
	std::cout << "CopyTim has " << copy_tim.get_hit_points() << " hit points and " \
	<< copy_tim.get_energy_points() << " energy points left" << std::endl;


	std::cout << YELLOW << std::endl << "Deconstructor calling" << RESET << std::endl;

	return (0);
}
