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

#ifndef CAT_HPP
#define CAT_HPP

# include "Brain.hpp"
# include "Animal.hpp"
# include <iostream>
# include <string>//std::string

// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class Cat : public Animal
{
private:
	Brain*	_Brain;
public:
	Cat();
	Cat(const std::string& name);
	Cat(const Cat &other);
	Cat&	operator=(const Cat &other);
	~Cat();

	std::string	getType() const;
	void		makeSound() const;
//
//
//New functions!
	void		edit_brain(int idea_number, std::string input_ideas);
	void		get_brain(int idea_number);
};

#endif
