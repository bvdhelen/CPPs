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
Point::Point() : x(0), y(0)
{

}

// destructor
Point::~Point()
{

}

// constructor con coordenadas
Point::Point(const float x, const float y) : x(x), y(y)
{

}

// constructor de copia
Point::Point(const Point &copy) : x(copy.x), y(copy.y)
{

}

// Operador de asignación (se declara pero no hace nada porque los atributos son constantes)
Point	&Point::operator=(const Point &copy)
{
	//if (this != &copy)
		//_value = copy._value;
	(void)copy;
	return (*this);
}

// Funciones miembro (getters)
Fixed	Point::getX() const
{
	return (x);
}

Fixed	Point::getY() const
{
	return (y);
}
