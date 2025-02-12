/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:35:16 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:35:18 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

# include <iostream>
# include <string>//std::string && "<class>.size() /length();""
# include <stdint.h>

# define RESET	"\033[0m"
# define RED	"\033[31m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define GREEN	"\033[32m"
# define MAG	"\e[0;35m"
// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class Data
{
	private:
		std::string	_name;

	public:
		Data();										// default constructor
		Data(const std::string& name);
		Data(const Data& copy);						// copy constructor
		Data& operator=(const Data& copy);			// Copy assignment
		~Data();									// destructor

		std::string	getName() const;
};

std::ostream& operator<<(std::ostream& os, const Data& other);
#endif

