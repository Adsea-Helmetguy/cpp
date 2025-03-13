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
//
/*
--edit this to work for your parse_inFile--
	std::string	line;

	std::cout << YELLOW << "PARSING the data.csv file..." << RT << std::endl;
	std::getline(*csvFile, line, ',');
	if (line == "date")
		std::getline((*csvFile), line);
	else
	{
		csvFile->clear();//clears the EOF state of the file so that
		csvFile->seekg(0);// this can be used to seek start of file.
	}

	std::string	date;
	char		separator;
	float		value;
	while (std::getline(*csvFile, line))
	{
		std::stringstream	lineStream(line);

		
		//str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
		std::cout << "----------------" << std::endl;
		lineStream >> date >> separator >> value;
		std::cout << "     Date: " << date << std::endl;
		std::cout << "Separator: " << separator << std::endl;
		std::cout << "    Value: " << value << std::endl;
		std::cout << "----------------\n" << std::endl;
	}
*/
void	parse_inFile(std::ifstream *inFile, std::ofstream *outFile)
{
	std::string	line;
	size_t		pipe_index;

	//	Skips the first line "date | value", else restart.
	std::getline(*inFile, line, '|');
	if (line == "date ")
		std::getline((*inFile), line);
	else
	{
		inFile->clear();//clears the EOF state of the file so that
		inFile->seekg(0);// this can be used to seek start of file.
	}
	
	//1)read the file line by line
	while (std::getline(*inFile, line))
	{
		//str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
		std::cout << "----------------" << std::endl;
		pipe_index = line.find('|');
		if (pipe_index == std::string::npos)  // No '|' found in line
		{
			std::cerr << RED << "Error: Missing '|' in line -> " << line \
				<< RT << "\n----------------\n" << std::endl;
			continue;
		}
		std::cout << "PIPE FOUND->[" << GREEN << pipe_index \
			<< RT << "]\n" << std::endl;
		
		//2) Now extract date and value
		std::string	date = line.substr(0, pipe_index);
		std::string	value = line.substr(pipe_index + 1, std::string::npos);
		
		date.erase(remove_if(date.begin(), date.end(), isspace), date.end());
		value.erase(remove_if(value.begin(), value.end(), isspace), value.end());
		std::cout << YELLOW << " Date: " << RT << date << std::endl;
		std::cout << YELLOW << "Value: " << RT << value << std::endl;
		
		std::cout << "----------------\n" << std::endl;
	}
	(void)outFile;
};

//https://www.youtube.com/watch?v=S2pvOeWyqBc --how to parse csvFile--
//https://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c
//create a class to store the value of std::map
std::map<std::string, float>	parse_csvfile(std::ifstream *csvFile)//Store them in the std::map.
{
	std::string	line;
	size_t		pipe_index;

	std::cout << YELLOW << "PARSING the data.csv file..." << RT << std::endl;
	std::getline(*csvFile, line, ',');
	if (line == "date")
		std::getline((*csvFile), line);
	else
	{
		csvFile->clear();//clears the EOF state of the file so that
		csvFile->seekg(0);// this can be used to seek start of file.
	}

	while (std::getline(*csvFile, line))
	{
		//str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
		std::cout << "----------------" << std::endl;
		pipe_index = line.find(',');
		if (pipe_index == std::string::npos)  // No '|' found in line
		{
			std::cerr << RED << "Error: Missing ',' in line -> " << line \
				<< RT << "\n----------------\n" << std::endl;
			continue;
		}
		std::cout << "COMMA FOUND->[" << GREEN << pipe_index \
			<< RT << "]\n" << std::endl;
		
		//2) Now extract date and value
		std::string	date = line.substr(0, pipe_index);
		std::string	value = line.substr(pipe_index + 1, std::string::npos);
		
		date.erase(remove_if(date.begin(), date.end(), isspace), date.end());
		value.erase(remove_if(value.begin(), value.end(), isspace), value.end());
		std::cout << YELLOW << " Date: " << RT << date << std::endl;
		std::cout << YELLOW << "Value: " << RT << value << std::endl;

		// Convert value to float
		
		//now throw them inside std::map
		std::map<std::string, float> datacsv_file
		//std::map done
		std::cout << "----------------\n" << std::endl;
	}
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
};

int	checking_infile(char **argv)
{
	std::ifstream	inFile;
	std::ifstream	csvFile;
	std::ofstream	outFile;
	std::string	name_outputFile = "output.txt";

	//open in read mode.
	inFile.open(argv[1], std::ios::in);
	if (!inFile.is_open())
	{
		std::cerr << RED << "Unable to open file OR no such file!" \
			<< RT << std::endl;
		return (1);
	}
	csvFile.open("data.csv", std::ios::in);
	if (!csvFile.is_open())
	{
		std::cerr << RED << "Unable to open file OR no such file!" \
			<< RT << std::endl;
		if (inFile.is_open())
			inFile.close();
		return (1);
	}

	//std::ios::out -> default
	//std::ios::trunc -> If the file exist, contents gg first then write
	outFile.open(name_outputFile.c_str(), std::ios::out | std::ios::trunc);
	if (!outFile.is_open())
	{
		std::cerr << "Error opening output file!" << std::endl;
		if (inFile.is_open())
			inFile.close();
		if (csvFile.is_open())
			csvFile.close();
		return (1);
	}
	std::map<std::string, float> datacsv_file = parse_csvfile(&csvFile);
	parse_inFile(&inFile, &outFile);
	if (inFile.is_open())
		inFile.close();
	if (csvFile.is_open())
		csvFile.close();
	if (outFile.is_open())
		outFile.close();
	return (0);
};
//void	parse_infile(char **argv, std::ifstream *inFile, std::ofstream *outFile){};





//links:
/*
--inFile.clear()/seekg()--
https://stackoverflow.com/questions/5343173/returning-to-beginning-of-file-after-getline

--Removing isspace in std::string--
https://stackoverflow.com/questions/83439/remove-spaces-from-stdstring-in-c
*/
