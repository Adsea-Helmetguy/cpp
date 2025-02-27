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

class	Span
{
	private:
		unsigned int*	_N;

	public:
		Span();
		Span(const Span& copy);
		Span&	operator=(const Span& copy);
		~Span();
	
	//member functions
	int	addNumber();
	int	shortestSpan();
	int	longestSpan();
};

//std::ostream& operator<<(std::ostream& os, const Array<T>& form);
#endif
