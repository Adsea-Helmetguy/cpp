/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:18:25 by mlow              #+#    #+#             */
/*   Updated: 2025/02/04 15:18:30 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{

};

Serializer::Serializer(const Serializer& copy)
{
	(void)copy;
};

Serializer& Serializer::operator=(const Serializer& copy)
{
	(void)copy;
	return (*this);
};

Serializer::~Serializer()
{

};

//https://stackoverflow.com/questions/1845482/what-is-the-uintptr-t-data-type
uintptr_t	Serializer::serialize(Data* ptr)
{
	ptr->updateUInt(reinterpret_cast<uintptr_t>(ptr));
	return (reinterpret_cast<uintptr_t>(ptr));
};

Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
};
