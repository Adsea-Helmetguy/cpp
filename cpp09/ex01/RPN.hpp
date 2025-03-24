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
# include <cstring>  // strtok()

# define RT	"\033[0m"
# define RED	"\033[31m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define CYAN	"\033[0;36m"
# define GREEN	"\033[32m"
# define MAG	"\e[0;35m"


void	RPN_code(int argc, char **argv);
void	RPN_argv2code(std::string string);
int     sizeof_array(char *argv);
bool	fundamental_operations(char character);

#endif
