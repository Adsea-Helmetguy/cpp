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

#pragma once

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
template <typename T>
void	iter(T *array, size_t arr_len, void (*function)(T &))//called on each element of array (one by one)
{
	if (array == NULL || function == NULL)
		return ;
	for (size_t i = 0; i < arr_len; i++)
		function(array[i]);
	//function is a pointer till used at function(array[i])
};















/*
template <typename T>
void	iter(T *array, size_t arr_len, void (*function)(T &))//called on each element of array (one by one)
{
	if (array == NULL || function == NULL)
		return ;
	for (size_t i = 0; i < arr_len; i++)
		function(array[i]);
	//function is a pointer till used at function(array[i])
};
*/
//note:
/*
Previously your code was:
template <typename T>
void	iter(T *array, size_t array_length, void function(T *array))
{
	for (size_t i = 0; i < array_length; ++i)
	{
		function(array[i]);  // Apply function to each element
	}	
};

Instead, you should pass function as a function pointer to iter() without calling it.
that means you need to do this:
"void (*function)(T &)" -u can't add const here "(T const &)" 
	if you plan to change the values-

,just like how u did in cpp05.

*/
