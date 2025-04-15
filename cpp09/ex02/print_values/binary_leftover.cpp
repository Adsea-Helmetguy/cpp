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

void	leftover_jacob(size_t &old_jacob, size_t &old_jacobsthal, \
					size_t &n, size_t &jacobsthal)
{
	old_jacob = n;
	old_jacobsthal = jacobsthal;
	jacobsthal = jacob_number(++n);
};

size_t	binary_search_leftover(std::vector<int>& main, size_t start, size_t end, int insert_element, size_t pair_size)
{
	static	int loop = 1;
	std::cout << "Start = " << start << " vs end = " << end << std::endl; 
	//if (start + (pair_size - 1) >= end)
	if (loop++ > 3)
		return (start);

	size_t	binary_location = 0;	
	size_t	total_pairs_inrange = ((end - start + 1) / pair_size);
	size_t	midpoint = start + ((total_pairs_inrange / 2) * pair_size) - 1;
	if (total_pairs_inrange == 1)
	{
		midpoint = start + pair_size -1;
	}

	//comparing_startVend(main, start, end, pair_size);

	std::cout << CYAN << "    Total pair_size in this range: " << RT << total_pairs_inrange << std::endl;
	std::cout << YELLOW << "    midpoint[" << midpoint << "] = " << RT << main[midpoint] << std::endl;
	std::cout << YELLOW << "   Insert_element(" << insert_element \
		<< ") vs main[midpoint](" << main[midpoint] << ")." << RT << std::endl;
	if (insert_element < main[midpoint])
		return binary_search_leftover(main, start, midpoint, insert_element, pair_size);
	else
		return binary_search_leftover(main, midpoint + 1, end, insert_element, pair_size);
	return (binary_location);
};

void	add_leftover(std::vector<int> &main, std::vector<int> &leftover, size_t &pair_size)
{
	size_t	binary_location = 0;
	size_t	endpoint = (main.size() - 1);

	//endpoint = ((n + num_of_pairs_inserted) * pair_size) - 1;
	if (!leftover.empty())
	{
		binary_location = (binary_search_leftover(main, 0, endpoint, leftover[pair_size - 1], pair_size));
		main.insert(main.begin() + binary_location, 
				leftover.begin(), leftover.begin() + pair_size);//+1 cause end iterator
		//main.insert(main.begin(), leftover.begin(), leftover.begin() + pair_size);
		convert_pend_to_negative(leftover, 0, 1, pair_size);
	}
	std::cout << GREEN << "Inserting first pairs into main!" << RT << std::endl;
	print_vector_pairs(main, pair_size, 0);
	print_vector_pairs(leftover, pair_size, 2);
};


/*
void	binaryinsert_leftover(std::vector<int> &main, std::vector<int> &leftover, size_t pair_size)
{
	// ---------------------------elements--------------------------------------
	size_t	old_jacob = 1;
	size_t	old_jacobsthal = 1;
	size_t	n = 3;
	size_t	jacobsthal = jacob_number(n);

	size_t	num_of_pairs_inserted = 0;
	size_t	binary_location = 0;
	size_t	endpoint = (main.size() - 1);
	size_t	counter = 0;
	// ---------------------------elements--------------------------------------

	//first order of business, update jacobsthal to the highest available value to compare
	std::cout << GREEN << "n = " << n << " | Jacobsthal = " << jacobsthal << RT << std::endl;
	//begin compare with end based on pairs
	add_leftover(main, leftover, pair_size);
	//working copy from 'binaryinsert_mainpend'

	(void)old_jacob;
	(void)old_jacobsthal;

	(void)main;
	(void)leftover;
	(void)pair_size;

	(void)num_of_pairs_inserted;
	(void)binary_location;
	(void)endpoint;
	(void)counter;

};
*/