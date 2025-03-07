/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:12:23 by mlow              #+#    #+#             */
/*   Updated: 2025/03/05 19:12:58 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main(void)
{
	std::cout << "\n\n\n\n\n\n\n\n" << std::endl;
	std::cout << "---Official Test---" << std::endl;
	{
		MutantStack<int>	mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "\n\n" << std::endl;
		std::cout << mstack.size() << std::endl;
		
		std::cout << "\n\n" << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}


	std::cout << MAG << "\n\n\n" \
		<< "---Personal Test (1)[Recreated official test]---" \
		<< RT << std::endl;
	{
		std::cout << "----Constructor----" << std::endl;
		MutantStack<int>	mstack;
		std::cout << "----Constructor----\n" << std::endl;

		mstack.push(5);//mstack = [5]
		mstack.push(17);//mstack = [5, 17]
		
		std::cout << GREEN << "Checking mstack's value after [5, 17]:" \
			<< RT << mstack << std::endl;

		std::cout << YELLOW << "accessing \"TOP\" element: " << RT << mstack.top() << std::endl;

		mstack.pop();
	
		std::cout << YELLOW << "Total Current size = " << RT << mstack.size() << std::endl;
	
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
	
		std::cout << std::endl;
		std::cout << GREEN << "Checking mstack's value after [5, 17, 3, 5, 737, 0]:" \
			<< RT << mstack << std::endl;

		std::stack<int> s(mstack);
		while (s.size() > 0)
		{
			if (!s.empty()) {
				std::cout << YELLOW << "\"TOP\" element(Before poop): " << RT << s.top() << std::endl;
				s.pop();
			} else {
				std::cout << "Stack is empty! Can't poop." << std::endl;
			}
		}
		std::cout << "Damn my tests are more superior compared to the official one >;3." \
			"\n" << std::endl;
		std::cout << RED << "****Destructor Called here:****" << RT << std::endl;
	}


	std::cout << MAG << "\n\n\n" \
		<< "---Personal Test (2)[Testing for DeepCopy copy constructor]---" \
		<< RT << std::endl;
	{
		std::cout << "----Constructor----" << std::endl;
		MutantStack<int>	mstack;
		std::cout << "----Constructor----\n" << std::endl;

		mstack.push(5);//mstack = [5]
		mstack.push(17);//mstack = [5, 17]
		
		std::cout << GREEN << "Checking mstack's value:" \
			<< RT << mstack << std::endl;

		MutantStack<int>	mstack2(mstack);

		std::cout << GREEN << "Checking mstack2's value:" \
			<< RT << mstack2 << std::endl;
		std::cout << RED << "****Destructor Called here:****" << RT << std::endl;
	}


	std::cout << MAG << "\n\n\n" \
		<< "---Personal Test (3)[Testing for DeepCopy operator=()]---" \
		<< RT << std::endl;
	{
		std::cout << "----Constructor----" << std::endl;
		MutantStack<int>	mstack;
		std::cout << "----Constructor----\n" << std::endl;

		mstack.push(5);//mstack = [5]
		mstack.push(17);//mstack = [5, 17]
		
		std::cout << GREEN << "Checking mstack's value:" \
			<< RT << mstack << std::endl;

		MutantStack<int>	mstack2 = mstack;

		std::cout << GREEN << "Checking mstack2's value:" \
			<< RT << mstack2 << std::endl;
		std::cout << RED << "****Destructor Called here:****" << RT << std::endl;
	}
	std::cout << "\n\n" << std::endl;
	return (0);
};
