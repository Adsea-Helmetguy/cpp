/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:26:48 by mlow              #+#    #+#             */
/*   Updated: 2024/11/05 19:26:49 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ICHARACTER_HPP
#define	ICHARACTER_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class AMateria;

# define RESET		"\033[0m"
# define RED		"\033[31m"//Red
# define GREEN		"\033[32m"//Green
# define YELLOW		"\033[33m"//Yellow
# define BLUE		"\033[34m"//Blue

// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		//virtual void unequip(int idx) = 0;
		//virtual void use(int idx, ICharacter& target) = 0;
};

#endif




















