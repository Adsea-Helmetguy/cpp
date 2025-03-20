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
# include <string>// std::string, std::getline, std::stoi
# include <fstream>// ofstream/ifstream/fstream
# include <algorithm>// begin(), end()
# include <sstream>// std::stringstream
# include <map>//std::map
# include <cstdlib>
# include <ctime> //ctime
# include <iostream>

# define RT	"\033[0m"
# define RED	"\033[31m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define CYAN	"\033[0;36m"
# define GREEN	"\033[32m"
# define MAG	"\e[0;35m"

//main files
int	checking_infile(char **argv);

//parsing input.txt file
bool		convertFloat(const std::string& valuestr);
std::string	remove_first_line(std::ifstream *inFile, char find);
int			find_char(std::string *inside_line, size_t *index, char character);
int			parse_inFile(std::ifstream *inFile, std::map<std::string, float> *datacsv_file);

//parsing data.csv file
std::map<std::string, float>	parse_csvfile(std::ifstream *csvFile);

//calender --to compare dates for usage--
int	calender_dates(unsigned int *year, unsigned int *month, unsigned int *current_day);
int	check_current_date(unsigned int *year, unsigned int *month, \
		unsigned int *day, std::map<std::string, float> *datacsv_file);

//comparing data
void	string_converterDate(std::string str, float value, \
		std::map<std::string, float> *datacsv_file);

#endif
