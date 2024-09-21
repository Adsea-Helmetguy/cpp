/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:36:58 by mlow              #+#    #+#             */
/*   Updated: 2024/01/02 15:55:07 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

# include <iostream>
# include <string>//std::string
# include <cctype>
# include <iomanip> //for std::setw
# include <sstream>

// ************************************************************************** //
//                               Phonebook Class                              //
// ************************************************************************** //

class Phonebook
{
public:
	Phonebook();//constructor--initializes object class allocating resources
	~Phonebook();//destructor--cleans resources allocated by object
	void	welcome(void) const;//welcome message
	void	addContact(void);//adds new contact
	void	printContacts(void);
	void	search(void);
//	void	search(void) const;
	
private:
	Contact	_contacts[8];//to limit up to 8 contacts
	int		total_contacts;//== 0
//	int		read_input(void) const;
};

#endif // PHONEBOOK_HPP
/*
Constructor (Phonebook()):
Initialization: It initializes the object of the class.
Memory Allocation: It allocates memory if necessary.
Resource Acquisition: It acquires resources needed by the object.
Usage: Constructors are typically used to set initial values for 
	member variables or to perform any setup required by the object.



Destructor (~Phonebook()):
Cleanup: It cleans up resources held by the object.
Memory Deallocation: It deallocates memory if necessary.
Resource Release: It releases resources acquired by the object 
	during its lifetime.
Usage: Destructors are used to release resources like memory, 
	file handles, network connections, etc., held by the object.
*/
