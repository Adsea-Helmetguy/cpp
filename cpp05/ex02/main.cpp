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

#include "AForm_bureaucrat/AForm.hpp"
#include "shrubberyCreationForm_RobotomyRequestForm/ShrubberyCreationForm.hpp"

int	main()
{
	std::cout << MAG << "\n\nFirst test commence!" << RESET << std::endl;
	{
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
		Bureaucrat a1;
		ShrubberyCreationForm f1;
		std::cout << f1 << std::endl;
		std::cout << YELLOW << "----------------------------" \
			<< RESET << std::endl;
	}
	return (0);
}

