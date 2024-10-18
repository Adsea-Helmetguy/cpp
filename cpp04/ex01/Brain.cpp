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

//COPY CONSTRUCTOR
Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << RED << "Brain copy constructor called" << RESET << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	const int	total_size = 100;
	int		index = 0;
	
	//while loop to do deep copy
	while (index < total_size)
	{
		this->ideas[index] = other.ideas[index];
		index++;
	}
	std::cout << RED << "Brain equal operator called, but nothing happened" \
	<< RESET << std::endl;
	return (*this);
}


Brain::~Brain()
{
	std::cout << "Brain Deconstructor called" << std::endl;
}

void	Brain::idea_member(int idea_number, std::string input_ideas)
{
	this->ideas[idea_number] = input_ideas;
}

void	Brain::obtain_idea(int idea_number)
{
	std::cout << BLUE << this->ideas[idea_number] << RESET << std::endl;
}
