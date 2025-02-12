/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:18:25 by mlow              #+#    #+#             */
/*   Updated: 2025/02/04 15:18:30 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _name("Default Data")
{

};

Data::Data(const std::string& name) : _name(name)
{

};

Data::Data(const Data& copy)
{
	(void)copy;
};

Data& Data::operator=(const Data& copy)
{
	if (this != &copy)
	{
		_name = copy._name;
	}
	else
		std::cout << "Don't Self copy!!" << std::endl;
	return (*this);
};

Data::~Data()
{

};

std::string	Data::getName() const
{
	return (this->_name);
};

std::ostream& operator<<(std::ostream& os, const Data& other)
{
	std::cout << YELLOW << other.getName() << RESET \
		<< "." << std::endl;
	return (os);
};
