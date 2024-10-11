/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:36:58 by mlow              #+#    #+#             */
/*   Updated: 2024/08/15 21:37:08 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//check out C++ Overloading (Operator and Function)
// && c++ setters and getters
Zombie*	zombieHorde(int N, std::string name)
{
	Zombie		*newZombie_creation;

	newZombie_creation = new Zombie[N];
	for (int loop = 0; loop < N; loop++)
	{
		newZombie_creation[loop].name_init(name);
		newZombie_creation[loop].announce();
	}
	return (newZombie_creation);
}
