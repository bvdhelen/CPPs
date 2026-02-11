/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:11:04 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/02/11 17:10:18 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructor
Animal::Animal(const std::string &type) : type(type)
{
	std::cout << "Animal parameter constructor called" << std::endl;
}

// Constructor por defecto
Animal::Animal() : type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

// Destructor
Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

// Constructor de copia
Animal::Animal(const Animal &copy) : type(copy.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

// Operador de asignación
Animal &Animal::operator=(const Animal &copy)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

// Funciones miembro
std::string		Animal::getType() const
{
	return (type);
}
