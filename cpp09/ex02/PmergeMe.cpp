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

int	convert_token(std::string string)
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
			std::cout << YELLOW << "Value of leftover[" << CYAN << i \
				<< YELLOW << "] = "<< RT << leftover[i] << std::endl;
	}
	return (pair_counter);
};

void	pushing_sort(std::vector<int> &sorter, int argc, char **argv)
{
	std::cout << "\n" << std::endl;
	for (int a = 1; a < argc; a++)
	{
		sorter.push_back(convert_token(argv[a]));
		std::cout << GREEN << "Value of sorter" << RT << "[" << CYAN \
			<< (a - 1) << RT << "]: " << sorter[a - 1] << RT << std::endl;
	}
};

//sort the pairs from left small to right big
void	sortinside_pairs(std::vector<int> &sorter, int power, int pair_counter)
{
	int	startpoint = power - 1;

	for (size_t i = pair_counter; i > 0; i--)
	{
		//sorting two values if right is not bigger than left
		std::cout << "Comparing std::vector between [" << (startpoint - (power / 2)) \
			<< "] vs [" << startpoint << "]" << std::endl;
		std::cout << YELLOW << "    BEFORE:  " << RT << sorter[(startpoint - (power / 2))] \
			<< " VS " << sorter[(startpoint)] << std::endl;
		if (sorter[(startpoint)] < sorter[startpoint - (power / 2)])
			std::swap(sorter[(startpoint - (power / 2))], sorter[(startpoint)]);
		std::cout << GREEN << "    AFTER:  " << RT << sorter[(startpoint - (power / 2))] \
			<< " VS " << sorter[(startpoint)] << std::endl;
		startpoint += power;
	}
};

void	start_recursive_sort(std::vector<int> &sorter, int level)
{
	std::vector<int>	leftover;
	int	pair_counter = 0;
	int	power = static_cast<int>(pow(2, level));

	std::cout << "\n-------------------------->>>>>>" << std::endl;
	std::cout << "Power is : \"" << power << "\"" << std::endl;
	pair_counter = counting_total_pair(sorter, leftover, power);
	std::cout << "Total_pairs for level[" << CYAN << level << RT \
		<< "] = " << pair_counter << "\n" << std::endl; 
	if (pair_counter == 0)
	{
		std::cout << GREEN << "\n\nONLY 1 number! THE END!~" << RT << std::endl;
		return ;
	}
	sortinside_pairs(sorter, power, pair_counter);
	start_recursive_sort(sorter, (level + 1));
}

bool	start_PmergeMe(int argc, char **argv)
{
	std::vector<int>	sorter;
	int			level = 1;

	//print out before
	std::cout << "Before: " << GREEN << argv[1] << RT << std::flush;
	for (int i = 2; i < argc; i++)
		std::cout << " " << GREEN << argv[i] << RT << std::flush;

	// insert numbers from argv into the std::vector
	pushing_sort(sorter, argc, argv);
	if (sorter.size() <= 1)
		return (true);

	//recursive sorting till all pairs are sorted
	start_recursive_sort(sorter, level);
	std::cout << "-----------------------------------------------------\n" << std::endl;

	//if (pair_counter != 0)
	//	return (false);
	return (true);
};






















