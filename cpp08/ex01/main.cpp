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

#include "Span.hpp"

int	main(void)
{
	std::cout << "\n\n" << MAG << std::endl;
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
	std::cout << MAG << "-------------------------" << RT << std::endl;


	//Note:
	// I will not be using the push_back function cause it's a hassle
	std::cout << "\n\n" << MAG << std::endl;
	std::cout << "----Personal test (1)[Same test but with Iterators]----" << RT << std::endl;
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
	std::cout << MAG << "-------------------------" << RT << std::endl;


	std::cout << "\n\n" << MAG << std::endl;
	std::cout << "----Personal test (2)[Only one \'N\' Span size]----" << RT << std::endl;
	{
		std::cout << "\nsp created with span(1)" << std::endl;
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

		std::cout << "\nsp2 created with span(1)" << std::endl;
		Span sp2 = Span(1);
		sp2.addNumber(8);
		try
		{
			std::cout << "Shortest_span: " << sp2.shortestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RT << std::endl;
		}

		std::cout << "\nsp3 created with span(0)" << std::endl;
		Span sp3 = Span(0);
		try
		{
			std::cout << "Longest_span: " << sp3.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RT << std::endl;
		}
		std::cout << YELLOW << "Destructors here:" << RT << std::endl;
	}
	std::cout << MAG << "-------------------------" << RT << std::endl;
	
	
	std::cout << "\n\n" << MAG << std::endl;
	std::cout << "----Personal test (3)[Beyond INT_MAX]----" << RT << std::endl;
	{
		try
		{
			Span sp = Span(UINT_MAX);
			int arr[] = {2, 4, -10, -11, 9, 1, 17, 20, 25, 30};
			std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));

			sp.addNumberGroup(numbers);
			std::cout << "\n---------------------------" << std::endl;
			std::cout << "Value of N: " << sp.getN() << std::endl;
			std::cout << "Vs\n" << "Array Size: " \
				<< sp.getArray_size() << std::endl;
			std::cout << "---------------------------" << std::endl;
			std::cout << "Shortest_span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest_span: " << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RT << std::endl;
		}
		std::cout << YELLOW << "\nDestructors here:" << RT << std::endl;
	}
	std::cout << MAG << "-------------------------" << RT << std::endl;
	
	
	std::cout << "\n\n" << MAG << std::endl;
	std::cout << "----Personal test (4)[Output for short/long spans]----" << RT << std::endl;
	{
		Span sp = Span(10);
		try
		{
			int arr[] = {2, 4, -10, -11, 9, 1, 17, 20, 25, 30};
			std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));

			sp.addNumberGroup(numbers);
			std::cout << "Shortest_span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest_span: " << sp.longestSpan() << std::endl;
			std::cout << "\nNOTE! THE CORRECT ANSWER FOR: " \
				<< "\"{2, 4, -10, -11, 9, 1, 17, 20, 25, 30}\"" \
				<< " SHOULD BE:" << std::endl;
			std::cout << "Shortest_span: " << 1 << std::endl;
			std::cout << "Longest_span: " << 41 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RT << std::endl;
		}
		std::cout << YELLOW << "\nDestructors here:" << RT << std::endl;
	}
	std::cout << MAG << "-------------------------" << RT << std::endl;


	std::cout << "\n\n" << MAG << std::endl;
	std::cout << "----Personal test (5)[Refer to test 4 but with more space]----" \
		<< RT << std::endl;
	{
		Span sp = Span(20);
		try
		{
			int arr[] = {2, 4, -9, -11, 9, 0, 17, 20, 25, 30, 40};
			std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));

			sp.addNumberGroup(numbers);
			std::cout << "\n---------------------------" << std::endl;
			std::cout << "Value of N: " << sp.getN() << std::endl;
			std::cout << "Vs\n" << "Array Size: " \
				<< sp.getArray_size() << std::endl;
			std::cout << "---------------------------" << std::endl;
			std::cout << "Shortest_span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest_span: " << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RT << std::endl;
		}
		std::cout << YELLOW << "\nDestructors here:" << RT << std::endl;
	}
	std::cout << MAG << "-------------------------" << RT << std::endl;


	//Now doing the copy constructor and operator=();
	std::cout << "\n\n" << MAG << std::endl;
	std::cout << "----Personal test (6)[Copy constructor]----" \
		<< RT << std::endl;
	{
		Span sp = Span(10);
		try
		{
			int arr[] = {2, 4, -10, -11, 9, 1, 17, 20, 25, 30};
			std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));

			sp.addNumberGroup(numbers);
			std::cout << "\n---------------------------" << std::endl;
			std::cout << "Value of N: " << sp.getN() << std::endl;
			std::cout << "Vs\n" << "Array Size: " \
				<< sp.getArray_size() << std::endl;
			std::cout << "---------------------------" << std::endl;
			std::cout << "Shortest_span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest_span: " << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RT << std::endl;
		}
		
		//Now copying over
		std::cout << GREEN << "\n\nNow copying over!" << RT << std::endl;
		Span sp2(sp);
		std::cout << YELLOW << "Testing sp2: " << RT << sp2 << std::endl;

		//Now what happens if we edit one will the other stay the same?
		// to check if it's deep copying not shallow
		std::cout << GREEN \
		<< "Now testing if it was deep or Shallow copy!" << RT << std::endl;
		sp2.clearArray_values();
		std::cout << YELLOW << "Testing sp2(AGAIN): " << RT << sp2 << std::endl;
		std::cout << YELLOW << "\n\nTesting sp2: " << RT << sp << std::endl;

		std::cout << YELLOW << "\nDestructors here:" << RT << std::endl;
	}
	std::cout << MAG << "-------------------------" << RT << std::endl;
	
	
	std::cout << "\n\n" << MAG << std::endl;
	std::cout << "----Personal test (7)[operator=()]----" \
		<< RT << std::endl;
	{
		Span sp = Span(10);
		try
		{
			int arr[] = {2, 4, -10, -11, 9, 1, 17, 20, 25, 30};
			std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));

			sp.addNumberGroup(numbers);
			std::cout << "\n---------------------------" << std::endl;
			std::cout << "Value of N: " << sp.getN() << std::endl;
			std::cout << "Vs\n" << "Array Size: " \
				<< sp.getArray_size() << std::endl;
			std::cout << "---------------------------" << std::endl;
			std::cout << "Shortest_span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest_span: " << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RT << std::endl;
		}
		
		//Now copying over
		std::cout << GREEN << "\n\nNow copying over!" << RT << std::endl;
		Span sp2 = sp;
		std::cout << YELLOW << "Testing sp2: " << RT << sp2 << std::endl;

		//Now what happens if we edit one will the other stay the same?
		// to check if it's deep copying not shallow
		std::cout << GREEN \
		<< "Now testing if it was deep or Shallow copy!" << RT << std::endl;
		sp2.clearArray_values();
		std::cout << YELLOW << "Testing sp2(AGAIN): " << RT << sp2 << std::endl;
		std::cout << YELLOW << "\n\nTesting sp2: " << RT << sp << std::endl;

		std::cout << YELLOW << "\nDestructors here:" << RT << std::endl;
	}
	std::cout << MAG << "-------------------------" << RT << std::endl;
	std::cout << "\n\n" << std::endl;
	return (0);
};



























