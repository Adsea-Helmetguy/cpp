/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:41:40 by mlow              #+#    #+#             */
/*   Updated: 2025/03/11 09:41:41 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*
stringstream stream("asdsdgdgdfg gsdgdsg dghgh gh");
string str;
vector strings;
while (stream >> str) {
	strings.push_back(str);
}
*/
//output to outfile:
//	(*outFile) << line << std::endl;
void	parse_csvfile(std::ifstream *inFile, std::ofstream *outFile)
{
	//std::string	line;
	std::string	date;
	std::string	value;

	(void)outFile;
	//1)read the file line by line
	//while (std::getline((*inFile), line))
	while (std::getline(*inFile, date, '|'))
	{
		std::cout << " Date: " << GREEN << date << RT << std::endl;
		if (std::getline(*inFile, value))
		{
			//std::cout << date << " " << value << std::endl; // Write without '|'
			std::cout << "   Value: " << GREEN << value << RT << std::endl;
		}
		//2)Split each line into date and exchange rate.
		//size_t	pipe_index = line.find('|');//if none found, std::string::npos is returned
		//if (pipe_index != std::string::npos)
		//{
		//	line.erase(pipe_index, 1);
		//}
		//std::cout << "   After-> " << YELLOW << line << RT << std::endl;
		std::cout << std::endl;
		//std::getline((*inFile), (*outFile), '|');
		
	}
	//3)Store them in the std::map.
};

int	checking_infile(char **argv)
{
	std::ifstream	inFile;
	std::ofstream	outFile;
	std::string	name_outputFile = "output.txt";

	//open in read mode.
	inFile.open(argv[1]);
	if (!inFile.is_open())
	{
		std::cerr << RED << "Unable to open file OR no such file!" \
			<< RT << std::endl;
		return (1);
	}

	//std::ios::out -> default
	//std::ios::trunc -> If the file exist, contents gg first then write
	outFile.open(name_outputFile.c_str(), std::ios::out | std::ios::trunc);
	if (!outFile.is_open())
	{
		std::cerr << "Error opening output file!" << std::endl;
		return (1);
	}
	parse_csvfile(&inFile, &outFile);
	if (inFile.is_open())
		inFile.close();
	if (outFile.is_open())
		outFile.close();
	return (0);
}
//void	parse_infile(char **argv, std::ifstream *inFile, std::ofstream *outFile){};

