/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:09:10 by mlow              #+#    #+#             */
/*   Updated: 2025/03/25 15:10:47 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static int	sizeof_index(char *argv)
{
	int	size = 0;

	while (argv[size])
		size++;
	return (size);
};

static bool	int_checker(int argc, char **argv)
{
	for (int a = 1; a < argc; a++)
	{
		for (int i = 0; i < sizeof_index(argv[a]); i++)
		{
			if (argv[a][i] < '0' || argv[a][i] > '9')
			{
				std::cerr << RED << "This is invalid." << RT << std::endl;
				return (false);
			}
		}
	}
	return (true);
};

int	main(int argc, char **argv)
{
	std::cout << "-------------------------" << std::endl;
	std::cout << "starting project for ex02" << std::endl;
	std::cout << "-------------------------" << std::endl;

	//check it is all positive int
	if (!int_checker(argc, argv))
		return (1);
	//begin project
	return (0);
};
