/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:52:02 by mlow              #+#    #+#             */
/*   Updated: 2025/02/27 17:03:32 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SPAN_HPP
#define	SPAN_HPP

# include <iostream>
# include <string>
# include <exception>
# include <limits.h>
# include <vector>
# include <algorithm>


# define RT	"\033[0m"
# define RED	"\033[31m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define CYAN	"\033[0;36m"
# define GREEN	"\033[32m"
# define MAG	"\e[0;35m"

class	Span
{
	private:
		unsigned int		N;//Should it be const, but if it does, i can't copy right?
		std::string		_name;
		unsigned int		_arraySize;
		std::vector<int>	_arrayNum;

	public:
		Span(unsigned int value);//starts with maximum capacity it can store(N).
		Span(const Span& copy);
		Span&	operator=(const Span& copy);
		~Span();
	
	//----------------------member functions----------------------
	int	addNumber(int value);//increment(++), throw exception if arraysize == N
	void	addNumberGroup(const std::vector<int> &numbers);
	int	shortestSpan();//if only one or nil, throw exception
	int	longestSpan();//if only one or nil, throw exception

	//add-on:
	//Implement a member function to add many numbers to your Span in one call.
	int	add_numSpan();//to add a sequence of elements to container, std::vector/list?
	
	//Personal Functions:
	unsigned int		getN() const;
	std::string		getName() const;
	unsigned int		getArray_size() const;
	int			getArray_num(unsigned int array) const;
	std::vector<int>	getArray() const;
	//----------------------member functions----------------------
};

//std::ostream& operator<<(std::ostream& os, const Span& SS);
#endif
