/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:58:11 by mlow              #+#    #+#             */
/*   Updated: 2024/10/16 13:58:13 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*
Upon construction, Dog and Cat will create their Brain using "new Brain()";
Upon destruction, Dog and Cat will "delete Brain".
*/
Brain::Brain()
{
	std::cout << RED << "Brain Default constructor called" << RESET << std::endl;
}

/*
Brain::Brain(const std::string& name)
{
	std::cout << RED << "Brain with std::string& name constructor called" \
	<< RESET << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << RED << "Brain copy constructor called" << RESET << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << RED << "Brain equal operator called, but nothing happened" \
	<< RESET << std::endl;
	return (*this);
}
*/

Brain::~Brain()
{
	std::cout << "Brain Deconstructor called" << std::endl;
}


