/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:34:13 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:34:18 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
You don’t have to handle associative containers.
e.g:
1) set
2) map
3) multiset
4) multimap
*/
#include "Span.hpp"

// about iterators: https://www.youtube.com/watch?v=EgVWWVZ6AEY
/*
note, about this code:
std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));

the arr inside here:
("arr" + sizeof---), points to the first element of the array.
*/

int	main(void)
{
	std::cout << "\n\n" << std::endl;
	std::cout << "----Official test (1)----" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
/*
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
*/
//
/*
			result should be:
			2
			14
*/
	}
	std::cout << "-------------------------" << std::endl;
	std::cout << "\n" << std::endl;
	return (0);
};

