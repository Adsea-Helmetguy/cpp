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

//use the power instead of checking every 2 int
static void	sorting_pend(std::vector<int> &sorter, std::vector<int> &pend, int start)
{
	//create starting points, then swap with another based on small big
	size_t	power = start;
	size_t	index = 0;
	std::vector<int>	main;

	//level 3 atm power should be 8
	//this power tells me the size of the pair
	//size of this pair == 8. What to do now?
	if (sorter[(power / 2) - 1] >  sorter[power - 1])
	{
		for (size_t i = (power / 2); i < power; i++)//first pair
		{
			main.push_back(sorter[i]);
			std::cout << YELLOW << "Pushing sorter[" << i << "] = " << sorter[i] \
				<< " | Now in main: " << main[index++] << RT << std::endl;
		}
		index = 0;
		for (int i = 0; i < static_cast<int>(power / 2); i++)//second pair
		{
			pend.push_back(sorter[i]);
			std::cout << CYAN << "Pushing sorter[" << i << "] = " << sorter[i] \
				<< " | Now in pend: " << pend[index++]  << RT << std::endl;
		}
	}
	std::cout << YELLOW << "\n====-----Printing values-----====" << RT << std::endl;
	print_mainchain(main);
	print_pendchain(pend);
	std::cout << YELLOW << "====-------------------------====\n" << RT << std::endl;
};

//now add unsorted values from sorter and put them inside pendchain
//chain1(main) vs chain2(pending chain)<- most likely the leftovers
//for (int i = static_cast<int>(sorter.size() - 1); (i > -1); i--)
void	sorting_mainpend_chain(std::vector<int> sorter, 
				std::vector<int> &leftover, std::vector<int> &pend, int power)
{
//	static int	main_sort = 0;

	//if (main_sort++ == 0)
	sorting_pend(sorter, pend, power);
	for (size_t i = 0; i < leftover.size(); i++)
		pend.push_back(leftover[i]);

	//std::cout << YELLOW << "\n====----Printing values[" << "]----====" << RT << std::endl;
	//print_mainchain(sorter);
	//print_pendchain(pend);
	//std::cout << YELLOW << "====-----------------------====\n\n\n\n" << RT << std::endl;
	//final_sort(sorter, pend);
};

















