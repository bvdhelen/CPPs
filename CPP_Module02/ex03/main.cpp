/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:54:50 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/01/04 17:54:50 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Point	a(0, 0);
	Point	b(5, 0);
	Point	c(0, 5);

	// Punto dentro
	Point	p1(1, 1);
	std::cout << "p1 inside: " << bsp(a, b, c, p1) << std::endl;
	
	// Punto fuera
	Point	p2(5, 5);
	std::cout << "p2 inside: " << bsp(a, b, c, p2) << std::endl;
	
	// Punto en borde
	Point	p3(2.5f, 0);
	std::cout << "p3 inside (edge): " << bsp(a, b, c, p3) << std::endl;
	
	// Punto en vértice
	Point	p4(0, 0);
	std::cout << "p4 inside (vertex): " << bsp(a, b, c, p4) << std::endl;

	return (0);
}
