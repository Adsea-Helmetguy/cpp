/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:18:13 by mlow              #+#    #+#             */
/*   Updated: 2024/11/05 19:18:15 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	IMATERIASOURCE_HPP
#define	IMATERIASOURCE_HPP

# include <iostream>
# include <string>//std::string

# define RESET		"\033[0m"
# define RED		"\033[31m"//Red
# define GREEN		"\033[32m"//Green
# define YELLOW		"\033[33m"//Yellow
# define BLUE		"\033[34m"//Blue

// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class	IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
}






















