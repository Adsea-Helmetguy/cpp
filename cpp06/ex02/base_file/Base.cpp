/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:18:25 by mlow              #+#    #+#             */
/*   Updated: 2025/02/04 15:18:30 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

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
		std::cout << GREEN << "Random_letter" << RT << " = " \
			<< YELLOW << letters[index] << RT << std::endl;
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
//1. Dynamic_cast is used at run time to find out correct down/up-cast
/*
//https://www.youtube.com/watch?v=wE4beL95pIo
Note1: Need at least 1 virtual function in base class
Note2: If the Cast is sucessful, dynamic_cast returns a value of type new_type
Note3: If the cast fails and new_type is a pointer type, it returns a nullpointer
		of that type.
Note4: If the cast fails and new_type is a reference type, it throws and exception 
		that matches the handler of type std::bad cast


Note5: This works only on polymorphic base class (at least on virtual function)
Note6: Used for up-cast(D->B) and down-cast(B->D), but mainly correct downcast
Note7: Checks during run time (RTTI)
*/
void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "downcast for \"A\" successful!!\n" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "downcast for \"B\" successful!!\n" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "downcast for \"C\" successful!!\n" << std::endl;
	else
		std::cout << "Failed to Downcast. nullptr." << std::endl;
};

//https://www.youtube.com/watch?v=wE4beL95pIo
//to learn how to use reference
//NO POINTERS ALLOWED
void	identify(Base& p)
{
	//print out values without using pointer
	try
	{
		A &a1 = dynamic_cast<A&>(p);
		(void)a1;
		std::cout << GREEN << "Base A!!" << RT << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << "Identify Exception for Base A: " \
			<< RED << e.what() << RT << std::endl;
	}

	try
	{
		B &b1 = dynamic_cast<B&>(p);
		(void)b1;
		std::cout << GREEN << "Base B!!" << RT << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << "Identify Exception for Base B: " \
			<< RED << e.what() << RT << std::endl;
	}

	try
	{
		C &c1 = dynamic_cast<C&>(p);
		(void)c1;
		std::cout << GREEN << "Base C!!" << RT << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << "Identify Exception for Base C: " \
			<< RED << e.what() << RT << std::endl;
	}
};
