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
Use std::ifstream to open and read files.
Use std::ofstream to open and write or append to files.

Always check if the file is successfully opened 
	using .is_open() before attempting to read or write.
*/
//
/*
--reference--
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

int	main(int argc, char **argv)
{
	std::ifstream	inputFile;
	std::ofstream	outputFile;
	std::string		name_inputFile;
	std::string		name_outputFile;	

	if (argc != 4)
	{
		std::cout << RED << "\tNeeds three Parameters" << RESET << std::endl;
		return (1);
	}
	//we usually don't include std::ios::in cause ifstream is always
	//open in read mode.
	inputFile.open(argv[1]);
	name_inputFile = argv[1];
	name_outputFile = name_inputFile + ".replace";
	if (!inputFile.is_open())
	{
		std::cerr << RED << "Unable to open file OR no such file!" \
		<< RESET << std::endl;
		return (1);
	}
	//https://cplusplus.com/reference/fstream/ofstream/open/
	//note that std::ios::out isn't really needed as it defaults to that mode
	// its just for reading clarity so better add anyways.
	outputFile.open(name_outputFile.c_str(), std::ios::out | std::ios::trunc);
	if (!outputFile.is_open())
	{
		std::cerr << RED << "Can't do outfile for some reason!!!" \
		<< RESET << std::endl;
		if (inputFile.is_open())
			inputFile.close();
		return (1);
	}
	read_and_replace(argv, &inputFile, &outputFile);//replaces the words here
	if (inputFile.is_open())
		inputFile.close();
	if (outputFile.is_open())
		outputFile.close();
	return (0);
}
*/
