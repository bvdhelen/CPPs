/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:11:09 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/02/20 13:03:14 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
	brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	brain = new Brain(*copy.brain);
}

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

void	Cat::makeSound() const
{
	std::cout << "Miau! Miau!" << std::endl;
}
