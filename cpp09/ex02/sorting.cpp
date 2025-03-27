/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:34:35 by mlow              #+#    #+#             */
/*   Updated: 2025/03/27 14:40:34 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static int	total_levels(const int pair_counter)
{
	int	total_level = 1;
	int	levels_left = pair_counter;

	while (levels_left % 2 == 0 && (levels_left /= 2))
		total_level++;
	std::cout << "\nTotal levels = " << total_level << std::endl;
	return (total_level);
};

static void	power_sorting(std::vector<int> *sorter, int *pair_counter, int power)
{
	//int	index_left = 0;
	//int	index_right = 0;//compare which is bigger.
	//int	pair_counter2 = 1;

	std::cout << "Current power: " << power << std::endl;
	for (int i = 1; i < (*pair_counter); i++)
	{
		std::cout << "Range: " << power * i << std::endl;
		//sort in terms of power
		std::cout << "Before swap: " << (*sorter)[((power * i) - (power / 2)) - 1] \
				<< ", " << (*sorter)[(power * i) - 1] << std::endl;
	}
	(*pair_counter) /= 2;
};

//get new sets of pairs and divide pair_counter by 2,
//  until (pair counter == 1) at final level;
void	sorting_level2(std::vector<int> *sorter, int *pair_counter)
{
	int	power = 2;
	int	levels_left = total_levels(*pair_counter);

	std::cout << "-----------------------------------------" << std::endl;
	std::cout << GREEN << "Working in progress..." << RT << std::endl;
	for (int l = 2; (levels_left-- && (*pair_counter) != 1); l++)
	{
		power  *= 2;
		std::cout << "Working on Sorting level [" << l << "] (2^" \
			<< l << " = " << power << ")" << std::endl;
		std::cout << "Total_pairs currently->[" << (*pair_counter) << "]\n" << std::endl;
		power_sorting(sorter, pair_counter, power);
	}
	std::cout << "-----------------------------------------\n" << std::endl;
	std::cout << "FINAL Total_pairs->[" << (*pair_counter) << "]\n" << std::endl;
	if ((*pair_counter) == 1)
		std::cout << GREEN << "<<ALL is sorted!>>" << RT << std::endl;
	else
		std::cout << RED << "<<Something is wrong!>>" << RT << std::endl;
};
