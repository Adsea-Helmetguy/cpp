/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:18:17 by mlow              #+#    #+#             */
/*   Updated: 2024/11/11 10:38:43 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MATERIASOURCE_HPP
#define	MATERIASOURCE_HPP

# include <iostream>
# include <string>//std::string
# include "IMateriaSource.hpp"


// ************************************************************************** //
//                                   Class                                    //
// ************************************************************************** //

class	MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_Materia_slot[4];//slot 0 to slot 3
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &copy);
		~MateriaSource();// Destructor

		// Operators
		MateriaSource &operator=(const MateriaSource &other);
		
		void		learnMateria(AMateria* copy);
		AMateria*	createMateria(std::string const & type);
};
#endif
