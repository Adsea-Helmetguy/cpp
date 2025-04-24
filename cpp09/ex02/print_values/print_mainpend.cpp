/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mainpend.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:45:55 by mlow              #+#    #+#             */
/*   Updated: 2025/04/14 16:46:00 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	print_vector_pairs(std::vector<long long>& vector, size_t pair_size, int mp)
{
/*
	size_t	loop = 0;

	if (mp == 0)
		std::cout << RED << "MAIN" << RT << std::endl;
	else if (mp == 1)
		std::cout << RED << "Leftovers" << RT << std::endl;
	else if (mp == 2)
		std::cout << RED << "PEND" << RT << std::endl;

	std::cout << YELLOW << "(" << RT << std::flush;
	for (std::vector<long long>::iterator it = vector.begin(); it != vector.end(); it++)
	{
		if (loop != 0 && loop % pair_size == 0)
			std::cout << YELLOW << ") (" << RT << std::flush;
		std::cout << *it << std::flush;
		if ((loop + 1) % pair_size != 0 && (loop < vector.size() - 1))
			std::cout << ", " << std::flush;
		loop++;
	}
	std::cout << YELLOW << ")" << RT << std::endl;
*/
	(void)vector;
	(void)pair_size;
	(void)mp;
}

void	comparing_startVend(std::vector<long long>& main, size_t start, size_t end, size_t pair_size)
{
/*
	std::cout << YELLOW << "  Comparing (start[" << RT << std::flush;
	
	for (size_t i = 0; i != (start + pair_size); i++)
	{
		std::cout << i << std::flush;
		if ((i + 1) != (start + pair_size))
			std::cout << ", " << std::flush;
	}
	std::cout << YELLOW << "] = (" << RT << std::flush;
	for (size_t i = 0; i < (start + pair_size); i++)
	{
		std::cout << main[i] << std::flush;
		if ((i + 1) != (start + pair_size))
			std::cout << ", " << std::flush;
	}
	std::cout << YELLOW << ")" << RT << std::flush;

	std::cout << YELLOW << " || " << "end[" << RT << std::flush;
	for (size_t i = end - (pair_size - 1); i < end + 1; i++)
	{
		std::cout << i << std::flush;
		if ((i + 1) != end + 1)
			std::cout << ", " << std::flush;
	}
	std::cout << YELLOW << "] = (" << RT << std::flush;
	for (size_t i = end - (pair_size - 1); i < end + 1; i++)
	{
		std::cout << main[i] << std::flush;
		if ((i + 1) != end + 1)
			std::cout << ", " << std::flush;
	}
	std::cout << YELLOW << ")" << RT << std::endl;
*/
	(void)main;
	(void)start;
	(void)end;
	(void)pair_size;
};

void	print_mainpend(std::vector<long long> &main, \
		std::vector<long long> &pend, size_t pair_size, size_t before_after)
{
/*
	if (before_after == 0)
	{
		std::cout << "------<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" \
			<< std::endl;
		std::cout << GREEN << "---->BEFORE: " << RT << std::endl;
	}
	else if (before_after == 1)
	{
		std::cout << GREEN << "\n---->AFTER: " << RT << std::endl;
	}
*/
	print_vector_pairs(main, pair_size, 0);
	print_vector_pairs(pend, pair_size, 2);
	(void)before_after;
};
