/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 18:55:43 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/10/14 03:01:42 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
    : _database(other._database)
{    
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _database = other._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{   
}

bool BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: could not open database file." << std::endl;
		return false;
	}

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::string::size_type comma = line.find(',');

        if (comma == std::string::npos)
            continue ;
        std::string date = line.substr(0, comma);
        std::string rateString = line.substr(comma + 1);
        
        float rate = static_cast<float>(std::atof(rateString.c_str()));
        
        _database[date] = rate;
    }
	// DEBUGGER (prints each date & price)
    // std::map<std::string, float>::iterator it;

    // for (it = _database.begin(); it != _database.end(); ++it)
    // {
    //     std::cout << it->first << " -> " << it->second << std::endl;
    // }
    
    file.close();
	return true;
}

int BitcoinExchange::daysInMonth(int year, int month)
{
	if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0)
			|| year % 400 == 0)
			return 29;
		return 28;
	}

	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;

	return 31;
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	int i;
	int year;
	int month;
	int day;

	if (date.size() != 10)
		return false;

	if (date[4] != '-' || date[7] != '-')
		return false;

	for (i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}

	year = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(5, 2).c_str());
	day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;

	if (day < 1 || day > daysInMonth(year, month))
		return false;

	return true;
}

bool BitcoinExchange::isValidValue(const std::string &value)
{
	int i;
	bool decimal;
	bool hasDigit;

	if (value.empty())
		return false;

	i = 0;
	decimal = false;
	hasDigit = false;

	if (value[i] == '+' || value[i] == '-')
		i++;

	if (i == static_cast<int>(value.size()))
		return false;

	for (; i < static_cast<int>(value.size()); i++)
	{
		if (value[i] == '.')
		{
			if (decimal)
				return false;
			decimal = true;
		}
		else if (std::isdigit(value[i]))
			return true;
		else
			return false;
	}
	
	return hasDigit;
}

std::string BitcoinExchange::trim(const std::string &str)
{
	std::string::size_type start;
	std::string::size_type end;

	start = str.find_first_not_of(" \t");
	if (start == std::string::npos)
		return "";

	end = str.find_last_not_of(" \t");

	return str.substr(start, end - start + 1);
}

void BitcoinExchange::processInput(const std::string &filename)
{
	std::ifstream file(filename.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	if (_database.empty())
    	return;
	
	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::string::size_type separator = line.find('|');

		if (separator == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, separator));
		std::string valueString = trim(line.substr(separator + 1));

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (!isValidValue(valueString))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		double value = std::atof(valueString.c_str());

		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}

		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		std::map<std::string, float>::iterator it;

		it = _database.lower_bound(date);

		if (it == _database.end())
			--it;
		else if (it->first != date)
		{
			if (it == _database.begin())
			{
				std::cerr << "Error: no exchange rate available for date."
						  << std::endl;
				continue;
			}
			--it;
		}

		double result = value * it->second;

		std::cout << date << " => " << value
				  << " = " << result << std::endl;
	}

	file.close();
}
