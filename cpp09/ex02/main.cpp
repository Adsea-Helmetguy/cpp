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

//https://www.linkedin.com/pulse/recursion-how-does-work-santiago-borgia/
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
	std::cout << "\n\n" << std::endl;
	std::cout << "-------------------------" << std::endl;
	std::cout << "starting project for ex02" << std::endl;
	std::cout << "-------------------------" << std::endl;

	//check it is all positive int
	//if (!(int_checker(argc, argv)))
	//	return (1);
	//correct arguments && check it is all positive int

	if (argc < 2 || !(int_checker(argc, argv)))
	{
		std::cout << RED << "Invalid!! Check arguments pls!" << RT << std::endl;
		return (1);
	}

	//begin project
	if (!(start_PmergeMe(argc, argv)))
	{
		std::cout << RED << "something is wrong!! FALSE!" << RT << std::endl;
		return (1);
	}
	std::cout << "\n\n\n" << std::endl;
	return (0);
};
