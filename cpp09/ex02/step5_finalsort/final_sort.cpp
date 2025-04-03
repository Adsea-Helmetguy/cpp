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

size_t	jacob_number(size_t	n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacob_number(n - 1) + 2 * jacob_number(n - 2));
};

static size_t	highest_jacob_ft(std::vector<int> &leftover)
{
	size_t	highest_jacob = 0;

	while (jacob_number(highest_jacob) < leftover.size())
		highest_jacob++;
	if (jacob_number(highest_jacob) > leftover.size())
		highest_jacob--;
	std::cout << GREEN << "\n\nHighest Jacobsthal number(" << highest_jacob << ") is: " \
		<< YELLOW << jacob_number(highest_jacob) << RT << " |vs| " << GREEN \
		<< "leftover.size(): " << YELLOW << leftover.size() << RT << std::endl;
	return (highest_jacob);
};

//binary_search used here to do ford johnson's algo while leftover/pendchain still have values:
void	binary_search(std::vector<int> &sorter, std::vector<int> &leftover)
{
	size_t	start = 0;
	size_t	end = sorter.size() - 1;
	size_t	mid = (start + end) / 2;
	size_t	numbers_to_insert = leftover.size();

	//doing binary_search
};

void	final_sort(std::vector<int> &sorter, std::vector<int> &leftover)
{
	size_t	working = 1;
	size_t	previous_n = 1;
	size_t	current_n = 3;
	size_t	highest_jacob = highest_jacob_ft(leftover);

	if (!leftover.empty())
	{
		sorter.insert((sorter.begin()), leftover.front());//a1 & b1
		std::cout << "Jacob's n(" << current_n << "): " << jacob_number(current_n) << std::endl;
		binary_search(sorter, leftover);
	}

	print_mainchain(sorter);
	print_pendchain(leftover);
};
























