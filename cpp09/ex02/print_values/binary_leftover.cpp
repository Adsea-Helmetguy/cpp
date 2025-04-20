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
	size_t	binary_location = 0;	
	size_t	total_pairs_inrange = ((end - start + 1) / pair_size);
	size_t	midpoint = start + ((total_pairs_inrange / 2) * pair_size) - 1;

	//std::cout << CYAN << "Mid" << RED << "point" << YELLOW << " = " << midpoint << RT << std::endl;

	//std::cout << RED << "Start = " << start << " | end = " << end << std::endl;
	//std::cout << "Midpoint = " << midpoint << std::endl;
	//std::cout << "VALUE OF main[" << midpoint << "] = " << main[midpoint] << RT << std::endl;
	if (total_pairs_inrange == 1 && midpoint < main.size())
	{
		if (insert_element > main[midpoint])
			return (start + pair_size);
	}
	if (start + (pair_size - 1) >= end)
		return (start);
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
	size_t	endpoint = (main.size() - 1);

	if (!leftover.empty())
	{
		binary_location = (binary_search_leftover(main, 0, endpoint, leftover[pair_size - 1], pair_size));
		main.insert(main.begin() + binary_location, leftover.begin(), leftover.end());
		//convert_pend_to_negative(leftover, 0, 1, pair_size);
	}
};

