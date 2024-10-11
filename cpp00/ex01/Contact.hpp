/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:36:58 by mlow              #+#    #+#             */
/*   Updated: 2024/01/02 15:55:07 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>
# include <string>//std::string
# include <cctype>

// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class Contact
{
public:
	Contact();//constructor--initializes object class allocating resources
	~Contact();//destructor--cleans resources allocated by object
	void	init(void);
	void	view(int index);
	int	exist(void);
	void	display(int index) const;

private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	int		whitespaces(std::string *string);
	std::string	get_contact_input(std::string string);
	std::string	trunc_text(std::string text);
};

#endif //CONTACT_HPP
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
