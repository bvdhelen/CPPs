/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 18:55:55 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/10/14 02:54:43 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream> //cerr, cout
#include <cctype> //isdigit

class BitcoinExchange
{
    private:
        std::map<std::string, float> _database; //KEY = fecha, VALUE = exchange rate
        
        std::string trim(const std::string &str);
        int daysInMonth(int year, int month);
        bool isValidDate(const std::string &date);
        bool isValidValue(const std::string &value);

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        bool loadDatabase(const std::string &filename);
        void processInput(const std::string &filename);
};

#endif
