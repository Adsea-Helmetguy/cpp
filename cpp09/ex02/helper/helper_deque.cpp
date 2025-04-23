/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_deque.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:34:15 by mlow              #+#    #+#             */
/*   Updated: 2025/04/22 15:34:41 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	insert_firstpair_deque(std::deque<long long> &main, std::deque<long long> &pend, size_t &pair_size)
{
	if (!pend.empty())
	{
		if (pair_size >= pend.size())
			main.insert(main.begin(), pend.begin(), pend.end());
		else
			main.insert(main.begin(), pend.begin(), pend.begin() + pair_size);
	}
};

void	timer_for_recursion_deque(std::deque<long long> &sorter, int argc)
{
	double		timer_start = 0;
	double		timer_end = 0;
	clock_t		time = clock();
	int		level = 1;

	timer_start = timer_in_ms(time);
	start_recursive_sort_deque(sorter, level);
	timer_end = timer_in_ms(time);
	timer_end -= timer_start;
	print_deque_AFTER(sorter, timer_end, argc);
};

void	pushing_sort_deque(std::deque<long long> &sorter, int argc, char **argv)
{
	for (int a = 1; a < argc; a++)
		sorter.push_back(convert_token(argv[a]));
};

void	print_deque_AFTER(std::deque<long long> &deque, double timer_end, int argc)
{
	std::cout << "After: " << std::flush;
	for (std::deque<long long>::iterator it = deque.begin(); it != deque.end(); it++)
	{
		std::cout << " " << CYAN << *it << RT<< std::flush;
	}
	std::cout << std::endl;
	std::cout << YELLOW << "Time to process a range of   " << RT << (argc - 1) \
		<< YELLOW << " elements with std::deque : " << RT << timer_end << "ms" << std::endl;
};

void	sortinside_pairs_deque(std::deque<long long> &sorter, size_t power, int pair_counter)
{
	size_t	sp = power - 1;//sp means startpoint

	for (size_t i = pair_counter; i > 0; i--)
	{
		num_comparison++;
		if (sorter[(sp)] < sorter[sp - (power / 2)])
		{
			std::swap(sorter[(sp - (power / 2))], sorter[(sp)]);
			for (int order = ((power / 2) - 1); order != 0; order--)
				std::swap(sorter[(sp - (power / 2)) - order], sorter[(sp - order)]);
		}
		sp += power;
	}
};
