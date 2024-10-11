/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:03:33 by mlow              #+#    #+#             */
/*   Updated: 2024/05/26 18:03:45 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Contact::Contact()
{

}

Contact::~Contact()
{

}

int	Contact::whitespaces(std::string *string)
{
	for (size_t i = 0; i < (*string).size(); ++i)
	{
		if (!std::isspace(((*string)[i])))
			return (0);
	}
	(*string).clear();
	return (1);
}

std::string	Contact::get_contact_input(std::string string)
{
	std::string	input = "";

	while (input.empty())
	{
		std::cout << string << std::endl << std::flush;
		if (!std::getline(std::cin, input))
			break ;
		if (this->whitespaces(&input) == 1)
		{
			std::cout << "Input contains only whitespaces: " << std::flush;
			continue;
		}
		if (input.empty() ||std::cin.bad())
		{
			std::cin.clear();
			std::cout << "Invalid input: " << std::flush;
		}
	}
	return (input);
}

void	Contact::init(void)
{
	std::string	input = "";

	this->first_name = this->get_contact_input("Please Enter First Name: ");
	std::cout << "Entered: " << this->first_name << std::endl;
	std::cout << std::endl;
	this->last_name = this->get_contact_input("Please Enter last name: ");
	std::cout << "Entered: " << this->last_name << std::endl;
	std::cout << std::endl;
	this->nickname = this->get_contact_input("Please Enter nickname(NIL if none): ");
	std::cout << "Entered: " << this->nickname << std::endl;
	std::cout << std::endl;
	this->phone_number = this->get_contact_input("Now gimme their PHONE NUMBER -Stare-: ");
	std::cout << "Entered: " << this->phone_number << std::endl;
	std::cout << std::endl;
	this->darkest_secret = this->get_contact_input("Now GIMME THEIR DANKEST_secret: ");
	std::cout << "Entered: " << this->darkest_secret << std::endl;
	std::cout << std::endl;
}

std::string Contact::trunc_text(std::string text)
{
	if (text.length() > 10)
		return (text.substr(0, 9) + ".");
	return (text);
}

//if it goes past 10, reveal 9 characters and put the last one with "."
void	Contact::view(int index)
{
	if (this->first_name.empty() || this->last_name.empty() || this->nickname.empty())
	{
		std::cout << "EMPTY" << std::endl;
		return ;
	}
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "|" << std::setw(10) << index << std::flush;
	std::cout << "|" << std::setw(10) << trunc_text(this->first_name) << std::flush;
	std::cout << "|" << std::setw(10) << trunc_text(this->last_name) << std::flush;
	std::cout << "|" << std::setw(10) << trunc_text(this->nickname) << std::flush;
	std::cout << "|" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
}

int	Contact::exist(void)
{
	if (this->first_name.empty())
		return (0);
	return (1);
}

void	Contact::display(int index) const
{
	std::cout << std::endl;
	std::cout << "--------------------INDEX #" << index << std::flush;
	std::cout << "-------------------" << std::endl;
	std::cout << "First_Name: " << this->first_name << std::endl;
	std::cout << "Last_name: " << this->last_name << std::endl;
	std::cout << "Nickname: " <<this->nickname << std::endl;
	std::cout << "Phone_number: " << this->phone_number << std::endl;
	std::cout << "Dankest Sercet: " << this->darkest_secret << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
}
