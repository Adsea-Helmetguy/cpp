/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_leftover.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:45:28 by mlow              #+#    #+#             */
/*   Updated: 2025/04/14 16:45:44 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	leftover_jacob(size_t &old_jacob, size_t &n, size_t &jacobsthal)
{
	old_jacob = n;
	old_jacobsthal = jacobsthal;
	jacobsthal = jacob_number(++n);
	print_mainpend(main, pend, pair_size, 1);
};

