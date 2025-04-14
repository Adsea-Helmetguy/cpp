/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mainpend.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:45:55 by mlow              #+#    #+#             */
/*   Updated: 2025/04/14 16:46:00 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	print_vector_pairs(std::vector<int>& vector, size_t pair_size, int mp)
{
	size_t	loop = 0;

	if (mp == 0)
		std::cout << RED << "MAIN" << RT << std::endl;
	else if (mp == 1)
		std::cout << RED << "Leftovers" << RT << std::endl;
	else if (mp == 2)
		std::cout << RED << "PEND" << RT << std::endl;

	std::cout << YELLOW << "(" << RT << std::flush;
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
	{
		if (loop != 0 && loop % pair_size == 0)
			std::cout << YELLOW << ") (" << RT << std::flush;
		std::cout << *it << std::flush;
		if ((loop + 1) % pair_size != 0 && (loop < vector.size() - 1))
			std::cout << ", " << std::flush;
		loop++;
	}
	std::cout << YELLOW << ")" << RT << std::endl;
}

void	comparing_startVend(std::vector<int>& main, size_t start, size_t end, size_t pair_size)
{
	std::cout << YELLOW << "  Comparing (start[" << RT << std::flush;
	
	for (size_t i = 0; i != (start + pair_size); i++)
	{
		std::cout << i << std::flush;
		if ((i + 1) != (start + pair_size))
			std::cout << ", " << std::flush;
	}
	std::cout << YELLOW << "] = (" << RT << std::flush;
	for (size_t i = 0; i < (start + pair_size); i++)
	{
		std::cout << main[i] << std::flush;
		if ((i + 1) != (start + pair_size))
			std::cout << ", " << std::flush;
	}
	std::cout << YELLOW << ")" << RT << std::flush;

	std::cout << YELLOW << " || " << "end[" << RT << std::flush;
	for (size_t i = end - 1; i < end + 1; i++)
	{
		std::cout << i << std::flush;
		if ((i + 1) != end + 1)
			std::cout << ", " << std::flush;
	}
	std::cout << YELLOW << "] = (" << RT << std::flush;
	for (size_t i = end - 1; i < end + 1; i++)
	{
		std::cout << main[i] << std::flush;
		if ((i + 1) != end + 1)
			std::cout << ", " << std::flush;
	}
	std::cout << YELLOW << ")" << RT << std::endl;
};

/* return the position of where to insert the insert_element */
size_t	binary_search_ft(std::vector<int>& main, size_t start, size_t end, int insert_element, size_t pair_size)
{
	if (start >= end || (start + (pair_size - 1) >= end))
		return (start);

	size_t	binary_location = 0;	
	size_t	total_pairs_inrange = ((end - start + 1) / pair_size);
	size_t	midpoint = start + ((total_pairs_inrange / 2) * pair_size) - 1;

	comparing_startVend(main, start, end, pair_size);

	std::cout << CYAN << "    Total pair_size in this range: " << RT << total_pairs_inrange << std::endl;
	std::cout << YELLOW << "    midpoint[" << midpoint << "] = " << RT << main[midpoint] << std::endl;
	if (insert_element < main[midpoint])
		return binary_search_ft(main, start, midpoint, insert_element, pair_size);
	else
		return binary_search_ft(main, midpoint + 1, end, insert_element, pair_size);
	return (binary_location);
};

size_t	jacob_number(size_t n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacob_number(n - 1) + 2 * jacob_number(n - 2));
};

int	pend_checkall_negative(std::vector<int> pend)
{
	for (size_t i = 0; i < pend.size(); i++)
	{
		if (pend[i] != -1)
			return (0);//false
	}
	return (1);//true
};

void	convert_pend_to_negative(std::vector<int> &pend, size_t old_jacob, size_t n, size_t pair_size)
{
	for (size_t loop = n; loop > old_jacob; loop--)
	{
		for (size_t pair = 0; pair < pair_size; pair++)
		{
			pend[(loop * pair_size) - 1 - pair] = -1;
		}
	}
}

void	print_mainpend(std::vector<int> &main, \
		std::vector<int> &pend, size_t pair_size, size_t before_after)
{
	if (before_after == 0)
	{
		std::cout << "------<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" \
			<< std::endl;
		std::cout << GREEN << "---->BEFORE: " << RT << std::endl;
	}
	else if (before_after == 1)
	{
		std::cout << GREEN << "\n---->AFTER: " << RT << std::endl;
	}
	print_vector_pairs(main, pair_size * 2, 0);
	print_vector_pairs(pend, pair_size * 2, 2);
};

void	insert_firstpair(std::vector<int> &main, std::vector<int> &pend, size_t &pair_size)
{
	if (!pend.empty())
	{
		if (!main.empty() && !pend.empty())
			print_mainpend(main, pend, pair_size, 0);
		main.insert(main.begin(), pend.begin(), pend.begin() + pair_size);
		convert_pend_to_negative(pend, 0, 1, pair_size);
	}
	std::cout << GREEN << "Inserting first pairs into main!" << RT << std::endl;
	print_vector_pairs(main, pair_size, 0);
	print_vector_pairs(pend, pair_size, 2);
};

void	update_new_jacob(std::vector<int> &main, std::vector<int> &pend, \
		size_t &old_jacob, size_t &old_jacobsthal, size_t &n, size_t &jacobsthal, size_t &pair_size)
{
	old_jacob = n;
	old_jacobsthal = jacobsthal;
	jacobsthal = jacob_number(++n);
	print_mainpend(main, pend, pair_size, 1);
	std::cout << YELLOW << "-------------------------------------------" << std::endl;
	std::cout << "n = " << n << " | Jacobsthal = " << RT << jacobsthal << std::endl;
	std::cout << YELLOW <<  "-------------------------------------------" << RT << std::endl;
};
