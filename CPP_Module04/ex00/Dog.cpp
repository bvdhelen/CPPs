/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:11:15 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/02/20 13:26:20 by bvdhelen         ###   ########.fr       */
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
	std::cout << "Guau! Guau!" << std::endl;
}
