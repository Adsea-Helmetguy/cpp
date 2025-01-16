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

#include "Form.hpp"

int	main()
{
	{
		std::cout << BLUE << "First test commence!" << std::endl;
		std::cout << "----------------------------" << std::endl;
		try
		{
			throw Bureaucrat::GradeTooHighException("testing for high value");
		}
		catch(const Form::GradeTooHighException& e)
		{
			std::cerr << "Custom Exception obtained: " << YELLOW \
				<< e.what() << RESET << std::endl;
		}
		std::cout << "----------------------------" << std::endl;
	}
	return (0);
}

