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
Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Constructor int
Fixed::Fixed(const int value)
{
	this->_value = value * 256;
	std::cout << "Int constructor called" << std::endl;
}

// Constructor float
Fixed::Fixed(const float value)
{
	this->_value = roundf(value * 256);
	std::cout << "Float constructor called" << std::endl;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Constructor de copia
Fixed::Fixed(const Fixed &copy) : _value(copy._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

// Operador de asignación
Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		_value = copy._value;
	return (*this);
}

// Funciones miembro
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)_value / 256;
}

int	Fixed::toInt(void) const
{
	return _value / 256;
}

// función externa que imprime el Fixed como float
std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return out;
}
