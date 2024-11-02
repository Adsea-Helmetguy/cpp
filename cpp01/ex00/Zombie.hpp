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

/*
	Include guards are stuff like ifndef, define and endif 
	which we done already
*/
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# include <string>//std::string
# include <cctype>
# include <iomanip> //for std::setw
# include <sstream>
# include <new>

# define RESET		"\033[0m"
# define RED		"\033[31m"//Red
# define GREEN		"\033[32m"//Green
# define YELLOW		"\033[33m"//Yellow
# define BLUE		"\033[34m"//Blue

// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class Zombie
{
public:
	Zombie();
	Zombie(std::string name);//constructor--initializes object class allocating resources
	~Zombie();//destructor--cleans resources allocated by object
	
	std::string	zombie_name;
	void announce(void);

private:
	std::string	name;
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);

#endif //CONTACT_HPP
/*
-It creates a zombie, name it, 
and return it so you can use it outside of the function scope-

Basically it is saying that it should not be a class member function and should
be a function OUTSIDE the class. Thus newZombie.cpp and randomChump.cpp were
formed, without adding the Zombie:: thingy infront of the functions.

They're global functions that interact with the Zombie class 
BUT are not it's members.
*/
