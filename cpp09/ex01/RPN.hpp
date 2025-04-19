/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:41:45 by mlow              #+#    #+#             */
/*   Updated: 2025/03/11 09:41:46 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BITCOINEXCHANGE_HPP
#define	BITCOINEXCHANGE_HPP

# include <iostream>// std::cout/std::endl
# include <string>// std::string, std::getline, std::stoi
# include <sstream>// std::stringstream
# include <stack>//std::map
# include <cctype>//std::isspace

# define RT	"\033[0m"
# define RED	"\033[31m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define CYAN	"\033[0;36m"
# define GREEN	"\033[32m"
# define MAG	"\e[0;35m"

//methods to solve
void	RPN_code(int argc, char **argv);
void	RPN_argv2code(std::string string);

//workings
int     sizeof_array(char *argv);

//Helper_function.cpp
float	compare_two_values(float v1, float v2, char character);
float	convert_token(const char *string);
float	convert_token_argv2(std::string string);
bool	fundamental_operations(char character);
bool	fundamental_operations_argv2(char character);
void	after_comparing(std::stack<float> *int_array, char character, int *operation_counter);
#endif
