/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 13:40:49 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/08/04 12:40:32 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string> //std::string
#include <iostream> //endl
#include <cctype> //isdigit, isprint
#include <climits> //char, int limits
#include <cfloat> // DBL_* y FLT_*
#include <cstdlib> //strtod()
#include <iomanip> //std::fixed & std::setprecision(1)
#include <cmath> //isnan(), isinf()

enum LiteralType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO_FLOAT,
	PSEUDO_DOUBLE,
	INVALID
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
	public:
		static void convert(const std::string &literal);
};

#endif