/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:36:03 by mlow              #+#    #+#             */
/*   Updated: 2024/11/05 14:36:06 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

# include <iostream>
# include <string>//std::string
# include "ICharacter.hpp"
//# include "MateriaSource.hpp"

class ICharacter;
//class IMateriaSource;

# define RESET		"\033[0m"
# define RED		"\033[31m"//Red
# define GREEN		"\033[32m"//Green
# define YELLOW		"\033[33m"//Yellow
# define BLUE		"\033[34m"//Blue

// ************************************************************************** //
//                                    Class                                   //
// ************************************************************************** //

class AMateria
{
	protected:
		std::string	_type;
	public:
		// Constructors
		AMateria();
 		AMateria(std::string const & type);
		AMateria(const AMateria &copy);//copy constructor
		virtual ~AMateria(); //Destructor

		// Operators
		AMateria &operator=(const AMateria &other);
	
		// Getters & Setters
		std::string const & getType() const; //Returns the materia type

		virtual AMateria *clone() const = 0;// refer 1);
		virtual void use(ICharacter& target);

//		Character *getWielder() const;
//		void setWielder(Character *new_wielder);
//		MateriaSource *getMateriaSource() const;
//		void setMateriaSource(MateriaSource *new_materia_source);
};
#endif
/*
https://isocpp.org/wiki/faq/virtual-functions#:~:text=A%20pure%20virtual%20function%20is,using%20the%20curious%20%3D0%20syntax.
1)A pure virtual function is a function that must be 
overridden in a derived class and need not be defined


2)
*/
