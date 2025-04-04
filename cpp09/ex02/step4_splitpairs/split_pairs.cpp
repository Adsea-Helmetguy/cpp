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
		//pend
		for (size_t i = (size_loop); i < (size_loop + (power / 2)); i++)//second pair
		{
			pend.push_back(sorter[i]);
		}
		//main
		for (size_t i = (size_loop) + (power / 2); i < (size_loop + power); i++)//first pair
		{
			main.push_back(sorter[i]);
		}
		size_loop += (power);
	}
};

static void	main_pend_sort(std::vector<int> &main, std::vector<int> &pend, size_t power)
{
	std::vector<int>	main2;
	std::vector<int>	pend2;
	size_t	size_loop = 0;

	if (power > 2)
	{
		std::cout << GREEN << "Comparing which is main inside pend--->\n" << \
			"pend[" << (power / 2) - 1 << "]: (" << pend[(power / 2) - 1] \
			<< ")\n--vs--\npend[" << power - 1 << "]: (" \
			<< pend[power - 1] << ")" << std::endl;
		std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
		std::cout << GREEN << "Comparing which is main inside main's--->\n" << \
			"main[" << (power / 2) - 1 << "]: (" << main[(power / 2) - 1] \
			<< ")\n--vs--\nmain[" << power - 1 << "]: (" \
			<< main[power - 1] << ")" << std::endl;
	}
	while (size_loop < power)
	{
		//pend
		for (size_t i = (size_loop); i < (size_loop + (power / 2)); i++)//second pair
		{
			pend2.push_back(main[i]);
		}
	}
	(void)main;
	(void)pend;
};

//use the power instead of checking every 2 int
static void	sorting_working(std::vector<int> &sorter, size_t power)
{
	static std::vector<int>	main;
	static std::vector<int>	pend;
	static	int once = 0;

	std::cout << "\n>>>---------------------------->>>\n" << std::flush;
	std::cout << GREEN << "STARTING WITH POWER OF \"" << YELLOW << power \
		<< GREEN << "\"" << RT << std::endl;
	if (main.empty() && pend.empty() && once++ == 0)
		adding_mainpend(sorter, main, pend, power);
	else
		main_pend_sort(main, pend, power);
	std::cout << YELLOW << "\n====-----Printing values-----====" << RT << std::endl;
	print_pendchain(pend);
	print_mainchain(main);
	std::cout << YELLOW << "====-------------------------====\n" << RT << std::endl;
};

//now add unsorted values from sorter and put them inside pendchain
//chain1(main) vs chain2(pending chain)<- most likely the leftovers
//for (int i = static_cast<int>(sorter.size() - 1); (i > -1); i--)
void	sorting_mainpend_chain(std::vector<int> sorter, 
		std::vector<int> &leftover, std::vector<int> &pend, size_t power)
{
//	static int	main_sort = 0;
	(void)pend;
	//if (main_sort++ == 0)
	sorting_working(sorter, power);
	for (size_t i = 0; i < leftover.size(); i++)
		pend.push_back(leftover[i]);

	//std::cout << YELLOW << "\n====----Printing values[" << "]----====" << RT << std::endl;
	//print_mainchain(sorter);
	//print_pendchain(pend);
	//std::cout << YELLOW << "====-----------------------====\n\n\n\n" << RT << std::endl;
	//final_sort(sorter, pend);
};

















