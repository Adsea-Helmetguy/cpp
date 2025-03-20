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

static	bool	numtoken_checker(int argc, char ** argv)
{
	num
	return (true);
};

//3 − 4 + 5
//3 4 − 5 +
int	main(int argc, char **argv)
{
	//check if the values are numbers or Multiplication Table(+ - / *)
	if (argc < 10)
	{
		if (!(numtoken_checker(argc, argv)))
		{
			std::cerr << RED << "THIS AIN'T a number!!" << RT << std::endl;
			return (1);
		}

		//start coding
		RPN_code(argv);
	}
	else
	{
		std::cerr << YELLOW << "Less than 10 arguments needed!" \
			<< RT << std::endl;
	}
	return (0);
};


