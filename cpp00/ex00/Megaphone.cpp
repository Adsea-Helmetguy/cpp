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

int	main(int argc, char **argv)
{
	int	array;
	int	index;

	if (argc != 1)
	{
		array = 0;
		while (argv[++array])
		{
			index = 0;
			while (argv[array][index])
				std::cout << static_cast<char>(toupper(argv[array][index++]));
		}
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
