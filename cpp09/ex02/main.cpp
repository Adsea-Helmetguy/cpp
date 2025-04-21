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

/*
need to pass:
test1)
0 14 1 9 3 11 12 8 6 16 5 15 17 13 19 10 18 2 20 4 7

2)
7 12 18 10 8 16 13 14 11 5 9 4 20 2 1 19 17 3 6 15 0
*/

//https://www.linkedin.com/pulse/recursion-how-does-work-santiago-borgia/
#include "PmergeMe.hpp"

int	num_comparison = 0;

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
//	std::cout << "\n\n" << std::endl;
//	std::cout << "-------------------------" << std::endl;
//	std::cout << "starting project for ex02" << std::endl;
//	std::cout << "-------------------------" << std::endl;

	num_comparison = 0;
	if (argc < 2 || !(int_checker(argc, argv)))
	{
		std::cout << RED << "Invalid!! Check arguments pls!" << RT << std::endl;
		return (1);
	}
	if (!(PmergeMe_vector(argc, argv)))
	{
		std::cout << RED << "something is wrong!! FALSE!" << RT << std::endl;
		return (1);
	}
	/*if (!(PmergeMe_deque_alt(argc, argv)))
	{
		std::cout << RED << "something is wrong!! FALSE!" << RT << std::endl;
		return (1);
	}*/
	std::cout << "Number of comparisons: " << num_comparison << std::endl;
	std::cout << "\n\n\n" << std::endl;
	return (0);
};
