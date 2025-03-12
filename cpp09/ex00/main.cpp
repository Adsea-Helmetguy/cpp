/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:41:30 by mlow              #+#    #+#             */
/*   Updated: 2025/03/11 09:41:31 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
# include <fstream>// for ofstream/ifstream/fstream
Use std::ifstream to open and read files.
Use std::ofstream to open and write or append to files.

Always check if the file is successfully opened 
	using .is_open() before attempting to read or write.
*/
//
/*
--reference--
static void	read_and_replace(char **argv,
	std::ifstream *inFile, std::ofstream *outFile)
{
	std::string	line;
	std::string s1(argv[2]);
	std::string s2(argv[3]);
	size_t		pos;

	while (getline((*inFile), line))
	{
		pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.replace(pos, s1.length(), s2);
			pos += s2.length();
		}
		(*outFile) << line << std::endl;
	}
}

int	main(int argc, char **argv)
{
	std::ifstream	inFile;
	std::ofstream	outFile;
	std::string		name_inputFile;
	std::string		name_outputFile;	

	if (argc != 4)
	{
		std::cout << RED << "\tNeeds three Parameters" << RESET << std::endl;
		return (1);
	}
	//we usually don't include std::ios::in cause ifstream is always
	//open in read mode.
	inFile.open(argv[1]);
	name_inputFile = argv[1];
	name_outputFile = name_inputFile + ".replace";
	if (!inFile.is_open())
	{
		std::cerr << RED << "Unable to open file OR no such file!" \
		<< RESET << std::endl;
		return (1);
	}
	//https://cplusplus.com/reference/fstream/ofstream/open/
	//note that std::ios::out isn't really needed as it defaults to that mode
	// its just for reading clarity so better add anyways.
	outFile.open(name_outputFile.c_str(), std::ios::out | std::ios::trunc);
	if (!outFile.is_open())
	{
		std::cerr << RED << "Can't do outfile for some reason!!!" \
		<< RESET << std::endl;
		if (inFile.is_open())
			inFile.close();
		return (1);
	}
	read_and_replace(argv, &inFile, &outFile);//replaces the words here
	if (inFile.is_open())
		inFile.close();
	if (outFile.is_open())
		outFile.close();
	return (0);
}
*/

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	int	return_value = 0;

	std::cout << MAG << "\n\n---------------" << RT << std::endl;
	{
		std::cout << GREEN << "Test (1)!" << RT << std::endl;

		//clear && make && clear && ./btc data.csv test1
		if (argc != 2)
		{
			std::cerr << RED << "\tNeeds \"argc = 2\", write like this: " \
				<< "\"./btc <second_database.txt here>\"\n" 
				<< "Error: could not open file." \
				<< RT << std::endl;
			return (1);
		}

		return_value = checking_infile(argv);
	}
	std::cout << MAG << "\n---------------" << RT << std::endl;
	std::cout << "\n\n" << std::endl;
	return (return_value);
};
