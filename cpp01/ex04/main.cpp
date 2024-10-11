/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:34:13 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:34:18 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Use std::ifstream to open and read files.
Use std::ofstream to open and write or append to files.

Always check if the file is successfully opened 
	using .is_open() before attempting to read or write.
*/
#include "Replace.hpp"

static void	read_and_replace(char **argv,
	std::ifstream *inputFile, std::ofstream *outputFile)
{
	std::string	line;
	std::string s1(argv[2]);
    std::string s2(argv[3]);
	size_t		pos;

	while (getline((*inputFile), line))
    {
		pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.replace(pos, s1.length(), s2);
			pos += s2.length();
		}
		(*outputFile) << line << std::endl;
    }
}

//e.g (./replace filename s1 s2)
int	main(int argc, char **argv)
{
	std::ifstream	inputFile;
	std::ofstream	outputFile;
	std::string		name_inputFile;
	std::string		name_outputFile;	

	if (argc != 4)
	{
		std::cout << " Needs three Parameters" << std::endl;
		return (1);
	}
	inputFile.open(argv[1]);
	name_inputFile = argv[1];
	name_outputFile = name_inputFile + ".replace";
	outputFile.open(name_outputFile.c_str(), std::ios::binary);
	if (!inputFile.is_open() || !outputFile.is_open())
	{
		std::cerr << "Unable to open file!" << std::endl;
		if (inputFile.is_open())
			inputFile.close();
		return (1);
	}
	read_and_replace(argv, &inputFile, &outputFile);
	inputFile.close();
	outputFile.close();
	return (0);
}
