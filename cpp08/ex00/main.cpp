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

int	main(void)
{
	//For iterators
	std::cout << GREEN << "\n\n\n\nTesting iterators!" << RT << std::endl;
	{
		//-----------------------------------------------------
		std::cout << "Without iterators: " << std::endl;
		int arr[] = {1, 2, 3, 4, 5};
		std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0])); 
		int	size = numbers.size();
		
		for (int i = 0; i < size; i++)
		{
			std::cout << "This is number[" << GREEN << i << RT \
				<< "]: \"" << numbers[i] << "\"" << std::endl;
		}
		//-----------------------------------------------------



		std::cout << "\n\n---------------------------------\n\n" \
			<< std::endl;



		//-----------------------------------------------------
		std::cout << "With iterators: " << std::endl;
		std::vector<int>::iterator	num2;
		for (num2 = numbers.begin(); num2 != numbers.end(); num2++)
		{
			std::cout << *num2 << std::endl;
		}
		//-----------------------------------------------------
	}












	//TEST (1)
	std::cout << GREEN << "\n\n\n\nTest(1) easyfind start!" << RT << std::endl;
	{
		//-----------------------------------------------------
		std::cout << "Easyfind function: " << std::endl;
		int arr[] = {1, 2, 3, 4, 5};
		std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0])); 
		int	valueToFind = 4;
		try
		{
			std::cout << "value of easyfind is: \"" << GREEN \
			<< easyfind(numbers, valueToFind) << RT << "\"" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED << "ERROR THROWN: \"" << YELLOW \
			<< e.what() << RED << "\"" << RT << std::endl;
		}
		//-----------------------------------------------------
	}
	std::cout << "\n\n" << std::endl;
	return 0;
};

