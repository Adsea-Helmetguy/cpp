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

	if (total_pairs_inrange == 1 && (insert_element > main[midpoint]) && midpoint < main.size())
	{
		std::cout << RED << "total_pairs_inrange = " << total_pairs_inrange << RT << std::endl;
		std::cout << RED << "midpoint = " << midpoint << RT << std::endl;
		std::cout << RED << "STARTpt = " << start << " vs ENDpoint = " \
			<< end << RT << std::endl;
		std::cout << RED << "Insert Element = " << insert_element \
			<< " vs main[midpoint] = " << main[midpoint] << RT << std::endl;
		return (start + pair_size);
	}
	//else if (total_pairs_inrange == 1 && (insert_element < main[midpoint]))
	//	return (start);

	std::cout << CYAN << "Start = " << start << " vs end = " << end << " | pair_size = " << pair_size << RT << std::endl;
	if (start + (pair_size - 1) >= end)
			return (start);

	std::cout << YELLOW << "    Total pair_size in this range: " << total_pairs_inrange << RT << std::endl;
	std::cout << YELLOW << "    midpoint[" << midpoint << "] = " << RT << main[midpoint] << std::endl;
	std::cout << YELLOW << "    Insert_element(" << insert_element \
		<< ") vs main[midpoint](" << main[midpoint] << ")." << RT << std::endl;
	if (insert_element < main[midpoint])
	{
		std::cout << YELLOW << "Going with startpoint = midpoint" << RT << std::endl;
		return binary_search_leftover(main, start, midpoint, insert_element, pair_size);
	}
	else
	{
		std::cout << RED << "Going with endpoint = midpoint + 1" << RT << std::endl;
		return binary_search_leftover(main, midpoint + 1, end, insert_element, pair_size);
	}
	return (binary_location);
};

void	add_leftover(std::vector<int> &main, std::vector<int> &leftover, size_t &pair_size)
{
	size_t	binary_location = 0;
	size_t	endpoint = (main.size() - 1);

	std::cout << GREEN << "------>BEFORE adding leftovers--" << RT << std::endl;
	print_vector_pairs(main, pair_size, 0);
	print_vector_pairs(leftover, pair_size, 1);
	std::cout << std::endl;
	//endpoint = ((n + num_of_pairs_inserted) * pair_size) - 1;
	if (!leftover.empty())
	{
		binary_location = (binary_search_leftover(main, 0, endpoint, leftover[pair_size - 1], pair_size));
		main.insert(main.begin() + binary_location, leftover.begin(), leftover.end());
		//main.insert(main.begin(), leftover.begin(), leftover.begin() + pair_size);
		convert_pend_to_negative(leftover, 0, 1, pair_size);
	}
};

