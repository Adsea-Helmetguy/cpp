/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
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
# include <string>// std::string, std::getline
# include <fstream>// ofstream/ifstream/fstream
# include <algorithm>// begin(), end()
# include <sstream>// std::stringstream

# define RT	"\033[0m"
# define RED	"\033[31m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define CYAN	"\033[0;36m"
# define GREEN	"\033[32m"
# define MAG	"\e[0;35m"


int	checking_infile(char **argv);
void	parse_inFile(std::ifstream *inFile, std::ofstream *outFile);
std::map<std::string, float>	parse_csvfile(std::ifstream *csvFile);
//void	parse_infile(char **argv, std::ifstream *inFile, std::ofstream *outFile)


#endif
