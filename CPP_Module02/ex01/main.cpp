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
	Fixed	const b(10);
	Fixed	const c(42.42f);
	Fixed	const d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return (0);
}

/*
int	main(void)
{
	Fixed	a(10);
	Fixed	b(42.42f);
	Fixed	c(1234.4321f);

	std::cout << a.getRawBits() << std::endl;
	
	std::cout << b.getRawBits() << std::endl;
	std::cout << b.toFloat() << std::endl;
	std::cout << b.toInt() << std::endl;

	std::cout << c.getRawBits() << std::endl;
	std::cout << c.toFloat() << std::endl;
	std::cout << c.toInt() << std::endl;

	std::cout << a << b << c << std::endl;

	return (0);
}
*/