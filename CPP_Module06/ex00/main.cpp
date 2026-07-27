/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 13:40:16 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/07/27 15:46:57 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert <literal>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}

/*
----------- PRUEBAS -----------

./convert 0 (cero ND)
./convert 42 (entero normal imprime *)
./convert 2147483647 (max int)
./convert 2147483648 (max int + 1 overflow en int)
./convert -2147483648 (min int)
./convert -2147483649 (min int - 1 overflow en int)
./convert " "
./convert 4.2f (float normal)
./convert .5f (float con punto delante)
./convert 5.f (float con punto detrás)
./convert 0.0000001f

./convert +.0
./convert ++1
./convert 1..0
./convert +
*/

/*MAS PRUEBAS

./convert a
./convert z
./convert 0
./convert 42
./convert -42
./convert +42
./convert 4.2
./convert 4.2f
./convert .5
./convert .5f
./convert 5.
./convert 5.f
./convert nan
./convert nanf
./convert +inf
./convert +inff
./convert -inf
./convert -inff
./convert hello
./convert ++42
./convert 4..2
./convert +
./convert -
./convert .
./convert f

*/