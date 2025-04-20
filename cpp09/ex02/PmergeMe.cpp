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

void	pushing_sort(std::vector<int> &sorter, int argc, char **argv)
{
	for (int a = 1; a < argc; a++)
		sorter.push_back(convert_token(argv[a]));
};

void	sortinside_pairs(std::vector<int> &sorter, size_t power, int pair_counter, int level)
{
	size_t	sp = power - 1;//sp means startpoint

	for (size_t i = pair_counter; i > 0; i--)
	{
		if (sorter[(sp)] < sorter[sp - (power / 2)])
		{
			std::swap(sorter[(sp - (power / 2))], sorter[(sp)]);
			for (int order = ((power / 2) - 1); order != 0; order--)
				std::swap(sorter[(sp - (power / 2)) - order], sorter[(sp - order)]);
		}
		(void)level;
		sp += power;
	}
};

int	counting_total_pair(std::vector<int> &sorter, std::vector<int> &leftover, int power)
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


void	start_recursive_sort(std::vector<int> &sorter, int level)
{
	std::vector<int>	leftover;
	size_t	power = static_cast<size_t>(pow(2, level));

	int	pair_counter = 0;
	pair_counter = counting_total_pair(sorter, leftover, power);
	//std::cout << CYAN << "LEVEL = " << level << RT << std::endl;
	if (pair_counter == 0)
		return ;
	sortinside_pairs(sorter, power, pair_counter, level);
	start_recursive_sort(sorter, (level + 1));
	sorter = sorting_mainpend_chain(sorter, leftover, power);
}

double	timer_in_ms(clock_t &time)
{
	time = clock() - time;
	double ms = double(time) / CLOCKS_PER_SEC;
	return (ms);
};

bool	PmergeMe_vector(int argc, char **argv)
{
	std::vector<int>	sorter;
	int			level = 1;
	double		timer_start = 0;
	double		timer_end = 0;

	std::cout << "Before: " << GREEN << argv[1] << RT << std::flush;
	for (int i = 2; i < argc; i++)
		std::cout << " " << GREEN << argv[i] << RT << std::flush;
	std::cout << std::endl;
	pushing_sort(sorter, argc, argv);
	if (sorter.size() <= 1)
		return (true);

	//timer start
	clock_t		time = clock();
	timer_start = timer_in_ms(time);
	start_recursive_sort(sorter, level);
	timer_end = timer_in_ms(time);
	timer_end -= timer_start;
	//timer end
	print_AFTER(sorter);
	std::cout << YELLOW << "Time to process a range of   " << RT << (argc - 1) \
		<< YELLOW << " elements with std::vector : " << RT << timer_end << "ms" << std::endl;
	return (true);
};






















