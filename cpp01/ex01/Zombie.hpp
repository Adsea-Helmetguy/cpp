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

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# include <string>//std::string
# include <cctype>
# include <iomanip> //for std::setw
# include <sstream>
# include <new>



// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class Zombie
{
public:
	Zombie();
	~Zombie();//destructor--cleans resources allocated by object
	
	void announce(void);
	void	name_init(std::string name);

private:
	std::string	name;
};

Zombie*	zombieHorde(int N, std::string name);

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
