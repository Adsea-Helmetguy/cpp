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

size_t	binary_search_leftover_deque(std::deque<long long>& main, size_t start, size_t end, int insert_element, size_t pair_size)
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
		return binary_search_leftover_deque(main, start, midpoint, insert_element, pair_size);
	else
		return binary_search_leftover_deque(main, midpoint + 1, end, insert_element, pair_size);
	return (binary_location);
};

void	add_leftover_deque(std::deque<long long> &main, std::deque<long long> &leftover, size_t &pair_size)
{
	size_t	binary_location = 0;
	size_t	endpoint = (main.size());

	if (!leftover.empty())
	{
		binary_location = (binary_search_leftover_deque(main, 0, endpoint, leftover[pair_size - 1], pair_size));
		main.insert(main.begin() + binary_location, leftover.begin(), leftover.end());
	}
};


/* return the position of where to insert the insert_element */
size_t	binary_search_ft_deque(std::deque<long long>& main, size_t start, size_t end, int insert_element, size_t pair_size)
{
	if (start + (pair_size - 1) >= end)
		return (start);

	size_t	binary_location = 0;	
	size_t	total_pairs_inrange = ((end - start + 1) / pair_size);
	size_t	midpoint = start + ((total_pairs_inrange / 2) * pair_size) - 1;

	num_comparison++;
	if (insert_element < main[midpoint])
		return binary_search_ft_deque(main, start, midpoint, insert_element, pair_size);
	else
		return binary_search_ft_deque(main, midpoint + 1, end, insert_element, pair_size);
	return (binary_location);
};

void	binaryinsert_mainpend_deque(std::deque<long long> &main, std::deque<long long> &pend, size_t pair_size)
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
				binary_location = (binary_search_ft_deque(main, 0, endpoint, pend[j], pair_size));
				main.insert(main.begin() + binary_location, \
					(pend.begin() + j - (pair_size - 1)), pend.begin() + j + 1);//+1 cause end iterator
				counter++;
			}
			num_of_pairs_inserted += counter;
			counter = 0;
			update_new_jacob(old_jacob, old_jacobsthal, n, jacobsthal);
		}
	}
};

void	adding_mainpend_deque(std::deque<long long> &sorter, std::deque<long long> &main, 
	std::deque<long long> &pend, size_t power)
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

std::deque<long long>	sorting_mainpend_chain_deque(std::deque<long long> &sorter, std::deque<long long> &leftover, \
							size_t power)
{
	std::deque<long long>	main;
	std::deque<long long>	pend;
	size_t	pair_size = power / 2;

	adding_mainpend_deque(sorter, main, pend, power);
	insert_firstpair_deque(main, pend, pair_size);
	binaryinsert_mainpend_deque(main, pend, pair_size);
	add_leftover_deque(main, leftover, pair_size);
	return (main);
};

int	counting_total_pair_deque(std::deque<long long> &sorter, std::deque<long long> &leftover, int power)
{
	int	pair_counter = static_cast<int>(sorter.size());
	size_t	current_leftovers = 0;
	size_t	indexof_leftover = 0;
	size_t	total_sorter_remover = 0;

	pair_counter /= power;
	current_leftovers = sorter.size() % power;
	indexof_leftover = sorter.size() - current_leftovers;
	if (current_leftovers > 0 && (current_leftovers != sorter.size()))
	{
		total_sorter_remover = 0;
		for (size_t i = indexof_leftover; i < sorter.size(); i++)
		{
			leftover.push_back(sorter[i]);
			total_sorter_remover++;
		}
		for (size_t i = 0; i < total_sorter_remover; i++)
			sorter.pop_back();
	}
	return (pair_counter);
};

void	start_recursive_sort_deque(std::deque<long long> &sorter, int level)
{
	std::deque<long long>	leftover;
	size_t	power = static_cast<size_t>(pow(2, level));

	int	pair_counter = 0;
	pair_counter = counting_total_pair_deque(sorter, leftover, power);
	if (pair_counter == 0)
		return ;
	sortinside_pairs_deque(sorter, power, pair_counter);
	start_recursive_sort_deque(sorter, (level + 1));
	sorter = sorting_mainpend_chain_deque(sorter, leftover, power);
};

void	PmergeMe_deque(int argc, char **argv)
{
	std::deque<long long>	sorter;

	std::cout << "Before: " << CYAN << argv[1] << RT << std::flush;
	for (int i = 2; i < argc; i++)
		std::cout << " " << CYAN << argv[i] << RT << std::flush;
	std::cout << std::endl;
	pushing_sort_deque(sorter, argc, argv);
	timer_for_recursion_deque(sorter, argc);
};


















