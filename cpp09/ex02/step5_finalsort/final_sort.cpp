/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:33:29 by mlow              #+#    #+#             */
/*   Updated: 2025/04/02 12:38:22 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	final_sort(std::vector<int> &sorter, std::vector<int> &leftover)
{
	int	compare = 0;//use this to increast the sorter.begin()!

	//add the b1 before the a1
	std::cout << GREEN << "\n\n\n\nFINAL PUSH!!!!" << RT << std::endl;
	if (!leftover.empty())
		sorter.insert(sorter.begin(), leftover.front());
	print_mainchain(sorter);
	print_pendchain(leftover);
};
