/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:35:16 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:35:18 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# include <iostream>
# include <string>//std::string && "<class>.size() /length();""
# include <stdint.h>
# include "../data_file/Data.hpp"

# define RT	"\033[0m"
# define RED	"\033[31m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define GREEN	"\033[32m"
# define MAG	"\e[0;35m"
// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class Serializer
{
	private:
		Serializer();										// default constructor
		Serializer(const Serializer& copy);					// copy constructor
		Serializer& operator=(const Serializer& copy);		// Copy assignment
		~Serializer();										// destructor

	public:
		static uintptr_t	serialize(Data* ptr);		//static method
		static Data*		deserialize(uintptr_t raw);	//static method
};

//std::ostream& operator<<(std::ostream& os, const Serializer& other);
#endif

