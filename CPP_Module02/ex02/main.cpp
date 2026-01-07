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

#include "Fixed.hpp"

int	main(void)
{
	Fixed	a;
	Fixed	const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a,b) << std::endl;

	return (0);
}

/*
int	main(void)
{
	Fixed	a(5.0f);
	Fixed	b(5.5f);
	Fixed	c(2);

	if (a < c)
		std::cout << "a es mayor" << std::endl;

	a == b;
	a != b;
	a < c;
	c >= b;

	Fixed d = a / c;
	std::cout << d << std::endl;
	
	Fixed e(1);

	std::cout << e << std::endl;
	std::cout << ++e << std::endl;
	std::cout << e++ << std::endl;
	std::cout << e << std::endl;

	return (0);
}
*/