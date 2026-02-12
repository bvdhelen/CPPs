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

/*RESUMEN:

La clase Fixed representa números en punto fijo usando un entero escalado por 256.
Los operadores trabajan directamente con ese entero para evitar pérdidas de precisión.
Los incrementos modifican el valor mínimo representable (1/256).
Las funciones miembro actúan sobre un objeto concreto (toFloat, toInt...),
mientras que las funciones de clase (min y max) no dependen de ningún objeto.
*/

// Constructor por defecto con lista de inicialización
Fixed::Fixed() : _value(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

// Constructor int
Fixed::Fixed(const int value)
{
	this->_value = value * 256;
	//std::cout << "Int constructor called" << std::endl;
}

// Constructor float
	// Uso roundf porque redondeo para no perder precisión (el cast trunca)
Fixed::Fixed(const float value)
{
	this->_value = roundf(value * 256);
	//std::cout << "Float constructor called" << std::endl;
}

// Destructor
Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

// Constructor de copia
Fixed::Fixed(const Fixed &copy) : _value(copy._value)
{
	//std::cout << "Copy constructor called" << std::endl;
}

// Operador de asignación
Fixed &Fixed::operator=(const Fixed &copy)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		_value = copy._value;
	return (*this);
}

// Funciones miembro
int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)_value / 256);
}

int	Fixed::toInt(void) const
{
	return (_value / 256);
}

// Función externa que imprime el Fixed como float
std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return (out);
}

// Operadores de comparación (si x > y entonces x·256 > y·256)
bool	Fixed::operator>(const Fixed &other) const
{
	return (this->_value > other._value);
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->_value < other._value);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->_value >= other._value);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->_value <= other._value);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->_value == other._value);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->_value != other._value);
}

// Operadores aritméticos
	// Suma y resta directa porque están en la misma escala
Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	result;

	result._value = this->_value + other._value;
	return (result);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	result;

	result._value = this->_value - other._value;
	return (result);
}

	// Multiplicación (x·256 * y·256) / 256 = (x·y)/256
Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	result;
	long	temp;

	temp = (long)this->_value * (long)other._value;
	result.setRawBits(temp / 256);
	return (result);
}

	// División (x·256 / y·256) * 256 = (x/y)·256
Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	result;
	long	temp;

	temp = ((long)this->_value * 256);
	result.setRawBits(temp / other._value);
	return (result);
}

// Operadores de incremento/decremento: La unidad mínima es 1/256
	// PRE-incremento: Devuelve el valor incrementado
Fixed	&Fixed::operator++()
{
	_value += 1;
	return (*this);
}

Fixed	&Fixed::operator--()
{
	_value -= 1;
	return (*this);
}

	// POST-incremento: Devuelve copia del valor anterior
Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	_value += 1;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	_value -= 1;
	return (temp);
}

// Funciones de clase
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
