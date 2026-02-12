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

/*RESUMEN:

En este ejercicio represento puntos con coordenadas constantes usando Fixed.
No uso floats en ningún momento, solo operaciones con Fixed.
Para comprobar si un punto está dentro del triángulo,
uso el método de las áreas:
	Si el área total es igual a la suma de las subáreas,
		el punto está dentro.
	Si alguna subárea es cero, 
		el punto está en un borde o vértice y devuelvo false.
*/

// MÉTODO DE LAS ÁREAS
	// Si esta fórmula se cumple, es que el punto está dentro:
		//Área(ABC) = Área(PAB) + Área(PBC) + Área(PCA)
	// Si alguna subárea es 0, es que está en un borde -> false

// Función Area -> Comparar áreas relativas
	// Área_doble = | (x1(y2−y3) + x2(y3−y1) + x3(y1−y2)) |
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
	// Cálculo del área total
	Fixed	total = area(a, b, c);
	// Cálculo de las subáreas
	Fixed	a1 = area(point, a, b);
	Fixed	a2 = area(point, b, c);
	Fixed	a3 = area(point, c, a);

	// Detectar borde o vértice
	if (a1 == Fixed(0) || a2 == Fixed(0) || a3 == Fixed(0))
		return (false);
	// Comprobación final
	return (a1 + a2 + a3 == total);
}
