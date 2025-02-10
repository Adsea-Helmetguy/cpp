/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar_printvalue.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:18:25 by mlow              #+#    #+#             */
/*   Updated: 2025/02/04 15:18:30 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::Base()
{

};

Base::Base(const Base& copy)
{
	(void)copy;
};

Base& Base::operator=(const Base& copy)
{
	(void)copy;
	return (*this);
};

Base::~Base()
{

};

//https://stackoverflow.com/questions/1845482/what-is-the-uintptr-t-data-type
uintptr_t	Base::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
};

Data*		Base::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
};