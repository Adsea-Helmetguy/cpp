/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:21:45 by mlow              #+#    #+#             */
/*   Updated: 2024/11/05 15:21:46 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

# include <iostream>
# include <string>//std::string
# include "AMateria.hpp"
# include "ICharacter.hpp"
//# include "MateriaSource.hpp"

# define RESET		"\033[0m"
# define RED		"\033[31m"//Red
# define GREEN		"\033[32m"//Green
# define YELLOW		"\033[33m"//Yellow
# define BLUE		"\033[34m"//Blue

// ************************************************************************** //
//                               	 Class                                //
// ************************************************************************** //

//Of course, their member function
//clone() will return a new instance of the same type (i.e., if you clone an Ice Materia,
//you will get a new Ice Materia).
class Ice : public AMateria
{
protected:
	//std::string	_type;
public:
	// Constructors
	Ice();
 	Ice(std::string const & type);
	Ice(const Ice &copy);
	~Ice();// Destructor

	// Operators
	Ice &operator=(const Ice &other);
	
	// Getters & Setters
	std::string const & getType() const;//Returns the materia type

	Ice *clone() const;
	void use(ICharacter& target);
};

#endif
