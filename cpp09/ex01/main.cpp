/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:41:30 by mlow              #+#    #+#             */
/*   Updated: 2025/03/11 09:41:31 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static	bool	numtoken_checker(int argc, char *argv)
{
	for (int i = 0; i < argc; i++)
	{
		if (!(argv[i]))
			break ;
		if ((argv[i] >= '0' && argv[i] <= '9') || argv[i] == '+' \
			|| argv[i] == '-' || argv[i] == '/' || argv[i] == '*')
		{
			std::cout << "\tindex[" << GREEN << i << RT << "]: " \
				<< argv[i] << std::endl;
			continue ;
		}
		std::cout << "\tindex[" << GREEN << i << RT << "]: (" << GREEN << argv[i] \
			<< RT << ") " << RED << "--THIS IS NOT A VALID VALUE)!!--" << std::endl;
		return (false);
	}
	std::cout << std::endl;
	return (true);
};

static int	sizeof_array(char *argv)
{
	int	size = 0;

	while (argv[size])
	{
		size++;
	}
	return (size);
};

static bool	array_size(int argc, char **argv)
{
	int	size = 0;

	std::cout << GREEN << "Starting argv checks!" << RT << std::endl;
	for (int a = 1; a < argc; a++)
	{
		size = sizeof_array(argv[a]);
		std::cout << "Array[" << a << "] = " << argv[a] << std::endl;
		if (size != 1 || !(numtoken_checker(argc, argv[a])))
		{
			std::cout << RED << "\n\nOnly " << YELLOW << "SINGLE " \
			<< "\"NUMBER\" " << RED << "and " << YELLOW << "\"+ - / *\" " \
			<< RED << "are allowed!!" << RT << std::endl;
			return (false);
		}
	}
	return (true);
};


//3 − 4 + 5
//3 4 − 5 +
int	main(int argc, char **argv)
{
	//check if the values are numbers or Multiplication Table(+ - / *)
	std::cout << "\n\n" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	//check if the values are numbers or Multiplication Table(+ - / *)
	if (argc > 1 && argc < 10)
	{
		if (!(array_size(argc, argv)))
			return (1);

		std::cout << GREEN << "\tStarting RPN_CODE now." << RT << std::endl;
		RPN_code(argc, argv);
	}
	else if (argc == 0)
	{
		std::cerr << YELLOW << "Where your argument!?" << RT << std::endl;
	}
	else
	{
		std::cerr << YELLOW << "Less than 10 arguments needed!" \
			<< RT << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "\n\n\n" << std::endl;
	return (0);
};

//Links:
/*
--introduction to RPN--
https://medium.com/@ainayat865/reverse-polish-notation-rpn-with-stack-4551a5f54ae0#:~:text=It%20made%20use%20of%20the,such%20as%20brackets%20and%20parentheses.

*/
