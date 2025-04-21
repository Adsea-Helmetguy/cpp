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

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	int	return_value = 0;

	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
	{
		std::cout << MAG << "=============================" \
			"==============================================="<< RT << std::endl;
		if (argc != 2)
		{
			std::cerr << RED << "\tNeeds \"argc = 2\", write like this: " \
				<< "\"./btc <second_database.txt here>\"\n" 
				<< "Error: could not open file." \
				<< RT << std::endl;
			return (1);
		}
		return_value = checking_infile(argv);
		std::cout << MAG << "=============================" \
			"==============================================="<< RT << std::endl;
	}
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
	return (return_value);
};
