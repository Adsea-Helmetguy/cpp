/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:35:16 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:35:18 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>
# include <string>//std::string

# define RESET   "\033[0m"
# define RED     "\033[31m"//Red
# define YELLOW  "\033[33m"//Yellow
# define BLUE    "\033[34m"//Blue

// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class WrongAnimal
{
protected:
	std::string	type;
public:
	WrongAnimal();//(init fixed point to 0) : _fixedpoint_value(0);
	WrongAnimal(const std::string& name);
	virtual ~WrongAnimal();
	
	std::string	getType() const;
	virtual void		makeSound() const;
};

#endif
