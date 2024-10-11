/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:33:42 by mlow              #+#    #+#             */
/*   Updated: 2024/05/26 17:40:20 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	main(void) 
{
	Phonebook	phonebook;
	std::string	input = "";

	phonebook.welcome();
	while (input.compare("EXIT"))
	{
		std::cout << "Enter Command: " << std::flush;
		if (std::getline(std::cin, input))
		{
			if (input.compare("ADD") == 0)
				phonebook.addContact();
			else if (input.compare("SEARCH") == 0)
				phonebook.printContacts();
		}
		else if (!std::getline(std::cin, input))
			break ;
	}
	std::cout << "EXIT! Thank you for Using Phonebook!" << std::endl;
	std::cout << "All data are erased! Type ./phonebook again to use me!" << std::endl;
	return (0);
}
