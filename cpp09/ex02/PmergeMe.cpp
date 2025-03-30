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

int	counting_total_pair(std::vector<int> &sorter, std::vector<int> &leftover, int power)
{
	int	pair_counter = sorter.size();
	int	current_leftovers = 0;
	int	indexof_leftover = 0;

	pair_counter /= power;
	current_leftovers = sorter.size() % power;
	indexof_leftover = sorter.size() - current_leftovers;
	if (current_leftovers > 0)
	{
		for (size_t i = indexof_leftover; i < sorter.size(); i++)
			leftover.push_back(sorter[i]);
		//checking the values of leftover
		for (size_t i = 0; i < leftover.size(); i++)
			std::cout << "Value of leftover[" << CYAN << i << RT \
				<< "] = " << leftover[i] << std::endl;
	}
	return (pair_counter);
};

static void	pushing_number(std::vector<int> &sorter, int argc, char **argv)
{
	std::cout << "\n" << std::endl;
	for (int a = 1; a < argc; a++)
	{
		sorter.push_back(convert_token(argv[a]));
		std::cout << GREEN << "Value of sorter" << RT << "[" << CYAN \
			<< a << RT << "]: " << sorter[a - 1] << RT << std::endl;
	}
};

void	sortinside_pairs()
{

};

void	start_recursive_sort(std::vector<int> &sorter, int level)
{
	int	pair_counter = 0;
	std::vector<int>	leftover;

	int	power = pow(2, level);
	std::cout << "Power is : \"" << power << "\"" << std::endl;
	pair_counter = counting_total_pair(sorter, leftover, power);
	std::cout << "Total_pairs for level[" << CYAN << level << RT \
		<< "] = " << pair_counter << std::endl; 
	if (pair_counter == 0)
	{
		std::cout << GREEN << "\n\nONLY 1 number! THE END!~" << RT << std::endl;
		return ;
	}
	//got pairs to sort
	//sortinside_pairs(sorter, power, pair_counter);
}

bool	start_PmergeMe(int argc, char **argv)
{
	std::vector<int>	sorter;
	int					level = 1;
	// int			pair_counter = 0;
	// bool			leftover = false;

	//print out before`
	std::cout << "Before: " << GREEN << argv[1] << RT << std::flush;
	for (int i = 2; i < argc; i++)
		std::cout << " " << GREEN << argv[i] << RT << std::flush;

	// insert numbers from argv into the std::vector
	pushing_number(sorter, argc, argv);

	// check total number of elements
	if (sorter.size() <= 1)
		return (true);

	start_recursive_sort(sorter, level);

	// pair_counter = counting_total_pair(&sorter, argc, argv, &leftover);
	// if (pair_counter == 0)
	// {
	// 	std::cout << GREEN << "\n\nONLY 1 number! THE END!~" << RT << std::endl;
	// 	return (true);
	// }

	//Get the pairs!
	// sorting_pairs(&sorter, &pair_counter);
	// sorting_level2(&sorter, &pair_counter);//second level onwards sort;

	//if (pair_counter != 0)//ensure no pairs are left!
	//	return (false);
	return (true);
};






















