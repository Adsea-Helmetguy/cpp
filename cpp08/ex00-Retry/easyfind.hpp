/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:35:16 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:35:18 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	EASYFIND_HPP
#define	EASYFIND_HPP


# include <iostream>
# include <string>//std::string && "<class>.size() /length();""
# include <vector>
# include <exception>
# include <list>
# include <deque>
# include <algorithm>


# define RT	"\033[0m"
# define RED	"\033[31m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define CYAN	"\033[0;36m"
# define GREEN	"\033[32m"
# define MAG	"\e[0;35m"

template<typename T>
int	noteasyfind(const T &a, int b);//assume T is a container of int

//version 1
template<typename T>
int	easyfind(const T &a, int ValueToFind);//assume T is a container of int

//version 2
template <typename T>
typename T::const_iterator it_easyfind(const T &arr, int ValueToFind);

# include "easyfind.tpp"

#endif
