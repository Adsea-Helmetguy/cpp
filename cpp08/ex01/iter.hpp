/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:35:16 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:35:18 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ITER_HPP
#define ITER_HPP

# include <iostream>
# include <string>//std::string && "<class>.size() /length();"

# define RT	"\033[0m"
# define RED	"\033[31m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define CYAN	"\033[0;36m"
# define GREEN	"\033[32m"
# define MAG	"\e[0;35m"


//create a function template iter
//template <typename T, typename S, typename N>
template <typename T, typename L, typename S>
void	iter(T *array, L arr_len, S (*function))
{
	if (array == NULL || function == NULL)
		return ;
	for (size_t i = 0; i < static_cast<size_t>(arr_len); i++)
		function(array[i]);
};


#endif














//note:
/*
Previously your code was:
template <typename T>
void	iter(T *array, size_t arr_len, void (*function)(T &))
{
	if (array == NULL || function == NULL)
		return ;
	for (size_t i = 0; i < arr_len; i++)
		function(array[i]);
};
*/
