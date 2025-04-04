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

void	print_mainchain(std::vector<int> &sorter)
{
	std::cout << "Inside the Main Chain->" << std::endl;
	if (sorter.empty())
		return ;
	for (size_t i = 0; i < sorter.size(); i++)
	{
		std::cout << "Main chain[" << CYAN << i << RT << "] = " \
			<< GREEN << sorter[i] << RT << std::endl;
	}
};

void	print_pendchain(std::vector<int> &leftover)
{
	std::cout << "\nInside the Pend Chain->" << std::endl;
	if (leftover.empty())
		return ;
	for (size_t i = 0; i < leftover.size(); i++)
	{
		std::cout << "Pend chain[" << CYAN << i << RT << "] = " \
			<< GREEN << leftover[i] << RT << std::endl;
	}
};

static void	adding_mainpend(std::vector<int> &sorter, std::vector<int> &main, 
			std::vector<int> &pend, size_t power)
{
	size_t	size_loop = 0;

	std::cout << GREEN << "sorter[(power / 2) - 1]: " << RT << sorter[(power / 2) - 1] \
		<< GREEN << " |vs| sorter[power - 1]: " << RT << sorter[power - 1] << std::endl;
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

static void	binary_search_ft(std::vector &main, 
					std::vector &pend, size_t power)
{
	size_t	jacob = 3;

	//first set b1 can be thrown into a1
	if (!pend.empty())
	{
		//use power here! to push first pair into main
	}
	for (size_t i = 0; i < pend.size(); i++)
	{
		
	}
};

void	sorting_mainpend_chain(std::vector<int> sorter, 
		std::vector<int> &leftover, size_t power)
{
	std::vector<int>	main;
	std::vector<int>	pend;

	adding_mainpend(sorter, main, pend, power);
	binary_search_ft(main, pend, power);
	//add_leftovers(pend, leftover);
	//leftover_binary_search_ft2() --for leftovers specially--

	std::cout << YELLOW << "\n====-----Printing values-----====" << RT << std::endl;
	print_pendchain(pend);
	print_mainchain(main);
	std::cout << YELLOW << "====-------------------------====\n" << RT << std::endl;
};

















