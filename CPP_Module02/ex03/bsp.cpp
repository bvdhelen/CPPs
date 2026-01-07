/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:29:32 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/01/07 16:29:32 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// MÉTODO DE LAS ÁREAS
	// Área(ABC) = Área(PAB) + Área(PBC) + Área(PCA)
	// Área = | (x1(y2−y3) + x2(y3−y1) + x3(y1−y2)) | / 2

Fixed	absFixed(Fixed valor)
{
	if (valor < Fixed(0))
		return (valor * Fixed(-1));
	return (valor);
}

// Función Area
static Fixed	area(Point const &a, Point const &b, Point const &c)
{
	Fixed	result =
		a.getX() * (b.getY() - c.getY()) +
		b.getX() * (c.getY() - a.getY()) +
		c.getX() * (a.getY() - b.getY());
	
	if (result < Fixed(0))
		result = result * Fixed(-1);
	return (result);
}

// Implementación de bsp
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	total = area(a, b, c);
	Fixed	a1 = area(point, a, b);
	Fixed	a2 = area(point, b, c);
	Fixed	a3 = area(point, c, a);

	if (a1 == Fixed(0) || a2 == Fixed(0) || a3 == Fixed(0))
		return (false);
	//if (a1 + a2 + a3 == total)
	//	return (true);
	//return (false);
	return (a1 + a2 + a3 == total);
}
