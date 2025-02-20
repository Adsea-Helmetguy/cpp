/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:35:16 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:35:18 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

# include <iostream>
# include <string>//std::string && "<class>.size() /length();""
# include <cstdlib>//For rand() && srand()
# include <ctime>//For time()
# include <exception>//std::exception

# define RT	"\033[0m"
# define RED	"\033[31m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define GREEN	"\033[32m"
# define MAG	"\e[0;35m"
// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class Base
{
	public:
		virtual ~Base();// destructor
};

class A : public Base{};
class B : public Base{};
class C : public Base{};

//Random Generator A/B/C return (Base pointer);
Base *generate(void);
void identify(Base* p);
void identify(Base& p);

//std::ostream& operator<<(std::ostream& os, const Base& other);
#endif

