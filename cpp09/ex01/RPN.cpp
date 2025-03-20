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

static int	calender_dates(unsigned int *month, unsigned int *current_day)
{
	unsigned int	total_days = 0;

	if (*month == 1 || *month == 3 || *month == 5 || *month == 7 \
		|| *month == 8 || *month == 10 || *month == 12)
	{
		total_days = 31;
	}
	else if (*month == 4 || *month == 6 || *month == 9 || *month == 11)
	{
		total_days = 30;
	}
	else if (*month == 2)
	{
		total_days = 28;
	}
	else
		return (1);
	
	if (*current_day < 1 || *current_day > total_days)
	{
		std::cerr << RED << "HEY YOUR DATE MAKE NO SENSE! CHECK CALENDER!!" \
			<< RT << std::endl;
		return (1);
	}
	return (0);
};

static int	check_current_date(unsigned int *year, unsigned int *month, \
	unsigned int *day, std::map<std::string, float> *datacsv_file)
{
	time_t timestamp;
	struct tm* datetime;
	unsigned int	earliest_year = 0, earliest_month = 0, earliest_day = 0;

	if (!(datacsv_file->empty()))
	{
		//first means the left side of <std::string, float>.
		std::string	earliest_date = datacsv_file->begin()->first;
		char	dash11, dash22;
		std::stringstream ss2(earliest_date);
		//std::cout << "What is in ss2?: " << ss2.str() << std::endl;
		ss2 >> earliest_year >> dash11 >> earliest_month >> dash22 >> earliest_day;
		if (ss2.fail() || dash11 != '-' || dash22 != '-')
		{
			std::cout << "Invalid date format! Expected YYYY-MM-DD" << std::endl;
			return (1);
		}
		std::cout << "Earliest EXTRACTED Date -> " << GREEN << "Earliest_year: " << earliest_year \
			<< ", Earliest_month: " << earliest_month << ", Earliest_day: " \
			<< earliest_day << RT << std::endl;
	}

	time(&timestamp);// Applying time()
	datetime = localtime(&timestamp);// Using localtime()
	unsigned int	current_year = static_cast<unsigned int>(datetime->tm_year + 1900);//years since 1900
	unsigned int	current_month = static_cast<unsigned int>(datetime->tm_mon + 1);//was (0-11) now its (1-12)
	unsigned int	current_day = static_cast<unsigned int>(datetime->tm_mday);

	//checking if date is valid
	if (*year < earliest_year || *year > current_year ||
		(*year == current_year && *month > current_month) ||
		(*year == earliest_year && *month < earliest_month) ||
		(*year == earliest_year && *month > 12) ||
		(*year == current_year && *month == current_month && *day > current_day) ||
		(*year == earliest_year && *month == earliest_month && *day < earliest_day) ||
		(calender_dates(month, day) == 1))
	{
		std::cout << "Current Date -> " << RED << "Invalid date: "\
			<< "Date is out of range! RETURN (1)!" << RT << std::endl;
		return (1);
	}
	std::cout << "Current Date -> " << GREEN << "Year: " << current_year \
		<< ", Month: " << current_month << ", Day: " << current_day << RT << std::endl;
	return (0);
};

//while it's not a '-' or '\0', copy and then convert to int
static void	string_converterDate(std::string str, float value, \
	std::map<std::string, float> *datacsv_file)
{

	//Check if it's a date first.
	if (str.size() != 10 || str[4] != '-' || str[7] != '-')
	{
		std::cout << RED << "Invalid date format! Expected YYYY-MM-DD" << RT << std::endl;
		return ;
	}

	//extract the date:
	unsigned int year = 0, month = 0, day = 0;
	char	dash1, dash2;
	std::stringstream ss(str);
	ss >> year >> dash1 >> month >> dash2 >> day;//skips non-number
	if (ss.fail() || dash1 != '-' || dash2 != '-')
	{
		std::cout << "Invalid date format! Expected YYYY-MM-DD" << std::endl;
		return ;
	}
	std::cout << "Extracted Date -> " << CYAN << "Year: " << year \
		<< ", Month: " << month << ", Day: " << day << RT << std::endl;

	if (check_current_date(&year, &month, &day, datacsv_file) == 1)
		return ;
	if (value < 0 || value > 1000)
	{
		std::cerr << RED << "Error, not between 0-1000." << RT << std::endl;
		return ;
	}
	
	//compare dates year-month-day vs std::map<std::string's> yyyy-mm-dd
	std::map<std::string, float>::iterator	lowest_value = datacsv_file->lower_bound(str);
	
	if (lowest_value == datacsv_file->end())
	{
		lowest_value--;
		std::cout << "Datacsv went past the last day, giving last day[" << CYAN \
			<< lowest_value->first << RT << "] => " << CYAN << lowest_value->second \
			<< RT << std::endl;
	}
	else if (lowest_value != datacsv_file->begin())
	{
		lowest_value--;
		std::cout << "Closets value that match Extracted Date: " << CYAN << lowest_value->first
			<< " | Value: " << lowest_value->second << RT << std::endl;
		//(--lowest_value)->first/second
	}

	//work on currency exchange
	std::cout << GREEN << "\nTime to exchange the values with datacsv!" << RT << std::endl;
	std::cout << YELLOW << "Year[" << RT << str << YELLOW << CYAN << "(" << value << " * " 
		<< lowest_value->second << RT << ")" << YELLOW << "] => " << RT << value << YELLOW \
		<< " = " << RT << (value * lowest_value->second) << std::endl;
}

