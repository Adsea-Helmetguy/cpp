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

//level is used here to check what is going on!
int	counting_total_pair(std::vector<int> &sorter, std::vector<int> &leftover, int power, int level)
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
		for (size_t i = 0; i < leftover.size(); i++)
		{
			std::cout << YELLOW << "Value of leftover[" << CYAN << i \
				<< YELLOW << "] = " << RT << leftover[i] << \
				" | Inside level[" << level << "]" << std::endl;
		}
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
void	sortinside_pairs(std::vector<int> &sorter, size_t power, int pair_counter, int level)
{
	size_t	sp = power - 1;//sp means startpoint

	for (size_t i = pair_counter; i > 0; i--)
	{
		//sorting two values if right is not bigger than left
		std::cout << "Comparing std::vector between [" << (sp - (power / 2)) \
			<< "] vs [" << sp << "]" << std::endl;
		std::cout << YELLOW << "    BEFORE:  " << RT << sorter[(sp - (power / 2))] \
			<< " VS " << sorter[(sp)] << std::endl;

		//===working===
		if (sorter[(sp)] < sorter[sp - (power / 2)])
		{
			std::swap(sorter[(sp - (power / 2))], sorter[(sp)]);
			for (int order = ((power / 2) - 1); order != 0; order--)
				std::swap(sorter[(sp - (power / 2)) - order], sorter[(sp - order)]);
		}
		//===working===
		(void)level;
		std::cout << GREEN << "    AFTER:  " << RT << sorter[(sp - (power / 2))] \
			<< " VS " << sorter[(sp)] << std::endl;
		sp += power;
	}
	print_mainchain(sorter);
};

void	start_recursive_sort(std::vector<int> &sorter, int level)
{
	std::vector<int>	leftover;
	int	pair_counter = 0;
	size_t	power = static_cast<size_t>(pow(2, level));

	std::cout << "\n-------------------------->>>>>>" << std::endl;
	std::cout << "Power is : \"" << power << "\"" << std::endl;
	pair_counter = counting_total_pair(sorter, leftover, power, level);
	std::cout << "Total_pairs for level[" << CYAN << level << RT \
		<< "] = " << pair_counter << "\n" << std::endl; 
	if (pair_counter == 0)
		return ;
	sortinside_pairs(sorter, power, pair_counter, level);
	start_recursive_sort(sorter, (level + 1));

	//time to rewind backwards the level--
	sorting_mainpend_chain(sorter, leftover, power);
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
	//print_mainchain(sorter);
	//sorting_mainpend_chain(sorter, leftover);
	std::cout << "-----------------------------------------------------\n" << std::endl;

	//if (pair_counter != 0)
	//	return (false);
	return (true);
};






















