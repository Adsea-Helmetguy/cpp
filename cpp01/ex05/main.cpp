/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:34:13 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:34:18 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Use std::ifstream to open and read files.
Use std::ofstream to open and write or append to files.

Always check if the file is successfully opened 
	using .is_open() before attempting to read or write.
*/
#include "Harl.hpp"

int	main(void)
{
	std::cout << YELLOW << "\n\nConstructor happens" << RESET << std::endl;
	Harl harl;

	std::cout << YELLOW << "\n*******************\n|Complains by Harl|\n*******************\n" \
	<< RESET << std::endl;
	std::cout << "------" << GREEN << "DEBUG Level" << RESET << "------" << std::endl;
	harl.complain("DEBUG");
	std::cout << "\n------" << GREEN << "INFO Level" << RESET << "------" << std::endl;
	harl.complain("INFO");
	std::cout << "\n------" << YELLOW << "WARNING Level" << RESET << "------" << std::endl;
	harl.complain("WARNING");
	std::cout << "\n------" << RED << "ERROR Level" << RESET << "------" << std::endl;
	harl.complain("ERROR");
	std::cout << "\n------ No valid Level ------" << std::endl;
	
	std::cout << YELLOW << "\n\nDestructor happens, FINALLY HARL IS GG" \
	<< RESET << std::endl;
}
