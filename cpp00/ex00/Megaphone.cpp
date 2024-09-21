/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:21:35 by mlow              #+#    #+#             */
/*   Updated: 2024/05/24 19:22:00 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype> // for std::toupper


//1)using namespace <ns_name> and
//friend keywords are forbidden. Otherwise, your grade will be -42.
//
//2)You are allowed to use the STL in the Module 08 and 09 only. That means:
//no Containers (vector/list/map/and so forth) and no Algorithms (anything that
//requires to include the <algorithm> header) until then.
//
//The following functions are forbidden
//too: *printf(), *alloc() and free().
//
//
char	**uppercase(char **argv)
{
	int	array;
	int	index;

	array = 0;
	while (argv[array])
	{
		index = -1;
		while (argv[array][++index])
			argv[array][index] = toupper(argv[array][index]);
		argv[array][index] = '\0';
		array++;
	}
	argv[array] = NULL;
	return (argv);
}

int	main(int argc, char **argv)
{
//	std::string text = "shhhhh... I think the students are asleep...";
	char	**print_out;
	int	array;

	if (argc != 1)
	{
		// Convert to uppercase
		print_out = uppercase(argv);
		// Output the converted string
		array = 0;
		while (argv[++array])
			std::cout << print_out[array];
		std::cout << std::endl;
	}
	else
		std::cout << " * LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
//
/*
$>./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
*/
