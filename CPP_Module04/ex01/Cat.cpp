/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:11:09 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/02/08 21:03:20 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructor por defecto
Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
	brain = new Brain();
}

// Destructor
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

//Constructor de copia
Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	brain = new Brain(*copy.brain);
}

// Operador de asignación
Cat	&Cat::operator=(const Cat &copy)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		Animal::operator=(copy);
		delete brain;
		brain = new Brain(*copy.brain);
	}
	return (*this);
}

// Funciones miembro
void	Cat::makeSound() const
{
	std::cout << "Miau! Miau!" << std::endl;
}
