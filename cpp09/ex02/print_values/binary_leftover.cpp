/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_leftover.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:45:28 by mlow              #+#    #+#             */
/*   Updated: 2025/04/14 16:45:44 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
need to pass:
test1)
0 14 1 9 3 11 12 8 6 16 5 15 17 13 19 10 18 2 20 4 7

2)
7 12 18 10 8 16 13 14 11 5 9 4 20 2 1 19 17 3 6 15 0

3)
clear && make && clear && ./PmergeMe 20 19 6 5 13 3 12 1 15 14 16 4 2 7 11 10 17 9 0 18 8

4)
clear && make && clear && ./PmergeMe 14 19 5 18 3 10 13 4 1 11 8 2 15 9 6 12 20 0 16 7 17

5)
clear && make && clear && ./PmergeMe 17 6 16 1 2 5 8 13 7 14 4 3 18 9 11 19 12 15 10 0 20

6)
clear && make && clear && ./PmergeMe 10 14 15 17 7 19 20 5 2 6 16 3 9 18 11 12 1 13 0 4 8

7)
clear && make && clear && ./PmergeMe 0 8 10 3 4 6 13 7 15 12 19 11 16 1 20 18 17 9 2 5 14
*/

void	leftover_jacob(size_t &old_jacob, size_t &old_jacobsthal, size_t &n, size_t &jacobsthal)
{
	old_jacob = n;
	old_jacobsthal = jacobsthal;
	jacobsthal = jacob_number(++n);
};

size_t	binary_search_leftover(std::vector<int>& main, size_t start, size_t end, int insert_element, size_t pair_size)
{
	size_t	binary_location = 0;	
	size_t	total_pairs_inrange = ((end - start + 1) / pair_size);

	if (total_pairs_inrange == 1)
		total_pairs_inrange = 2;
	
	size_t	midpoint = start + ((total_pairs_inrange / 2) * pair_size) - 1;

	std::cout << RED << "INSERT_ELEMENT = " << insert_element << RT << std::endl;
	std::cout << YELLOW << "  Start = " << start << " | end = " << end << std::endl;
	std::cout << "  Midpoint = " << midpoint << std::endl;
	std::cout << "  VALUE OF main[" << midpoint << "] = " << main[midpoint] << RT << std::endl;



//main woking for LEFTOVERS "HERE"
//	return values determines the location where the value is placed?
// ---------------------------------------------- ------------------------------------------------------

	std::cout << RED << "Midpoint" << " = " << RT << midpoint << std::endl;
	if (total_pairs_inrange == 1 && midpoint < main.size())
	{
		std::cout << CYAN << "start + pair_size = " << start + pair_size << std::flush;
		std::cout << " | insert(" << insert_element << ") vs main[" << midpoint << "] = " << main[midpoint] << RT << std::endl;
		if (insert_element > main[midpoint])
			return (start);
	}

	if (start + (pair_size - 1) >= end)
		return (start);



// ---------------------------------------------- ------------------------------------------------------



	num_comparison++;
	if (insert_element < main[midpoint])
		return binary_search_leftover(main, start, midpoint, insert_element, pair_size);
	else
		return binary_search_leftover(main, midpoint + 1, end, insert_element, pair_size);
	return (binary_location);
};

void	add_leftover(std::vector<int> &main, std::vector<int> &leftover, size_t &pair_size)
{
	size_t	binary_location = 0;
	size_t	endpoint = (main.size());

	if (!leftover.empty())
	{
		binary_location = (binary_search_leftover(main, 0, endpoint, leftover[pair_size - 1], pair_size));
		main.insert(main.begin() + binary_location, leftover.begin(), leftover.end());
		//convert_pend_to_negative(leftover, 0, 1, pair_size);
	}
};

