/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 13:40:16 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/08/04 19:50:36 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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
----------- TESTS -----------
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
./convert 0.0000001f
./convert nan
./convert nanf
./convert +inf
./convert +inff
./convert -inf
./convert -inff
./convert hello
./convert +.0
./convert ++42
./convert 4..2
./convert +
./convert -
./convert .
./convert f
./convert 2147483647
./convert 2147483648
./convert -2147483648
./convert -2147483649
./convert " "
*/