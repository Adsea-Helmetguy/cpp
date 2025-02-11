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

//------------------------------------------------------
//------------------------------------------------------
//https://cplusplus.com/reference/cstdlib/srand/
Base	*generate(void)
{
	int	index;
	char	letters[3] = {'A', 'B', 'C'};

	//srand(time(0));//This can be found in main.cpp.
	index = std::rand() % 3;
	if (index == 0)
	{
		std::cout << "Random_letter = " << YELLOW << letters[index] \
			<< RT << std::endl;
		return (new A());
	}
	else if (index == 1)
	{
		std::cout << "Random_letter = " << YELLOW << letters[index] \
			<< RT << std::endl;
		return (new B());
	}
	std::cout << "Random_letter = " << YELLOW << letters[index] << RT << std::endl;
	return (new C());
};

//https://www.geeksforgeeks.org/casting-operators-in-cpp/
void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "downcast for \"A\" successful!!\n" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "downcast for \"B\" successful!!\n" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "downcast for \"C\" successful!!\n" << std::endl;
	else
		std::cout << "Failed to Downcast." << std::endl;
/*
	//add in function: "dynamic_cast"
	Base	*replaceA = dynamic_cast<A*>(p);
	Base	*replaceB = dynamic_cast<B*>(p);
	Base	*replaceC = dynamic_cast<C*>(p);

	if (replaceA == p)
	{
		std::cout << "downcast for \"A\" successful!!\n" << std::endl;
	}
	else if (replaceB == p)
	{
		std::cout << "downcast for \"B\" successful!!\n" << std::endl;
	}
	else if (replaceC == p)
	{
		std::cout << "downcast for \"C\" successful!!\n" << std::endl;
	}
	else
	{
		std::cout << "Failed to Downcast." << std::endl;
	}

	delete replaceA;
	delete replaceB;
	delete replaceC;
*/
};

void	identify(Base& p)
{
	//print out values without using pointer
	
};

/*
void	identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e) {}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e) {}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e) {}
};
*/
//------------------------------------------------------
//------------------------------------------------------

