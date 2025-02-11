/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
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


# define RESET	"\033[0m"
# define RED	"\033[31m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define GREEN	"\033[32m"
# define MAG	"\e[0;35m"

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