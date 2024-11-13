/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:53:13 by mlow              #+#    #+#             */
/*   Updated: 2024/11/06 09:53:15 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define	CHARACTER_HPP

# include <iostream>
# include <string>//std::string
# include "ICharacter.hpp"
//# include "MateriaSource.hpp"


# define RESET		"\033[0m"
# define RED		"\033[31m"//Red
# define GREEN		"\033[32m"//Green
# define YELLOW		"\033[33m"//Yellow
# define BLUE		"\033[34m"//Blue

// ************************************************************************** //
//                                    Class                                   //
// ************************************************************************** //

class Character : public ICharacter
{
	protected:
		std::string	_name;
		AMateria	*_Materia_slot[4];//slot 0 to slot 3
		static int	_discarded_slot;
		AMateria	*_discarded_Materia[50];
	public:
		Character();
		Character(std::string const &name);
		Character(const Character &copy);
		~Character();//ICharacter virtual destructor
		
		//Operators
		Character	&operator=(const Character &copy);
		
		//ICharacter functions overwrite!
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};
#endif



































