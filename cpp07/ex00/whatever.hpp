/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:35:16 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:35:18 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>//std::string && "<class>.size() /length();""


# define RT	"\033[0m"
# define RED	"\033[31m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define CYAN	"\033[0;36m"
# define GREEN	"\033[32m"
# define MAG	"\e[0;35m"

//Creating a template here and define it
//https://isocpp.org/wiki/faq/templates#:~:text=A%20template%20is%20a%20%E2%80%9Cpattern,%E2%80%9Cfill%20in%E2%80%9D%20the%20template.
//first is swap:
//---------------------------------------------------------------
template<typename T>// the defined "T" is the template now

void	swap(T &a, T &b)
{
	T temp = b;
	b = a;
	a = temp;
};

//second is min
//---------------------------------------------------------------
template<typename U>// the defined "U" is the template now

U	min(U &a, U &b)
{
	if (a < b)
		return (a);
	return (b);
};

//second is man
//---------------------------------------------------------------
template<typename S>// the defined "U" is the template now

S	max(S &a, S &b)
{
	if (a > b)
		return (a);
	return (b);
};























/*
//Templates must be defined in the header files
template< typename T > // defines, T is a template

//max
const T	&max(const T &x ,const T &y) // more const, more better
{
	return (x >= y ? x : y);
}

template< typename U > // defines, U is a template

//min
const U	&min(const U &x ,const U &y) // more const, more better
{
	return (x <= y ? x : y);
}

template< typename V >

//swap
void swap(V &x, V &y)
{
	V temp = x;
	x = y;
	y = temp;
}
*/
