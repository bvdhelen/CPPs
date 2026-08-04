/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 13:41:12 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/08/04 12:47:09 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Orthodox Canonical Form
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

// Useful Functions
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
    std::size_t i = 0;
    std::size_t end = str.size();
    bool dot = false;
    bool digit = false;

    if (str.empty())
        return false;    
    if (str[i] == '+' || str[i] == '-')
    {
        i++;
    }
	if (i == end)
        return false;
	if (hasSuffixF)
    {
        if (str[end - 1] != 'f')
            return false;
        end--;
    }
    while (i < end)
    {
        if (std::isdigit(str[i]))
            digit = true;
        else if (str[i] == '.')
        {
            if (dot)
                return false;
            dot = true;
        }
        else
            return false;
        i++;
    }
    return (dot && digit);
}

static bool isFloat(const std::string &str)
{
    return isDecimal(str, true);
}

static bool isDouble(const std::string &str)
{
    return isDecimal(str, false);
}

// Other Useful Functions
static LiteralType detectPseudoLiteral(const std::string &str)
{
    if (str == "nanf" || str == "+inff" || str == "-inff")
        return PSEUDO_FLOAT;
    if (str == "nan" || str == "+inf" || str == "-inf")
        return PSEUDO_DOUBLE;
    return INVALID;
}

static LiteralType detectType(const std::string &str)
{
    LiteralType pseudo = detectPseudoLiteral(str);

    if (pseudo != INVALID)
        return pseudo;
    if (isChar(str))
        return CHAR;
    if (isInt(str))
        return INT;
    if (isFloat(str))
        return FLOAT;
    if (isDouble(str))
        return DOUBLE;
    return INVALID;
}

static void printNan(void)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
}

static void printInf(double value)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (value > 0)
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

static void printChar(double value)
{
    char c = static_cast<char>(value);

    std::cout << "char: ";
    if (value != static_cast<int>(value) || value < CHAR_MIN || value > CHAR_MAX)
        std::cout << "impossible";
    else if (!isprint(c))
        std::cout << "Non displayable";
    else
        std::cout << "'" << c << "'";
    std::cout << std::endl;
}

static void printInt(double value)
{
    int i = static_cast<int>(value);
    
    std::cout << "int: ";
    if (value != static_cast<int>(value) || value < INT_MIN || value > INT_MAX)
        std::cout << "impossible";
    else
        std::cout << i;
    std::cout << std::endl;
}

static void printFloat(double value)
{
    float f = static_cast<float>(value);

    std::cout << "float: ";
    if (value > FLT_MAX || value < -FLT_MAX)
        std::cout << "impossible";
    else
        std::cout << std::fixed << std::setprecision(1) << f << "f";
    std::cout << std::endl;
}

static void printDouble(double value)
{
    std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

static void printConversions(double value)
{
    if (std::isnan(value))
    {
        printNan();
        return;
    }
    if (std::isinf(value))
    {
        printInf(value);
        return;
    }
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

// Member Function
void ScalarConverter::convert(const std::string &literal)
{
    double value;
    LiteralType type = detectType(literal);

    switch (type)
    {
        case CHAR:
            value = static_cast<double>(literal[0]);
            break;
        case INT:
        case FLOAT:
        case DOUBLE:
        case PSEUDO_FLOAT:
        case PSEUDO_DOUBLE:
            value = std::strtod(literal.c_str(), NULL);
            break;
        default:
            std::cout << "Invalid literal" << std::endl;
            return;
    }
    printConversions(value);
}
