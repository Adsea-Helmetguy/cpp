/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:13:15 by mlow              #+#    #+#             */
/*   Updated: 2025/03/25 15:13:29 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	counting_total_pair_vector(std::vector<int> &sorter, std::vector<int> &leftover, int power)
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

void	start_recursive_sort_vector(std::vector<int> &sorter, int level)
{
	std::vector<int>	leftover;
	size_t	power = static_cast<size_t>(pow(2, level));

	int	pair_counter = 0;
	pair_counter = counting_total_pair_vector(sorter, leftover, power);
	//std::cout << CYAN << "LEVEL = " << level << RT << std::endl;
	if (pair_counter == 0)
		return ;
	sortinside_pairs_vector(sorter, power, pair_counter);
	start_recursive_sort_vector(sorter, (level + 1));
	sorter = sorting_mainpend_chain_vector(sorter, leftover, power);
};

void	PmergeMe_vector(int argc, char **argv)
{
	std::vector<int>	sorter;

	std::cout << "Before: " << GREEN << argv[1] << RT << std::flush;
	for (int i = 2; i < argc; i++)
		std::cout << " " << GREEN << argv[i] << RT << std::flush;
	std::cout << std::endl;
	pushing_sort_vector(sorter, argc, argv);
	timer_for_recursion_vector(sorter, argc);
};






















