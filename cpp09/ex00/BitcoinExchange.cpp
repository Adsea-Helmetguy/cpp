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

static bool	correct_format_checker(std::string str)
{
	if (str.size() != 10 || str[4] != '-' || str[7] != '-')
	{
		std::cout << RED << "Invalid date! Expected \"YYYY-MM-DD\"!" << RT << std::endl;
		return (false);
	}
	return (true);
};

static bool	year_month_day_getter(std::string str, float value, \
			std::map<std::string, float> *datacsv_file)
{
	unsigned int	year = 0, month = 0, day = 0;
	char		dash1, dash2;

	std::stringstream ss(str);
	ss >> year >> dash1 >> month >> dash2 >> day;//skips non-number
	if (ss.fail() || dash1 != '-' || dash2 != '-')
	{
		std::cout << RED << "Invalid date! Expected YYYY-MM-DD" << RT << std::endl;
		return (false);
	}
	std::cout << "Extracted Date -> " << CYAN << "Year: " << year \
		<< ", Month: " << month << ", Day: " << day << RT << std::endl;

	if (check_current_date(&year, &month, &day, datacsv_file) == 1)
		return (false);
	if (value < 0 || value > 1000)
	{
		std::cerr << RED << "Error, not between 0-1000." << RT << std::endl;
		return (false);
	}
	return (true);
};

void	string_converterDate(std::string str, float value, \
		std::map<std::string, float> *datacsv_file)
{

	//Check if it's a date first.
	if (!(correct_format_checker(str)))
		return ;

	//extract and check the date:
	if (!(year_month_day_getter(str, value, datacsv_file)))
		return ;

	//Finally, Final part:
	//compare dates year-month-day vs std::map's yyyy-mm-dd
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
	}

	//work on currency exchange
	std::cout << GREEN << "\nTime to exchange the values with datacsv!" << RT << std::endl;
	std::cout << YELLOW << "Year[" << RT << str << YELLOW << CYAN << "(" << value << " * " 
		<< lowest_value->second << ")" << YELLOW << "] => " << RT << value << YELLOW \
		<< " = " << RT << (value * lowest_value->second) << std::endl;
}

int	checking_infile(char **argv)
{
	std::ifstream	inFile;
	std::ifstream	csvFile;

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

	std::cout << YELLOW << "PARSING the data.csv file..." << RT << std::endl;
	std::map<std::string, float> datacsv_file = parse_csvfile(&csvFile);
	if (datacsv_file.empty())
		return (1);
	parse_inFile(&inFile, &datacsv_file);
	if (inFile.is_open())
		inFile.close();
	if (csvFile.is_open())
		csvFile.close();
	return (0);
};

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
