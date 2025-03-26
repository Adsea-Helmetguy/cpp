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
	//std::cout << GREEN << "Inside ss: " << RT << f << std::endl;
	return (f);
};

static int	counting_total_pair(std::vector<int> *sorter, int argc, char **argv)
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
	std::cout << "\nTotal pair_counter returned: [" << GREEN \
		<< pair_counter << RT << "]" << std::flush;
	return (pair_counter);
};

static void	sorting_pairs(std::vector<int> *sorter, int *pair_counter)
{
	int	compare1 = 0;
	int	compare2 = 0;//compare which is bigger.
	

	for (size_t i = 1; i < sorter->size(); i++)
	{
		if (i % 2 == 0)
			(*pair_counter)--;
		if ((*pair_counter) == 0)
			return ;
		//compare the two values, sort the bigger one on the right!
		sorter[i -1]
	}
};

bool	start_PmergeMe(int argc, char **argv)
{
	std::vector<int>	sorter;
	int			pair_counter = 0;
	bool			leftovers = false;

	//print out before
	std::cout << "Before: " << GREEN << argv[1] << RT << std::flush;
	for (int i = 2; i < argc; i++)
		std::cout << " " << GREEN << argv[i] << RT << std::flush;

	//getting the total number of pairs
	pair_counter = counting_total_pair(&sorter, argc, argv);
	if ((argc - 1) % pair_counter == 1)
	{
		std::cout << " | 1 Leftover: \"" << YELLOW << argv[argc - 1]\
			<< RT << "\"." << std::endl;
		leftovers = true;
	}

	//Get the first pairs!
	sorting_pairs(&sorter, &pair_counter);

	if (pair_counter != 0)
		return (false);
	return (true);
};






















