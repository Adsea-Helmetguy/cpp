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

int	sizeof_array(char *argv)
{
	int	size = 0;

	while (argv[size])
		size++;
	return (size);
};

static bool	array_size(int argc, char **argv)
{
	int	size = 0;
	
	//remove_isspace(argc, &argv);
	std::cout << GREEN << "Starting argv checks!" << RT << std::endl;
	for (int a = 1; a < argc; a++)
	{
		size = sizeof_array(argv[a]);
		std::cout << "Array[" << a << "] = " << "\"" << argv[a] << "\"" << std::endl;
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

int	main(int argc, char **argv)
{
	std::cout << "\n\n" << std::endl;
	std::cout << "--------argc = " << argc << \
		"------------------------------" << std::endl;

	//single argument but a string of char
	//https://cplusplus.com/reference/string/string/string/#google_vignette
	if (argc == 2)
	{
		std::string	input(argv[1]);
		RPN_argv2code(input);
		return (0);
	}
	else if (argc > 1)
	{
		if (!(array_size(argc, argv)))
			return (1);
		RPN_code(argc, argv);//if got isspace, fail cause argument
	}
	else
	{
		std::cerr << YELLOW << "Arguments needed!" \
			<< RT << std::endl;
	}

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "\n\n\n" << std::endl;
	return (0);
};

/*
// try)
//	./RPN 3 5 + 7 2 - "*"
//	./RPN 3 5 + 7 2 - "*" 6 +
//	./RPN 3 5 + 7 2 - "*" 6 + 6
//answer: 40
//p.s, don't write raw *, it will call bash to do weird things
*/

//Links:
/*
--introduction to RPN--
https://medium.com/@ainayat865/reverse-polish-notation-rpn-with-stack-4551a5f54ae0#:~:text=It%20made%20use%20of%20the,such%20as%20brackets%20and%20parentheses.

*/
