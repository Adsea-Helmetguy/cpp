/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:34:28 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:34:30 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//https://www.twitch.tv/shashshy
//miss uptoyou LOL

void    Scalar_value(const std::string& value, const size_t strlen)
{
    //--Detect the type of value the string it passes
    //char -check if its only one char-
    std::cout << "testing for strlen value of: " \
        << GREEN << "\"" << value << "\"" << RESET << std::endl;
    std::cout << MAG << strlen << RESET << std::endl;
    //Scalar_checkChar(value, strlen);
    //Scalar_checkInt(value, strlen);
    //Scalar_checkFloat(value, strlen);
    //Scalar_checkDouble(value, strlen);
    //Checking if it's part of the ASCII Table and if its only one char
    if (strlen == 1)
    {
        std::cout << "confirmed it's only length of " << std::endl;
        std::cout << GREEN << "\"1\"" << RESET << std::endl;
        //Checking ASCII TABLE
        if (value[0] < 127 || value[0] > 31)
        {
            //obtain char!
            std::cout << GREEN << "Value(char) is part of ASCII printable" \
                RESET << std::endl;
            if (value[0] < 48 || value[0] > 57)
            {
                
            }
        }
        else
        {
            //put error
            std::cout << RED << "Value is ERROR!" \
                RESET << std::endl;
        }
    }
};

//void  Scalar_checkChar(const std::string& value, const size_t strlen);

void    Scalar_type(const std::string& value)
{
    //--Conver it from string to actual type!
    //Scalar_type()
    (void)value;

    //These are for printing
    //Scalar_typeChar(value, strlen);
    //Scalar_typeInt(value, strlen);
    //Scalar_typeFloat(value, strlen);
    //Scalar_typeDouble(value, strlen);
};























