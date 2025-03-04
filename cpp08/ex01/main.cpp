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
//
/*
static int	array_int()
{
	return (0);
};
*/

int	main(void)
{
	std::cout << "\n\n" << std::endl;
	std::cout << "----Official test (1)----" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "-------------------------" << std::endl;


	//Note:
	// I will not be using the push_back function cause it's a hassle
	std::cout << "\n\n" << YELLOW << std::endl;
	std::cout << "----Personal test (1[Same test but with Iterators])----" << RT << std::endl;
	{
		Span sp = Span(5);

		try
		{
			int arr[] = {6, 3, 17, 9, 11};
			std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));

			sp.addNumberGroup(numbers);
			std::cout << "Shortest_span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest_span: " << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RT << std::endl;
		}
		std::cout << YELLOW << "Destructors here:" << RT << std::endl;
	}
	std::cout << "-------------------------" << std::endl;


	std::cout << "\n\n" << YELLOW << std::endl;
	std::cout << "----Personal test (2[lower Span \'N\' size])----" << RT << std::endl;
	{
		Span sp = Span(1);
		try
		{
			int arr[] = {6, 3, 17, 9, 11};
			std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));

			sp.addNumberGroup(numbers);
			std::cout << "Shortest_span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest_span: " << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RT << std::endl;
		}
		std::cout << YELLOW << "Destructors here:" << RT << std::endl;
	}
	std::cout << "-------------------------" << std::endl;
	
	
	std::cout << "\n\n" << YELLOW << std::endl;
	std::cout << "----Personal test (3[beyond INT_MAX])----" << RT << std::endl;
	{
		Span sp = Span(4294967295);
		//std::cout<< "\n" << Span.size() << std::endl;
		std::cout << YELLOW << "\nDestructors here:" << RT << std::endl;
	}
	std::cout << "-------------------------" << std::endl;
	
	
	std::cout << "\n\n" << YELLOW << std::endl;
	std::cout << "----Personal test (4[Different value for short/long])----" << RT << std::endl;
	{
		Span sp = Span(10);
		try
		{
			int arr[] = {2, 10, 3, 11, 9, 1, 17, 20, 25, 30};
			std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));

			sp.addNumberGroup(numbers);
			std::cout << "Shortest_span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest_span: " << sp.longestSpan() << std::endl;
			std::cout << "\nNOTE! THE CORRECT ANSWER SHOULD BE:" << std::endl;
			std::cout << "Shortest_span: " << 1 << std::endl;
			std::cout << "Longest_span: " << 29 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RT << std::endl;
		}
		std::cout << YELLOW << "\nDestructors here:" << RT << std::endl;
	}
	std::cout << "-------------------------" << std::endl;
	std::cout << "\n\n" << std::endl;
	return (0);
};