//make sure that data.csv cannot be higher than current date and lesser than earilest date in .csv
int	parse_inFile(std::ifstream *inFile, std::ofstream *outFile, std::map<std::string, float> *datacsv_file)
{
	std::string	line;
	size_t		pipe_index;
	int		return_value = 0;

	//	Skips the first line "date | value", else restart.
	std::getline(*inFile, line, '|');
	line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
	std::cout << "value of line[" << line << "]" << std::endl;
	if (line == "date")
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
		std::string	datestr = line.substr(0, pipe_index);
		std::string	valuestr = line.substr(pipe_index + 1, std::string::npos);
		
		datestr.erase(remove_if(datestr.begin(), datestr.end(), isspace), datestr.end());
		valuestr.erase(remove_if(valuestr.begin(), valuestr.end(), isspace), valuestr.end());
		if (*valuestr.begin() < 48 || *valuestr.begin() > 57)
		{
			std::cerr << RED << "This is not a number! NEXT!" << RT << std::endl;
			continue ;
		}

		//3) Convert value to int/float
		std::cout << YELLOW << "--Converting Values to float--" << RT << std::endl;
		char	*endptr_value;//stores address of first non-coverted char
		float	value = std::strtof(valuestr.c_str(), &endptr_value);

		std::cout << YELLOW << " Date: " << RT << datestr << std::endl;
		std::cout << YELLOW << "Value: " << RT << value << std::endl;

		//if string_converter is == 1, fail it or something
		string_converterDate(datestr, value, datacsv_file);
		std::cout << "----------------\n" << std::endl;
	}
	(void)outFile;
	return (return_value);
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
	line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
	std::cout << "value of line[" << line << "]" << std::endl;
	if (line == "date")
		std::getline((*csvFile), line);
	else
	{
		csvFile->clear();//clears the EOF state of the file so that
		csvFile->seekg(0);// this can be used to seek start of file.
	}

	std::map<std::string, float>	datacsv_file;
	while (std::getline(*csvFile, line))
	{
		//str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
		//std::cout << "----------------" << std::endl;
		pipe_index = line.find(',');
		if (pipe_index == std::string::npos)  // No '|' found in line
		{
			std::cerr << RED << "Error: Missing ',' in line -> " << line \
				<< RT << "\n----------------\n" << std::endl;
			continue;
		}
		//std::cout << "COMMA FOUND->[" << GREEN << pipe_index
		//	<< RT << "]\n" << std::endl;
		
		//2) Now extract date and value
		std::string	datestr = line.substr(0, pipe_index);
		std::string	valuestr = line.substr(pipe_index + 1, std::string::npos);

		//Remove '-' char string by converting it to isspace
		//std::replace(datestr.begin(), datestr.end(), '-', ' ');

		//remove spaces
		datestr.erase(remove_if(datestr.begin(), datestr.end(), isspace), datestr.end());
		valuestr.erase(remove_if(valuestr.begin(), valuestr.end(), isspace), valuestr.end());
		if (*valuestr.begin() < 48 || *valuestr.begin() > 57)
		{
			std::cerr << RED << "This is not a number! NEXT!" << RT << std::endl;
			continue ;
		}
		std::cout << YELLOW << " Date: " << RT << datestr << std::endl;
		std::cout << YELLOW << "Value: " << RT << valuestr << std::endl;

		//3) Convert value to int/float and store in std::map
		//std::cout << YELLOW << "--Converting Values to float--" << RT << std::endl;
		char	*endptr_value;//stores address of first non-coverted char
		float	value = std::strtof(valuestr.c_str(), &endptr_value);

		datacsv_file[datestr] = value;
		//std::cout << "datacsv[" << datestr << "]: " << datacsv_file[datestr] << std::endl;

		
		//std::cout << "----------------\n" << std::endl;
	}
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
	return (datacsv_file);
};

int	checking_infile(char **argv)
{
	std::ifstream	inFile;
	std::ifstream	csvFile;
	std::ofstream	outFile;
	std::string		name_outputFile = "output.txt";

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
	if (datacsv_file.empty())
		return (1);
	parse_inFile(&inFile, &outFile, &datacsv_file);
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

--std::strtof--
https://cplusplus.com/reference/cstdlib/strtof/

--Why create a *endptr for std::strol and std::strtof--
https://stackoverflow.com/questions/18970237/c-using-strtol-endptr-is-never-null-cannot-check-if-value-is-integer-only

--here explains where the first and second from--(note, look at operator[] to see specifics)
https://en.cppreference.com/w/cpp/container/map/operator_at
*/
