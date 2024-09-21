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
//	std::cout << "Phonebook Constructor" << std::endl;
//	std::cout << "Current number of Contacts set: " << total_contacts << std::endl;
}

Phonebook::~Phonebook()
{
//	std::cout << "Phonebook destructor" << std::endl;
}

//to define a member function outside the class "PhoneBook::welcome"
void    Phonebook::welcome(void) const//const to prevent modify.
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
// first name, last name, nickname, phone number, and
//  darkest secret

void	Phonebook::addContact(void)//no const cause values keep changing
{
	this->_contacts[this->total_contacts % 8].init();
	this->total_contacts++;
	std::cout << "Total overall Contacts set: " << total_contacts << std::endl;
	std::cout << "AFTER USING '%' " << (total_contacts % 8) << std::endl;
}

void	Phonebook::printContacts(void)
{
	int		index;

	std::cout << "-----All Current available Contacts-----" << std::endl;
	index = -1;
	while (++index < 8)//does this stop when there is no value inside?
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
		std::istringstream iss(input);
		if (iss >> number)
		{
			if ((number >= 0 && number < 8) 
				&& (this->_contacts[number].exist() != 0))
			{
				this->_contacts[number].display(number);
				//std::cout << "Test completed for SEARCH" << std::endl;
			}
			else
			{
				if (number < 0 || number > 7) 
					std::cout << "Hey! try from (0 to 7)!:" << std::endl;
				else
					std::cout << "It's empty try again!:" << std::endl;
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
