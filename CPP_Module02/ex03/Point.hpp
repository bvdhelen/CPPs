/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:08:55 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/01/07 15:08:55 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed	x;
		const Fixed	y;
	public:
		// constructor por defecto
		Point();
		// destructor
		~Point();
		// constructor de copia
		Point(const Point &copy);
		// Operador de asignación (se declara pero no se usa)
		Point &operator=(const Point &copy);
		
		// constructor con coordenadas
		Point(const float x, const float y);

		// getters
		Fixed	getX() const;
		Fixed	getY() const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif