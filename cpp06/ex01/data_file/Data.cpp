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

Data::Data() : _name("Default Data"), _UInt(0)
{

};

Data::Data(const std::string& name) : _name(name), _UInt(0)
{

};

Data::Data(const Data& copy)
{
	this->_name = copy.getName();
	this->_UInt = copy.getUInt();
	std::cout << "DATA COPY CONSTRUCTOR " << this->_name \
		<< " Called!!" << std::endl;
};

Data& Data::operator=(const Data& copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_UInt = copy._UInt;
	}
	else
		std::cout << "Don't Self copy!!" << std::endl;
	return (*this);
};

Data::~Data()
{

};




//---------------Return private values---------------
std::string	Data::getName() const
{
	return (this->_name);
};

uintptr_t	Data::getUInt() const
{
	return (this->_UInt);
};

void		Data::updateUInt(const uintptr_t raw)
{
	this->_UInt = raw;
};
//---------------Return private values---------------




std::ostream& operator<<(std::ostream& os, const Data& other)
{
	std::cout << YELLOW << other.getName() << RESET \
		<< "." << std::endl;
	return (os);
};
