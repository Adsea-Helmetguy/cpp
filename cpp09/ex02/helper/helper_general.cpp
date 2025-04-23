/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_general.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:33:47 by mlow              #+#    #+#             */
/*   Updated: 2025/04/22 15:34:00 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

size_t	jacob_number(size_t n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacob_number(n - 1) + 2 * jacob_number(n - 2));
};

long long	convert_token(std::string string)
{
	std::stringstream ss(string);
	long long	f;

	ss >> f;
	return (f);
};

double	timer_in_ms(clock_t &time)
{
	time = clock() - time;
	double ms = double(time) / CLOCKS_PER_SEC;
	return (ms);
};

void	update_new_jacob(size_t &old_jacob, size_t &old_jacobsthal, size_t &n, size_t &jacobsthal)
{
	old_jacob = n;
	old_jacobsthal = jacobsthal;
	jacobsthal = jacob_number(++n);
	//std::cout << YELLOW << "-------------------------------------------" << std::endl;
	//std::cout << "n = " << n << " | Jacobsthal = " << RT << jacobsthal << std::endl;
	//std::cout << YELLOW <<  "-------------------------------------------" << RT << std::endl;
};

