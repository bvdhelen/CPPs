/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 18:18:58 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/12/26 18:18:58 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string> // std::string
#include <iostream> // std::cout

int	main(void)
{
	// Variable normal
	std::string		str = "HI THIS IS BRAIN";
	// Puntero
	std::string		*stringPTR = &str;
	// Referencia
	std::string		&stringREF = str;

	// Imprimir direcciones
	std::cout << "Variable	" << &str << std::endl;
	std::cout << "Puntero		" << stringPTR << std::endl;
	std::cout << "Referencia	" << &stringREF << std::endl;

	// Imprimir valores
	std::cout << "Variable	" << str << std::endl;
	std::cout << "Puntero		" << *stringPTR << std::endl;
	std::cout << "Referencia	" << stringREF << std::endl;

	return (0);
}

// Un puntero es una variable que almacena una dirección de memoria
	// Puede ser nulo o cambiar de dirección
// Una referencia es un alias de una variable existente
	// No puede ser nula y no puede cambiar de objeto una vez inicializada