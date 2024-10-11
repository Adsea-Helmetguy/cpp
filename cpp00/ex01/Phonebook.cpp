/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:21:35 by mlow              #+#    #+#             */
/*   Updated: 2024/05/24 19:22:00 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	total_contacts = 0;
}

Phonebook::~Phonebook()
{

}

void    Phonebook::welcome(void) const
{
	std::cout << std::endl;
	std::cout << "📞 Welcome to the PhoneBook 📖" << std::endl;
	std::cout << std::endl;
	std::cout << "--------------USAGE---------------" << std::endl;
	std::cout << "ADD\t: To add a NEW contact." << std::endl;
	std::cout << "SEARCH\t: To search for a contact." << std::endl;
	std::cout << "EXIT\t: Quits Phonebook, losing all contacts." << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << std::endl;
}

void	Phonebook::addContact(void)
{
	this->_contacts[this->total_contacts % 8].init();
	this->total_contacts++;
	std::cout << "Total overall Contacts set: " << total_contacts << std::endl;
}

void	Phonebook::printContacts(void)
{
	int		index;

	std::cout << "-----All Current available Contacts-----" << std::endl;
	index = -1;
	while (++index < 8)
	{
		this->_contacts[index].view(index);
	}
	this->search();
	std::cout << std::endl;
}

void	Phonebook::search(void)
{
	std::string	input = "";
	int		number = 9;

	if (this->_contacts[0].exist() == 0)
	{
		std::cout << "PHONEBOOK EMPTY!! Restarting!!!" << std::flush;
		return ;
	}
	std::cout << "User, Enter the number for which contact you want" << std::endl;
	while (number == 9)
	{
		std::cout << "Index: " << std::flush;
		if (!std::getline(std::cin, input))
			break ;
		if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
		{
			number = input[0] - '0'; 
			if (this->_contacts[number].exist() != 0)
			{
				this->_contacts[number].display(number);
			}
			else
			{
				std::cout << "It's empty, try again!:" << std::endl;
				number = 9; // Reset number to continue the loop
			}
		}
		else
		{
			number = 9;
			std::cout << "invalid index, re-enter:" << std::endl;
		}
	}
}
/*
void	Phonebook::search(void)
{
	std::string	input = "";
	int		number = 9;

	if (this->_contacts[0].exist() == 0)
	{
		std::cout << "PHONEBOOK EMPTY!! Restarting!!!" << std::flush;
		return ;
	}
	std::cout << "User, Enter the number for which contact you want" << std::endl;
	while (number == 9)
	{
		std::cout << "Index: " << std::flush;
		if (!std::getline(std::cin, input))
			break ;
		std::istringstream iss(input);
		if (iss >> number)
		{
			if ((input.length() == 1) && (number >= 0 && number < 8) 
				&& (this->_contacts[number].exist() != 0))
				this->_contacts[number].display(number);
			else
			{
				if (number < 0 || number > 7) 
					std::cout << "Hey! try from (0 to 7)!:" << std::endl;
				else
					std::cout << "It's incorrect try again!:" << std::endl;
				number = 9;
			}
		}
		else
		{
			number = 9;
			std::cout << "invalid index, re-enter:" << std::endl;
		}
	}
}
*/
