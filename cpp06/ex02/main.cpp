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

	//------------------------------------
	Base *ptr = generate();
	//Base &ref = *ptr;
	identify(ptr);//this should print either 'A', 'B' Or 'C'
	identify(*ptr);//prints it's address....i think. if not use below:
	//identify(ref);
	//------------------------------------
	
	delete ptr; // Avoid memory leak
    }
    return (0);
}
