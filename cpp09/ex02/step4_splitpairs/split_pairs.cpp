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
	std::cout << "Inside the sorter, Main Chain->" << std::endl;
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
	std::cout << "\nInside the leftover, Pend Chain->" << std::endl;
	if (leftover.empty())
		return ;
	for (size_t i = 0; i < leftover.size(); i++)
	{
		std::cout << "Pend chain[" << CYAN << i << RT << "] = " \
			<< GREEN << leftover[i] << RT << std::endl;
	}
};

//now add unsorted values from sorter and put them inside pendchain
//chain1(main) vs chain2(pending chain)<- most likely the leftovers
void	sorting_mainpend_chain(std::vector<int> &sorter, std::vector<int> &leftover)
{
	std::cout << RED << "\n\nTesting \"num % 2\" == " << RT << 2 % 2 << std::endl;
	for (int i = static_cast<int>(sorter.size() - 1); (i > -1); i--)
	{
		if (i % 2 == 0)
		{
			std::cout << "Value i am looking at: Main chain[" << CYAN << i << RT \
				<< "] = " << sorter[i] << std::endl;
			leftover.push_back(sorter[i]);
			sorter.erase(sorter.begin() + i);
		}
	}
	//since the leftovers are not in correct order, reverse vector!
	std::reverse(leftover.begin(), leftover.end());
	std::cout << YELLOW << "\n====----Printing values----====" << RT << std::endl;
	print_mainchain(sorter);
	print_pendchain(leftover);
	std::cout << YELLOW << "====----Printing ending----====" << RT << std::endl;
};

















