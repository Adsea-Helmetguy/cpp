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

/* return the position of where to insert the insert_element */
size_t	binary_search_ft_vector(std::vector<long long>& main, size_t start, size_t end, int insert_element, size_t pair_size)
{
	if (start + (pair_size - 1) >= end)
		return (start);

	size_t	binary_location = 0;	
	size_t	total_pairs_inrange = ((end - start + 1) / pair_size);
	size_t	midpoint = start + ((total_pairs_inrange / 2) * pair_size) - 1;

	num_comparison++;
	if (insert_element < main[midpoint])
		return binary_search_ft_vector(main, start, midpoint, insert_element, pair_size);
	else
		return binary_search_ft_vector(main, midpoint + 1, end, insert_element, pair_size);
	return (binary_location);
};

void	binaryinsert_mainpend_vector(std::vector<long long> &main, std::vector<long long> &pend, size_t pair_size)
{
	size_t	binary_location = 0;
	size_t	old_jacob = 1;
	size_t	old_jacobsthal = 1;
	size_t	n = 3;
	size_t	jacobsthal = jacob_number(n);
	size_t	num_of_pairs_inserted = 1;
	size_t	endpoint = ((3 + num_of_pairs_inserted) * pair_size) - 1;
	size_t	counter = 0;

	if (!main.empty() && !pend.empty())
	{
		while (num_of_pairs_inserted < (pend.size() / pair_size))
		{
			for (size_t j = (jacobsthal * pair_size) - 1;
				j > (old_jacobsthal * pair_size) - 1; j -= pair_size)
			{
				if (j > (pend.size() - 1))
					j = (pend.size() - 1);
				//
				//std::cout << YELLOW << "\nstarting at pend[" << RT << j << YELLOW << "] = " << RT << pend[j] << std::endl;
				//
				endpoint = ((jacobsthal + num_of_pairs_inserted) * pair_size) - 1;
				if (endpoint > main.size() - 1)
					endpoint = main.size() - 1;
				//std::cout << CYAN << "ENDPT = " << endpoint << RT << std::endl;
				//std::cout << "main SIZE-> " << main.size() << " vs pend.size()" << pend.size() << std::endl;
				//std::cout << CYAN << "jacobsthal = " << jacobsthal << " | j = " << j << RT << std::endl;
				binary_location = (binary_search_ft_vector(main, 0, endpoint, pend[j], pair_size));
				main.insert(main.begin() + binary_location, \
					(pend.begin() + j - (pair_size - 1)), pend.begin() + j + 1);//+1 cause end iterator
				counter++;
			}
			num_of_pairs_inserted += counter;
			counter = 0;
			update_new_jacob(old_jacob, old_jacobsthal, n, jacobsthal);
			print_mainpend(main, pend, pair_size, 1);
		}
	}
};

void	adding_mainpend_vector(std::vector<long long> &sorter, std::vector<long long> &main, 
	std::vector<long long> &pend, size_t power)
{
	size_t	size_loop = 0;

	//std::cout << GREEN << "RESCURSIVE power: " << power << RT << std::endl;
	while (size_loop < sorter.size())
	{
		for (size_t i = (size_loop); i < (size_loop + (power / 2)); i++)//second pair
			pend.push_back(sorter[i]);
		for (size_t i = (size_loop) + (power / 2); i < (size_loop + power); i++)//first pair
			main.push_back(sorter[i]);
		size_loop += (power);
	}
};

std::vector<long long>	sorting_mainpend_chain_vector(std::vector<long long> &sorter, std::vector<long long> &leftover, \
							size_t power)
{
	std::vector<long long>	main;
	std::vector<long long>	pend;
	size_t	pair_size = power / 2;

	adding_mainpend_vector(sorter, main, pend, power);
	insert_firstpair_vector(main, pend, pair_size);
	binaryinsert_mainpend_vector(main, pend, pair_size);
	add_leftover_vector(main, leftover, pair_size);
	//std::cout << YELLOW << "\n====-----Printing values-----====" << RT << std::endl;
	//print_vector_pairs(main, pair_size, 0);
	//print_vector_pairs(pend, pair_size, 2);
	//print_vector_pairs(leftover, pair_size, 1);
	//std::cout << YELLOW << "====-------------------------====\n\n\n\n\n" << RT << std::endl;
	return (main);
};