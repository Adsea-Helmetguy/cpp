/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:34:13 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:34:18 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_file/Base.hpp"

int	main(void)
{
    {
	srand(time(0));
	std::cout << "\n\n\n\n" << std::endl;
	//------------------------------------
	std::cout << MAG << "\n\n-Creating Base *ptr--" << RT << std::endl;
	Base *ptr = generate();
	Base &ref = *ptr;
	
	std::cout << MAG << "\n\n-test ptr--" << RT << std::endl;
	identify(ptr);//this should print either 'A', 'B' Or 'C'
	
	std::cout << MAG << "\n\n--test *ptr--" << RT << std::endl;
	identify(*ptr);//prints the result from ["void	identify(Base& p)"]
	
	std::cout << MAG << "\n\n--test ref--" << RT << std::endl;
	identify(ref);
	//------------------------------------
	
	delete ptr; // Avoid memory leak
    }
    std::cout << MAG << "\n\n\n\n" << RT << std::endl;
    return (0);
};
