/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:54:45 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/01/04 17:54:45 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructor por defecto con lista de inicialización
Fixed::Fixed() : _rawValue(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

// Constructor int
Fixed::Fixed(const int value)
{
	_rawValue = value * 256;
	//std::cout << "Int constructor called" << std::endl;
}

// Constructor float
Fixed::Fixed(const float value)
{
	_rawValue = roundf(value * 256);
	//std::cout << "Float constructor called" << std::endl;
}

// Destructor
Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

// Constructor de copia
Fixed::Fixed(const Fixed &copy) : _rawValue(copy._rawValue)
{
	//std::cout << "Copy constructor called" << std::endl;
}

// Operador de asignación
Fixed &Fixed::operator=(const Fixed &copy)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		_rawValue = copy._rawValue;
	return (*this);
}

// Funciones miembro
int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawValue);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_rawValue = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)_rawValue / 256);
}

int	Fixed::toInt(void) const
{
	return (_rawValue / 256);
}

// función externa que imprime el Fixed como float
std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return (out);
}

// operadores de comparación (si x > y entonces x·256 > y·256)
bool	Fixed::operator>(const Fixed &other) const
{
	return (this->_rawValue > other._rawValue);
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->_rawValue < other._rawValue);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->_rawValue >= other._rawValue);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->_rawValue <= other._rawValue);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->_rawValue == other._rawValue);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->_rawValue != other._rawValue);
}

// operadores aritméticos ()
Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	result;

	result._rawValue = this->_rawValue + other._rawValue;
	return (result);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	result;

	result._rawValue = this->_rawValue - other._rawValue;
	return (result);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	result;
	long	temp;

	temp = (long)this->_rawValue * (long)other._rawValue;
	result.setRawBits(temp / 256);
	return (result);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	result;
	long	temp;

	temp = ((long)this->_rawValue * 256);
	result.setRawBits(temp / other._rawValue);
	return (result);
}

// operadores de incremento/decremento
Fixed	&Fixed::operator++()
{
	_rawValue += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	_rawValue += 1;
	return (temp);
}

Fixed	&Fixed::operator--()
{
	_rawValue -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	_rawValue -= 1;
	return (temp);
}

// funciones de clase
Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}