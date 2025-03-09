/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:13:14 by mlow              #+#    #+#             */
/*   Updated: 2025/03/05 19:18:06 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MUTANTSTACK_HPP
#define	MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include <deque>
# include <algorithm>

# define RT	"\033[0m"
# define RED	"\033[31m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define CYAN	"\033[0;36m"
# define GREEN	"\033[32m"
# define MAG	"\e[0;35m"


template <typename T>
class	MutantStack : public std::stack<T>//std::stack needs a "type" parameter"<T>"
{
	public:
		MutantStack();
		MutantStack(const MutantStack& copy);
		MutantStack&	operator=(const MutantStack& copy);
		~MutantStack();

	//--------------Creating my own iterators--------------
	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;

	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;

	//---Personal Functions---
	void	getstack_values() const;
	//std::list<int>	copystack() const;
	
};

template <typename T>
std::ostream&	operator<<(std::ostream& os, const MutantStack<T>& stack);

//from ex00
template <typename T>
int		easyfind(const T &a, int ValueToFind);

#include "MutantStack.tpp"

#endif
