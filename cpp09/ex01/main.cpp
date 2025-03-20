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

	std::cout << MAG << "\n\n---------------" << RT << std::endl;
	{
		std::cout << GREEN << "Test (1)!\n" << RT << std::endl;

		//clear && make && clear && ./btc data.csv test1
		if (argc != 2)
		{
			std::cerr << RED << "\tNeeds \"argc = 2\", write like this: " \
				<< "\"./btc <second_database.txt here>\"\n" 
				<< "Error: could not open file." \
				<< RT << std::endl;
			return (1);
		}
		return_value = checking_infile(argv);
	}
	std::cout << MAG << "\n---------------" << RT << std::endl;
	std::cout << "\n\n" << std::endl;
	return (return_value);
};
