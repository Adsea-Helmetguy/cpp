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
#include "ScavTrap.hpp"

//https://github.com/Dsite42/CPP03/blob/master/ex00/ClapTrap.cpp refer to this if u need help
int main(void)
{
    ScavTrap scav("Gatekeeper");

    scav.guardGate();  // This will print the Gatekeeper mode message
    scav.attack("target");
    
    return (0);
}
