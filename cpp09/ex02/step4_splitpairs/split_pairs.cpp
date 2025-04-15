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

static void	adding_mainpend(std::vector<int> &sorter, std::vector<int> &main, 
			std::vector<int> &pend, size_t power)
{
	size_t	size_loop = 0;

	std::cout << GREEN << "RESCURSIVE power: " << power << RT << std::endl;
	while (size_loop < sorter.size())
	{
		for (size_t i = (size_loop); i < (size_loop + (power / 2)); i++)//second pair
			pend.push_back(sorter[i]);
		for (size_t i = (size_loop) + (power / 2); i < (size_loop + power); i++)//first pair
			main.push_back(sorter[i]);
		size_loop += (power);
	}
};

void	binaryinsert_mainpend(std::vector<int> &main, std::vector<int> &pend, size_t pair_size)
{
// ---------------------------elements--------------------------------------
	size_t	binary_location = 0;

	size_t	old_jacob = 1;
	size_t	old_jacobsthal = 1;
	size_t	n = 3;
	size_t	jacobsthal = jacob_number(n);

	//inserted first pair and check if (pend.size() > jacob = 3)
	size_t	num_of_pairs_inserted = 1;
	size_t	endpoint = ((3 + num_of_pairs_inserted) * pair_size) - 1;
	size_t	counter = 0;
// ---------------------------elements--------------------------------------

	if (!main.empty() && !pend.empty())
	{
		while (num_of_pairs_inserted < (pend.size() / pair_size))//create a while loop to --
		{
			for (size_t j = (jacobsthal * pair_size) - 1;
				j > (old_jacobsthal * pair_size) - 1; j -= pair_size)
			{
				if (j > (pend.size() - 1))
					j = (pend.size() - 1);
				std::cout << YELLOW << "\nstarting at pend[" << RT << j << \
					YELLOW << "] = " << RT << pend[j] << std::endl;
				endpoint = ((n + num_of_pairs_inserted) * pair_size) - 1;
				binary_location = (binary_search_ft(main, 0, endpoint, pend[j], pair_size));
				main.insert(main.begin() + binary_location, \
					(pend.begin() + j - (pair_size - 1)), pend.begin() + j + 1);//+1 cause end iterator
				counter++;
			}
			num_of_pairs_inserted += counter;
			counter = 0;
			convert_pend_to_negative(pend, old_jacob, n, pair_size);
			update_new_jacob(main, pend, old_jacob, old_jacobsthal, n, jacobsthal, pair_size);
		}
	}
};

void	sorting_mainpend_chain(std::vector<int> sorter, 
				std::vector<int> &leftover, size_t power)
{
// ---------------------------elements--------------------------------------
	std::vector<int>	main;
	std::vector<int>	pend;

	size_t	pair_size = power / 2;
// ---------------------------elements--------------------------------------

	adding_mainpend(sorter, main, pend, power);
	insert_firstpair(main, pend, pair_size);
	binaryinsert_mainpend(main, pend, pair_size);
	add_leftover(main, leftover, pair_size);
	std::cout << YELLOW << "\n====-----Printing values-----====" << RT << std::endl;
	print_vector_pairs(main, power, 0);
	print_vector_pairs(pend, power, 2);
	print_vector_pairs(leftover, power, 1);
	std::cout << YELLOW << "====-------------------------====\n" << RT << std::endl;

	//-not updated code, leftover still not staying:
	//   sorting_mainpend_chain call it again?
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
};

/*
std::vector<int> main = { 1, 3, 5, 7, 9, 11, 55, 100 };
std::vector<int> pend = { 0, 2, 4, 6, 8, 10, 29, 42 };

0 1 2 3 4 5 6 7 8 9 10 11 29 42 100
*/




