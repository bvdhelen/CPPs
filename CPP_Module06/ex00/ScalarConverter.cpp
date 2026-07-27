/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 13:41:12 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/07/27 12:39:40 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream> //endl
#include <cctype> //isdigit, isprint
#include <climits> //limites de un char e int
#include <cfloat> // DBL_* y FLT_*
#include <cstdlib> //strtod()
#include <iomanip> //std::fixed y std::setprecision(1)

//OCF
ScalarConverter::ScalarConverter()
{
}
ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

//funciones miembro
static bool isChar(const std::string &str)
{
	return (str.size() == 1 && !std::isdigit(str[0]));
}

static bool isInt(const std::string &str)
{
	if (str.empty())
		return false;
	std::size_t	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str.size() == 1)
			return false;
		i++;
	}
	while (i < str.size())
	{
		if (!std::isdigit(str[i]))
			return false;
		i++;
	}
	return true;
}

static bool isDecimal(const std::string &str, bool hasSuffixF)
{
    bool dotFound = false;
    bool digitBeforeDot = false;
    bool digitAfterDot = false;
    if (str.empty())
        return false;

    std::size_t i = 0;
    
    if (str[i] == '+' || str[i] == '-')
    {   
        if (str.size() == 1)
            return false;
        i++;
    }
	std::size_t end = str.size();
	if (!hasSuffixF && str.find('f') != std::string::npos)
    return false;
	if (hasSuffixF)
    {
        if (str[str.size() - 1] != 'f')
            return false;
        end--;
    }

    while (i < end)
    {
        if (std::isdigit(str[i]))
        {
            if (!dotFound)
                digitBeforeDot = true;
            else
                digitAfterDot = true;
        }
        else if (str[i] == '.')
        {
            if (dotFound)
                return false;

            if (!digitBeforeDot)
                return false;
            dotFound = true;
        }
        else
            return false;
        i++;
    }
    if (!dotFound)
        return false;
    if (!digitBeforeDot)
        return false;
    if (!digitAfterDot)
        return false;
    return true;
}

static bool isFloat(const std::string &str)
{
    return isDecimal(str, true);
}

static bool isDouble(const std::string &str)
{
    return isDecimal(str, false);
}


/* TENGO QUE ENTENDER LA QUE ESTA AHI
static bool isFloat(const std::string &str)
{
	bool dotFound = false;
	bool digitBeforeDot = false;
	bool digitAfterDot = false;

    if (str.empty())
        return false;

    std::size_t i = 0;

    if (str[i] == '+' || str[i] == '-')
    {
        if (str.size() == 1)
            return false;
        i++;
    }
    while (i < str.size())
{
    if (std::isdigit(str[i]))
    {
        if (!dotFound)
            digitBeforeDot = true;
        else
            digitAfterDot = true;
    }
    else if (str[i] == '.')
    {
        if (dotFound)
            return false;
        if (!digitBeforeDot)
            return false;
        dotFound = true;
    }
    else if (str[i] == 'f')
    {
        if (i != str.size() - 1)
            return false;
    }
    else
        return false;

    i++;
}
	if (!dotFound)
		return false;
	if (!digitBeforeDot)
		return false;
	if (!digitAfterDot)
		return false;
	return true;
}

static bool isDouble(const std::string &str)
{
	bool dotFound = false;
	bool digitBeforeDot = false;
	bool digitAfterDot = false;

    if (str.empty())
        return false;

    std::size_t i = 0;

    if (str[i] == '+' || str[i] == '-')
    {
        if (str.size() == 1)
            return false;
        i++;
    }
    while (i < str.size())
{
    if (std::isdigit(str[i]))
    {
        if (!dotFound)
            digitBeforeDot = true;
        else
            digitAfterDot = true;
    }
    else if (str[i] == '.')
    {
        if (dotFound)
            return false;
        if (!digitBeforeDot)
            return false;
        dotFound = true;
    }
    else if (str[i] == 'f')
	    return false;
    else
        return false;

    i++;
}
	if (!dotFound)
		return false;
	if (!digitBeforeDot)
		return false;
	if (!digitAfterDot)
		return false;
	return true;
}
*/

static LiteralType detectType(const std::string &str)
{
    if (isChar(str))
        return CHAR;
    //if (isPseudoLiteral(str))
        //return PSEUDO;
    if (isInt(str))
        return INT;
    if (isFloat(str))
        return FLOAT;
    if (isDouble(str))
        return DOUBLE;
    return INVALID;
}

static void printConversions(double value)
{
    char c = static_cast<char>(value);
    int i = static_cast<int>(value);
    float f = static_cast<float>(value);
    double d = value;

    bool hasFraction = (value != static_cast<int>(value));

    std::cout << "char: ";
    if (hasFraction)
        std::cout << "impossible" << std::endl;
    else if (value < CHAR_MIN || value > CHAR_MAX)
        std::cout << "impossible" << std::endl;
    else if (!isprint(c))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << c << "'" << std::endl;

    std::cout << "int: ";
    if (hasFraction)
        std::cout << "impossible" << std::endl;
    else if (value < INT_MIN || value > INT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << i << std::endl;

    std::cout << "float: ";
    if (value > FLT_MAX || value < -FLT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;

}

void ScalarConverter::convert(const std::string &literal)
{
    LiteralType type = detectType(literal);
    double value;

    switch (type)
    {
        case CHAR:
            value = static_cast<double>(literal[0]);
            break;

        case INT:
        case FLOAT:
        case DOUBLE:
            value = std::strtod(literal.c_str(), NULL);
            break;
        
        default:
            std::cout << "Invalid literal" << std::endl;
            return;
    }

    printConversions(value);
}
