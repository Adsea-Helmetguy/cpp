/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:35:33 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:35:35 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>//std::string
#include <cctype>
#include <iomanip> //for std::setw
#include <sstream>
#include <new>

int	main(void) 
{
    std::string	string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "String address: " << &string << std::endl;
    std::cout << "StringPTR address: " << stringPTR << std::endl;
    std::cout << "StringRef address: " << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "String value: " << string << std::endl;
    std::cout << "StringPTR value: " << *stringPTR << std::endl;
    std::cout << "StringRef value: " << stringREF << std::endl;

    return (0);
}
