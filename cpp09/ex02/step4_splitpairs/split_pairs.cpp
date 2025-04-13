/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spilt_pairs.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:59:17 by mlow              #+#    #+#             */
/*   Updated: 2025/04/01 16:00:15 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void	adding_mainpend(std::vector<int> &sorter, std::vector<int> &main, 
			std::vector<int> &pend, size_t power)
{
	size_t	size_loop = 0;

	std::cout << GREEN << "power: " << power << RT << std::endl;
	while (size_loop < sorter.size())
	{
		for (size_t i = (size_loop); i < (size_loop + (power / 2)); i++)//second pair
			pend.push_back(sorter[i]);
		for (size_t i = (size_loop) + (power / 2); i < (size_loop + power); i++)//first pair
			main.push_back(sorter[i]);
		size_loop += (power);
	}
};

//use the power instead of checking every 2 int
static void	add_leftovers(std::vector<int> &pend, 
				std::vector<int> &leftover)
{
	if (!leftover.empty())
	{
		for (size_t i = 0; i < leftover.size(); i++)
			pend.push_back(leftover[i]);
	}
};

void	binary_search_ft(std::vector<int> &main, 
						size_t start, size_t end, int insert_element)
{
	size_t	midpoint = ((start + end) / 2);

	std::cout << RED << "VALUE OF insert_element: \"" << GREEN \
	<< insert_element << RED << "\"" << RT << std::endl;
	if (insert_element < main[midpoint])
	{
		for (size_t loop = midpoint; loop > start; loop--)
		{
			if (insert_element > main[loop])
				main.insert(main.begin() + loop, insert_element);
		}
	}
	(void)main;
	(void)start;
	(void)end;
	(void)insert_element;
};

void	sorting_mainpend_chain(std::vector<int> sorter, 
		std::vector<int> &leftover, size_t power)
{
	size_t	p_by2	= (power / 2);

// ---------------------------elements--------------------------------------
	std::vector<int>	main;
	std::vector<int>	pend;

	size_t	pair_size = 2;
	size_t	binary_location = 0;

	size_t	old_jacob = 1;
	size_t	old_jacobsthal = 1;
	size_t	n = 3;
	size_t	jacobsthal = jacob_number(n);

	//inserted first pair and check if (pend.size() > jacob = 3)
	size_t	num_of_pairs_inserted = 1;
	size_t	endpoint = ((3 + num_of_pairs_inserted) * pair_size) - 1;
	size_t	counter = 0;
// ---------------------------elements--------------------------------------
	adding_mainpend(sorter, main, pend, power);
	
	if (!pend.empty())
	{
		main.insert(main.begin(), pend.begin(), pend.begin() + p_by2);
		for (size_t i = 0; i < p_by2; i++)
			pend[i] = -1;
	}
	for (size_t i = p_by2 - 1; i < pend.size(); i += p_by2)
	{
		std::cout << "value of i: " << i << std::endl;
		for (size_t p = 0; p < pend.size(); p++)
		{
			if (pend[p] != -1)
			{
				binary_search_ft(main, i, (i + p_by2 - 1), pend[i + p_by2 - 1]);
				p = 0;
			}
		}
	}
	//std::cout << RED << "ADDING LEFTOVERS" << RT << std::endl;
	//add_leftovers(pend, leftover);
	//leftover_binary_search_ft2() --for leftovers specially--

	std::cout << YELLOW << "\n====-----Printing values-----====" << RT << std::endl;
	print_vector_pairs(main, power, 0);
	print_vector_pairs(pend, power, 1);
	std::cout << YELLOW << "====-------------------------====\n" << RT << std::endl;
};











/*
std::vector<int> main = { 1, 3, 5, 7, 9, 11, 55, 100 };
	std::vector<int> pend = { 0, 2, 4, 6, 8, 10, 29, 42 };

0 1 2 3 4 5 6 7 8 9 10 11 29 42 100
*/





