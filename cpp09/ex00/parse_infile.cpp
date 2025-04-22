/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infile.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:48:56 by mlow              #+#    #+#             */
/*   Updated: 2025/03/20 11:49:12 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//Skips the first line "date | value", else restart
std::string	remove_first_line(std::ifstream *inFile, char find)
{
	std::string	line;
	size_t		pipe_index = 0;

	std::getline(*inFile, line);
	pipe_index = line.find(find);
	if (pipe_index == std::string::npos)// No '|' found in line
	{
		inFile->clear();//clears the EOF state of the file so that
		inFile->seekg(0);// this can be used to seek start of file.
		return (line);
	}

	std::string	datestr = line.substr(0, pipe_index);
	datestr.erase(remove_if(datestr.begin(), datestr.end(), isspace), datestr.end());
	if (datestr != "date")
	{
		inFile->clear();//clears the EOF state of the file so that
		inFile->seekg(0);// this can be used to seek start of file.
	}
	return (line);
};

//find the char you want, updates location of the char as well
int	find_char(std::string *inside_line, size_t *index, char character)
{
	*index = inside_line->find(character);
	if (*index == std::string::npos)
	{
		std::cerr << RED << "Error: Missing '|' in line -> \"" << *inside_line \
			<< "\"" << RT << "\n----------------\n" << std::endl;
		return (1);
	}
	return (0);
};

//https://stackoverflow.com/questions/12947607/string-to-float-using-stringstream
bool	convertFloat(const std::string& valuestr)
{
	std::stringstream ss(valuestr);
	float	f;

	ss >> f;
	//std::cout << "STRING: \"" << GREEN << ss.str() << RT << "\"" 
	//	<< " | FLOAT IS: \"" << GREEN << f << RT << "\"" << std::endl;
	if (!(ss.eof()))
	{
	 	std::cerr << RED << "THERE ARE LEFTOVERS!!!" << RT << std::endl;
	  	return (false);
	}
		
	return (true);
};

int	parse_inFile(std::ifstream *inFile, std::map<std::string, float> *datacsv_file)
{
	size_t		pipe_index = 0;
	int			return_value = 0;
	std::string	line = remove_first_line(inFile, '|');

	while (std::getline(*inFile, line))
	{
		std::cout << "----------------" << std::endl;
		if (find_char(&line, &pipe_index, '|') == 1)
			continue;

		std::string	datestr = line.substr(0, pipe_index);
		std::string	valuestr = line.substr(pipe_index + 1, std::string::npos);

		datestr.erase(remove_if(datestr.begin(), datestr.end(), isspace), datestr.end());
		valuestr.erase(remove_if(valuestr.begin(), valuestr.end(), isspace), valuestr.end());
		if (*valuestr.begin() < 48 || *valuestr.begin() > 57 || !(convertFloat(valuestr)))
		{
			std::cerr << YELLOW << "(" << valuestr << ")" << RED \
				<< " is not a number! NEXT!" << RT << std::endl;
			std::cout << "----------------\n" << std::endl;
			continue ;
		}

		char	*endptr_value;//stores address of first non-coverted char
		float	value = std::strtof(valuestr.c_str(), &endptr_value);

		std::cout << GREEN << "             Date: " << datestr << std::flush;
		std::cout << " | Value: " << value << RT << std::endl;

		//if string_converter is == 1, fail it or something
		string_converterDate(datestr, value, datacsv_file);
		std::cout << "----------------\n" << std::endl;
	}
	return (return_value);
};
