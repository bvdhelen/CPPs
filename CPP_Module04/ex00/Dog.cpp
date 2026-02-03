/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:11:15 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/02/03 11:01:24 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructor por defecto
Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
}

// Destructor
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

// Constructor de copia
Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

// Operador de asignación
Dog	&Dog::operator=(const Dog &copy)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &copy)
		Animal::operator=(copy);
	return (*this);
}

// Funciones miembro
void	Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}
