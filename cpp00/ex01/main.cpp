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
	Phonebook	phonebook;//creating variable called book
	std::string	input = "";//to give input an empty string

	phonebook.welcome();//Phonebook.cpp to intro ppl
	while (input.compare("EXIT"))//from std::cin >> input
	{
		std::cout << "Enter Command: " << std::flush;//prompts user for INPUT
		if (std::getline(std::cin, input))
		{
			if (input.compare("ADD") == 0)//from std::cin >> input
				phonebook.addContact();
			else if (input.compare("SEARCH") == 0)//from std::cin >> input
			{
				phonebook.printContacts();
			}
		}
		else if (!std::getline(std::cin, input))
			break ;
	}
	std::cout << "EXIT! Thank you for Using Phonebook!" << std::endl;
	std::cout << "All data are erased! Type ./phonebook again to use me!" << std::endl;
	return (0);
}
//https://cplusplus.com/reference/iomanip/
//https://cplusplus.com/reference/string/string/
