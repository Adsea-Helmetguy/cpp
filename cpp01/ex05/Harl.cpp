/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:34:28 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:34:30 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << GREEN << "Oh no.... Incoming " << RED << "\"Harl\"." \
	<< RESET << std::endl;
}

Harl::~Harl()
{
	std::cout << "FINALLY!! " << RED << "Harl LEFT THE STORE!!!" \
	<< RESET << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon " \
	<< "for my 7XL-double-cheese-triple-pickle-special-" \
	<< "ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. " \
	<< "You didn’t put enough bacon in my burger! " \
	<< "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. " \
	<<  "I’ve been coming for years whereas you started working " \
	<< "here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << YELLOW << "This is unacceptable! " << RED << "I want " \
	<< "to speak to the manager now!!!!!" << RESET << std::endl;
}

/*
Harl::funcs can hold 4 pointers/addresses in funcs array

Member function pointers in C++ must be declared using the * (pointer) 
syntax with the correct scope of the class they belong to.

----------------------------------------------------------------------------------
funcs is just a local array inside the complain method. 
This means it's created when complain is called and destroyed when complain exits. 

It does not need to be part of the class itself because 
it exists only temporarily during the function execution.
----------------------------------------------------------------------------------
*/
void	Harl::complain(std::string level)
{
	std::string	levels[4];//holds levels 0-3, 4 possible strings
	void		(Harl::*funcs[4])() = {&Harl::debug, &Harl::info, \
				&Harl::warning, &Harl::error};

	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
	for (int index = 0; index < 4; index++)
	{
		if (levels[index] == level)
		{
			(this->*funcs[index])();
			return;
		}
	}
	std::cout << "NO valid level" << std::endl;
}
