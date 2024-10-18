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

#ifndef DOG_HPP
#define DOG_HPP

# include "Brain.hpp"
# include "Animal.hpp"
# include <iostream>
# include <string>//std::string

// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class Dog : public Animal
{
private:
	Brain*	_Brain;
public:
	Dog();
	Dog(const std::string& name);
	Dog(const Dog &other);
	Dog&	operator=(const Dog &other);
	~Dog();

	std::string	getType() const;
	void		makeSound() const;
//
//
//New functions!
	void		edit_brain(int idea_number, std::string input_ideas);
	void		get_brain(int idea_number);
};

#endif
