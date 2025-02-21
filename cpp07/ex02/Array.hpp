/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:35:16 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:35:18 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ARRAY_HPP
#define	ARRAY_HPP

# include <iostream>
# include <string>//std::string && "<class>.size() /length();"
# include <exception>//std::exception
# include <cstdlib>//for rand()

# include "Array.tpp"

# define RT	"\033[0m"
# define RED	"\033[31m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define CYAN	"\033[0;36m"
# define GREEN	"\033[32m"
# define MAG	"\e[0;35m"

//create:
//class template Array that contains 
/*
		//elements of type T and that implements\\


		1)---construction---
		-Construction with no parameter: Creates an empty array.
		-Construction with an unsigned int n as a parameter.
		-Construction by copy and assignment operator.


		2)---functions---
		-use the operator new[] to allocate memory.
		-Elements can be accessed through the subscript operator: [ ].
		-[ ] operator, if its index is out of bounds, an std::exception is thrown.
		-A member function size() that returns the number of elements in the array.
*/

template <typename T>
class	Array
{
	private:
		T	_name;
		
	public:
		Array() : _name("Default_name");
		Array(unsigned int n) : _name("Default_name");
		Array(const Array &copy);
		Array&	operator=(const Array &copy);
		~Array();
	
	std::string	getName()
	{
		return (this->_name);
	};
	
	void	numbers(Array max_value);
};

//std::ostream& operator<<(std::ostream& os, const Array& other);
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
