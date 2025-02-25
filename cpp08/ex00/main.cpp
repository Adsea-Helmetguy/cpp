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

// about iterators:
//https://www.youtube.com/watch?v=EgVWWVZ6AEY
int	main(void)
{
	std::cout << GREEN << "easyfind start!" << RT << std::endl;
	{
		//-----------------------------------------------------
		std::cout << "Without iterators: " << std::endl;
		int arr[] = {1, 2, 3, 4, 5};
		std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0])); 
		int	size = numbers.size();
		//int	value = 4;
		
		for (int i = 0; i < size; i++)
		{
			std::cout << "This is number[" << GREEN << i << RT \
				<< "]: \"" << numbers[i] << "\"" << std::endl;
		}
		//-----------------------------------------------------



		//-----------------------------------------------------
		std::cout << "With iterators: " << std::endl;
		std::vector<int>::iterator	num2;
		for (num2 = numbers.begin(); num2 != numbers.end(); num2++)
		{
			std::cout << *num2 << std::endl;
		}
		//-----------------------------------------------------
	}
	return 0;
};

