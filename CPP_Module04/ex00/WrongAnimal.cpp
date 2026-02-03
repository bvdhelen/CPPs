/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:11:23 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/02/03 12:03:26 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructor
WrongAnimal::WrongAnimal(const std::string &type) : type(type)
{
	std::cout << "WrongAnimal parameter constructor called" << std::endl;
}

// Constructor por defecto
WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

// Constructor de copia
WrongAnimal::WrongAnimal(const WrongAnimal &copy) : type(copy.type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

// Operador de asignación
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

// Funciones miembro
std::string		WrongAnimal::getType() const
{
	return (type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "* WrongAnimal makes a generic sound *" << std::endl;
}
