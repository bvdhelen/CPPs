/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:11:28 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/02/03 12:10:19 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Constructor por defecto
WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat constructor called" << std::endl;
}

// Destructor
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

//Constructor de copia
WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

// Operador de asignación
WrongCat	&WrongCat::operator=(const WrongCat &copy)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &copy)
		WrongAnimal::operator=(copy);
	return (*this);
}

// Funciones miembro
void	WrongCat::makeSound() const
{
	std::cout << "Miau? (but wrong)" << std::endl;
}
