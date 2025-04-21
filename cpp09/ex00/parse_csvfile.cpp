/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_csvfile.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:50:07 by mlow              #+#    #+#             */
/*   Updated: 2025/03/20 11:50:16 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//create a class to store the value of std::map
std::map<std::string, float>	parse_csvfile(std::ifstream *csvFile)//Store them in the std::map.
{
	std::string	line = remove_first_line(csvFile, ',');
	size_t		pipe_index;
	std::map<std::string, float>	datacsv_file;

	while (std::getline(*csvFile, line))
	{
		if (find_char(&line, &pipe_index, ',') == 1)
			continue;

		std::string	datestr = line.substr(0, pipe_index);
		std::string	valuestr = line.substr(pipe_index + 1, std::string::npos);

		datestr.erase(remove_if(datestr.begin(), datestr.end(), isspace), datestr.end());
		valuestr.erase(remove_if(valuestr.begin(), valuestr.end(), isspace), valuestr.end());
		if (*valuestr.begin() < 48 || *valuestr.begin() > 57)
		{
			std::cerr << YELLOW << "\"" << datestr << "\" " \
				<< ", (" << valuestr << ")" << RED \
				<< " is not a number! NEXT!" << RT << std::endl;
			continue ;
		}

		char	*endptr_value;//stores address of first non-coverted char
		float	value = std::strtof(valuestr.c_str(), &endptr_value);

		datacsv_file[datestr] = value;
	}
	return (datacsv_file);
};






//links
/*
//https://www.youtube.com/watch?v=S2pvOeWyqBc --how to parse csvFile--
//https://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c
*/
