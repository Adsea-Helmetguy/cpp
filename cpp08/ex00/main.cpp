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
#include "easyfind.hpp"

// about iterators: https://www.youtube.com/watch?v=EgVWWVZ6AEY
/*
note, about this code:
std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));

the arr inside here:
("arr" + sizeof---), points to the first element of the array.
*/

int	main(void)
{
	//TEST (1)-std::vector with  int-
	std::cout << "\n\n\n\n---------------------------------" << std::endl;
	std::cout << GREEN << "Test(1) with \"int\" start!!" << RT << std::endl;
	{
		int arr[] = {1, 2, 3, -4, 5};
		std::vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
		int	valueToFind = -4;

		try
		{
			std::cout << "value of easyfind is: \n-" << std::endl;
			std::cout << easyfind(nums, valueToFind) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED << "\nERROR THROWN: \"" << YELLOW \
			<< e.what() << RED << "\"" << RT << std::endl;
		}
		std::cout << "---------------------------------" << std::endl;
	}

	//TEST (2)-std::vector with char-
	std::cout << "\n\n\n\n---------------------------------" << std::endl;
	std::cout << GREEN << "Test(2) with \"ascii_table char\" start!!" << RT << std::endl;
	{
		int arr[] = {'A', 'b', 'W', 'E', 'a'};
		std::vector<char> chars(arr, arr + sizeof(arr) / sizeof(arr[0]));
		int	valueToFind = 97;

		try
		{
			std::cout << "value of easyfind is: \n-" << std::endl;
			std::cout << easyfind(chars, valueToFind) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED << "\nERROR THROWN: \"" << YELLOW \
			<< e.what() << RED << "\"" << RT << std::endl;
		}
		std::cout << "---------------------------------" << std::endl;
	}

	//TEST (3)-std::list with int-
	std::cout << "\n\n\n\n---------------------------------" << std::endl;
	std::cout << GREEN << "Test(3) \"std::list with int\" start!!" << RT << std::endl;
	{
		int arr[] = {1, 2, 3, 4, -5, 6};
		std::list<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
		int	valueToFind = -5;

		try
		{
			std::cout << "value of easyfind is: \n-" << std::endl;
			std::cout << easyfind(nums, valueToFind) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED << "\nERROR THROWN: \"" << YELLOW \
			<< e.what() << RED << "\"" << RT << std::endl;
		}
		std::cout << "---------------------------------" << std::endl;
	}

	//TEST (4)-std::deque with int-
	std::cout << "\n\n\n\n---------------------------------" << std::endl;
	std::cout << GREEN << "Test(4) \"std::deque with int\" start!!" << RT << std::endl;
	{
		int arr[] = {1, 2, 3, 4, -5, 6};
		std::deque<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
		int	valueToFind = -5;

		try
		{
			std::cout << "value of easyfind is: \n-" << std::endl;
			std::cout << easyfind(nums, valueToFind) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED << "\nERROR THROWN: \"" << YELLOW \
			<< e.what() << RED << "\"" << RT << std::endl;
		}
		std::cout << "---------------------------------" << std::endl;
	}

	//TEST (5)-std::vector fail to find-
	std::cout << "\n\n\n\n---------------------------------" << std::endl;
	std::cout << GREEN << "Test(5) purpose to fail!!" << RT << std::endl;
	{
		int arr[] = {'A', 'b', 'W', 'E', 'a'};
		std::vector<char> chars(arr, arr + sizeof(arr) / sizeof(arr[0]));
		int	valueToFind = -5;

		try
		{
			std::cout << "value of easyfind is: \n-" << std::endl;
			std::cout << easyfind(chars, valueToFind) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED << "\nERROR THROWN: \"" << YELLOW \
			<< e.what() << RED << "\"" << RT << std::endl;
		}
		std::cout << "---------------------------------" << std::endl;
	}

	//TEST (6)-it_easyfind (returning iterator instead of int)-
	std::cout << "\n\n\n\n---------------------------------" << std::endl;
	std::cout << GREEN << "Test(6) easyfind returns iterator " \
		<< "instead of int" << RT << std::endl;
	{
		int arr[] = {1, 2, 3, 4, -5, 6};
		std::vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
		int	valueToFind = -5;
		try
		{
			std::cout << "value of easyfind is: \n-" << std::endl;
			std::cout << *it_easyfind(nums, valueToFind) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED << "\nERROR THROWN: \"" << YELLOW \
			<< e.what() << RED << "\"" << RT << std::endl;
		}
		std::cout << "---------------------------------" << std::endl;
	}

	//TEST (7)-it_easyfind (with std::deque)-
	std::cout << "\n\n\n\n---------------------------------" << std::endl;
	std::cout << GREEN << "Test(7) Now With std::deque" << RT << std::endl;
	{
		int arr[] = {1, 2, 3, 4, -5, 6};
		std::deque<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
		int	valueToFind = 3;
		try
		{
			std::cout << "value of easyfind is: \n-" << std::endl;
			std::cout << *it_easyfind(nums, valueToFind) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED << "\nERROR THROWN: \"" << YELLOW \
			<< e.what() << RED << "\"" << RT << std::endl;
		}
		std::cout << "---------------------------------" << std::endl;
	}

	//TEST (8)-it_easyfind (with std::list)-
	std::cout << "\n\n\n\n---------------------------------" << std::endl;
	std::cout << GREEN << "Test(8) Now With std::list" << RT << std::endl;
	{
		int arr[] = {1, 2, 3, 4, -5, 6};
		std::list<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
		int	valueToFind = 4;
		try
		{
			std::cout << "value of easyfind is: \n-" << std::endl;
			std::cout << *it_easyfind(nums, valueToFind) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED << "\nERROR THROWN: \"" << YELLOW \
			<< e.what() << RED << "\"" << RT << std::endl;
		}
		std::cout << "---------------------------------" << std::endl;
	}

	//Not using iterators
	//TEST (Theory 1)-Without using iterators-
	std::cout << "\n\n\n\n---------------------------------" << std::endl;
	{
		std::cout << GREEN << "<Final Test!>\n" << RT << std::endl;
		std::cout << YELLOW << "Without iterators(direct indexing): " << RT << std::endl;
		int arr[] = {1, 2, 3, -4, 5, -6, 7, 8, 9};
		std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));
		int	size = numbers.size();
		
		for (int i = 0; i < size; i++)
		{
			std::cout << "This is number[" << GREEN << i << RT \
				<< "]: \"" << numbers[i] << "\"" << std::endl;
			if (numbers[i] == 8)
				std::cout << GREEN << "AH HA! FOUND IT! IT's ABOVE ME!" \
					<< RT << std::endl;
		}

		std::cout << "\n" << std::endl;
		std::cout << YELLOW << "With iterators(Manual Iterator Loop): " \
			<< RT << std::endl;
		std::vector<int>::iterator	num2;
		unsigned int	i = 0;

		for (num2 = numbers.begin(); num2 != numbers.end(); num2++)
		{
			std::cout << "This is number[" << GREEN << i++ << RT \
				<< "]: \"" << *num2 << "\"" << std::endl;
			if (*num2 == 8)
				std::cout << GREEN << "AH HA! FOUND IT! IT's ABOVE ME!" \
					<< RT << std::endl;
		}
	}

	//With iterators
	//TEST (Theory 1.5)-How does iterators workin easyfind?-
	{
		std::cout << "\n" << std::endl;
		std::cout << YELLOW << "Algorithm command" \
			"(element with a single command): " << RT << std::endl;
		int array[] = {1, 2, 3, -4, 5, -6, 7, 8, 9};
		std::vector<int> numbers(array, array + sizeof(array) / sizeof(array[0]));
		unsigned int	ValueToFind = 8;
		std::vector<int>::iterator	found;
		
		found = std::find(numbers.begin(), numbers.end(), ValueToFind);
		if (found != numbers.end())
		{
			std::cout << "AH HA! FOUND VALUE: \"" << ValueToFind \
				<< "\"! IT's AT INDEX->[" << GREEN \
				<< std::distance(numbers.begin(), found) << RT << "]" << std::endl;
		}
		else
			std::cout << RED << "Value: \"" << ValueToFind \
				<< "\" not found!" << RT << std::endl;
		std::cout << "---------------------------------" << std::endl;
	}
	std::cout << "\n\n" << std::endl;
	return (0);
};

