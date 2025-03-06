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
/*
	std::cout << "---Official Test---" << std::endl;
	{
		MutantStack<int>	mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

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
*/
	std::cout << MAG \
		<< "---Personal Test (1)[Recreated official test]---" \
		<< RT << std::endl;
	{
		std::cout << "----Constructor----" << std::endl;
		MutantStack<int>	mstack;
		std::cout << "----Constructor----\n" << std::endl;

		mstack.push(5);//mstack = [5]
		mstack.push(17);//mstack = [5, 17]
		
		std::cout << GREEN << "Checking mstack's value:" \
			<< RT << mstack << std::endl;

		std::cout << RED << "****Destructor Called here:****" << RT << std::endl;
	}
	std::cout << "\n\n" << std::endl;
	return (0);
};
