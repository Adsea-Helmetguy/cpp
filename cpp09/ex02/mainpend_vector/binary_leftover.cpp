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

size_t	binary_search_leftover_vector(std::vector<long long>& main, size_t start, size_t end, int insert_element, size_t pair_size)
{
	size_t	binary_location = 0;	
	size_t	total_pairs_inrange = ((end - start + 1) / pair_size);

	if (total_pairs_inrange == 1)
		total_pairs_inrange = 2;
	
	size_t	midpoint = start + ((total_pairs_inrange / 2) * pair_size) - 1;
	if (total_pairs_inrange == 1 && midpoint < main.size())
	{
		if (insert_element > main[midpoint])
			return (start);
	}
	if (start + (pair_size - 1) >= end)
		return (start);
	num_comparison++;
	if (insert_element < main[midpoint])
		return binary_search_leftover_vector(main, start, midpoint, insert_element, pair_size);
	else
		return binary_search_leftover_vector(main, midpoint + 1, end, insert_element, pair_size);
	return (binary_location);
};

void	add_leftover_vector(std::vector<long long> &main, std::vector<long long> &leftover, size_t &pair_size)
{
	size_t	binary_location = 0;
	size_t	endpoint = (main.size());

	if (!leftover.empty())
	{
		binary_location = (binary_search_leftover_vector(main, 0, endpoint, leftover[pair_size - 1], pair_size));
		main.insert(main.begin() + binary_location, leftover.begin(), leftover.end());
	}
};

