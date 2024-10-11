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
	std::cout << "Incoming Harl....?" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl destroyed....?" << std::endl;
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
	<< " You didn’t put enough bacon in my burger! " \
	<< "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. " \
	<< "I’ve been coming for years whereas you started working " \
	<< "here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the " \
	<< "manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	levels[4];
	void		(Harl::*funcs[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

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
