/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:54:47 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/01/04 17:54:47 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> // roundf() -> redondea al entero más cercano

class Fixed
{
	private:
		int	_rawValue;
		static const int	_fractionalBits = 8;
	public:
		// constructor por defecto
		Fixed();
		// constructor int
		Fixed(const int value);
		// constructor float
		Fixed(const float value);
		// destructor
		~Fixed();
		// constructor de copia
		Fixed(const Fixed &copy);
		// operador de asignación
		Fixed	&operator=(const Fixed &copy);

		// funciones miembro
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		
		float	toFloat(void) const;
		int		toInt(void) const;

		// 6 operadores de comparación
		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;

		// 4 operadores aritméticos
		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;

		// 4 operadores de incremento/decremento
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);

		// FUNCIONES DE CLASE
		static Fixed	&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);

		static Fixed	&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
};

// Cuando alguien haga "ostream << Fixed", quiero que sepas cómo imprimirlo
std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif