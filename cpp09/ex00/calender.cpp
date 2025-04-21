/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calender.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:51:07 by mlow              #+#    #+#             */
/*   Updated: 2025/03/20 11:51:12 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static bool	leap_year(unsigned int year)
{
	if ((year % 4) == 0)
	{
		if ((year % 100) == 0)
		{
			if ((year % 400) == 0)
				return (true);// Divisible by 400 → Leap year
			return (false);// Divisible by 100 but not 400 → FAIL
		}
		return (true);// Divisible by 4 but not 100 → Leap year
	}
	return (false);// Not Divisible by 4 → FAIL
};

int	calender_dates(unsigned int *year, unsigned int *month, unsigned int *current_day)
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
	else if (*month == 2 && leap_year(*year))
	{
		total_days = 29;
	}
	else if (*month == 2 && !(leap_year(*year)))
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

int	check_current_date(unsigned int *year, unsigned int *month, \
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
			std::cout << YELLOW << "Invalid date format! Expected YYYY-MM-DD" << RT << std::endl;
			return (1);
		}
		//std::cout << "Earliest EXTRACTED Date -> " << GREEN << "Earliest_year: " << earliest_year 
		//	<< ", Earliest_month: " << earliest_month << ", Earliest_day: " 
		//	<< earliest_day << RT << std::endl;
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
		(calender_dates(year, month, day) == 1))
	{
		std::cout << "Current Date -> " << RED << "Invalid date: "\
			<< "Date is out of range! RETURN (1)!" << RT << std::endl;
		return (1);
	}
	//std::cout << "Current Date -> " << GREEN << "Year: " << current_year 
	//	<< ", Month: " << current_month << ", Day: " << current_day << RT << std::endl;
	return (0);
};

