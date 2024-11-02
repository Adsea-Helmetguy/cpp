/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:49:33 by mlow              #+#    #+#             */
/*   Updated: 2024/10/21 11:49:45 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

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
//                                  Class                                     //
// ************************************************************************** //

class Weapon
{
private:
	std::string	_type;//'_' added to mark it is a private member datatype

public:
	Weapon();
	Weapon(std::string name);
	~Weapon();

	const std::string&	getType() const;//for access
	void			setType(std::string type);//for modify

};
#endif

