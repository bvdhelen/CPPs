/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:08:51 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/01/07 15:08:51 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// constructor por defecto
Point::Point() : _x(0), _y(0)
{

}

// destructor
Point::~Point()
{

}

// constructor con coordenadas
Point::Point(const float x, const float y) : _x(x), _y(y)
{

}

// constructor de copia
Point::Point(const Point &other) : _x(other._x), _y(other._y)
{

}

// Operador de asignación (se declara pero no se usa)
Point	&Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}

// Funciones miembro
	// getters
Fixed	Point::getX() const
{
	return (_x);
}

Fixed	Point::getY() const
{
	return (_y);
}
