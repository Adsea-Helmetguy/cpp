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

static int	convert_token(std::string string)
{
	std::stringstream ss(string);
	int	f;

	ss >> f;
	return (f);
};

static int	counting_total_pair(std::vector<int> *sorter, int argc, char **argv, bool *leftover)
{
	int	pair_counter = (argc - 1);

	std::cout << "\n" << std::endl;
	for (int a = 1; a < argc; a++)
	{
		sorter->push_back(convert_token(argv[a]));
		std::cout << GREEN << "Value of sorter" << RT << "[" << CYAN \
			<< a << RT << "]: " << (*sorter)[a - 1] << RT << std::endl;
	}
	if (pair_counter % 2 == 1)
		pair_counter--;
	pair_counter /= 2;
	std::cout << "  Total pair_counter returned: [" << GREEN \
		<< pair_counter << RT << "]" << std::flush;
	if (pair_counter != 0 && (((argc - 1) % pair_counter) == 1 || (argc - 1) == 3))
	{
		std::cout << " | 1 Leftover: \"" << YELLOW << argv[argc - 1]\
			<< RT << "\"." << std::endl;
		(*leftover) = true;
	}
	return (pair_counter);
};

static void	sorting_pairs(std::vector<int> *sorter, int *pair_counter)
{
	int	index_left = 0;
	int	index_right = 0;//compare which is bigger.
	int	pair_counter2 = 1;

	for (size_t i = 0; i < sorter->size(); i++)
	{
		if ((*pair_counter) == 0)
			break ;
		if ((i + 1) % 2 == 0)
			(*pair_counter)--;

		//compare the two values, sort the bigger one on the right!
		if ((i + 1) % 2 == 1)
			index_left = i;
		else if ((i + 1) % 2 == 0)
		{
			index_right = i;
			std::cout << "\n--------\nPair[" << pair_counter2++ \
				<< "]\n--------" << std::endl;
			std::cout << "Before swap: " << (*sorter)[index_left] \
				<< ", " << (*sorter)[index_right] << std::endl;

			//if left is bigger than right, sort!
			if ((*sorter)[index_left] > (*sorter)[index_right])
				std::swap((*sorter)[index_left], (*sorter)[index_right]);
			std::cout << GREEN << "After swap: " << CYAN << (*sorter)[index_left] \
				<< ", " << (*sorter)[index_right] << RT << std::endl;
		}
	}
	(*pair_counter) = (pair_counter2 - 1);
};

bool	start_PmergeMe(int argc, char **argv)
{
	std::vector<int>	sorter;
	int			pair_counter = 0;
	bool			leftover = false;

	//print out before`
	std::cout << "Before: " << GREEN << argv[1] << RT << std::flush;
	for (int i = 2; i < argc; i++)
		std::cout << " " << GREEN << argv[i] << RT << std::flush;

	//getting the total number of pairs
	pair_counter = counting_total_pair(&sorter, argc, argv, &leftover);
	if (pair_counter == 0)
	{
		std::cout << GREEN << "\n\nONLY 1 number! THE END!~" << RT << std::endl;
		return (true);
	}
	//Get the pairs!
	sorting_pairs(&sorter, &pair_counter);
	sorting_level2(&sorter, &pair_counter);//second level onwards sort;

	//if (pair_counter != 0)//ensure no pairs are left!
	//	return (false);
	return (true);
};






















