/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:21:57 by mlow              #+#    #+#             */
/*   Updated: 2024/11/05 15:21:58 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP


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

class Cure : public AMateria
{
	public:
		// Constructors
		Cure();
	 	Cure(std::string const & type);
		Cure(const Cure &copy);
		~Cure();// Destructor

		// Operators
		Cure &operator=(const Cure &other);

		//functions
		Cure *clone() const;
		void use(ICharacter &target);
};

#endif
