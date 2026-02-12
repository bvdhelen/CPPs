/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:06:04 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/01/24 16:06:04 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructor
FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;

	std::cout << "FragTrap " << this->name << " has been created" << std::endl;
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

// Constructor por defecto
FragTrap::FragTrap() : ClapTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;

	std::cout << "FragTrap default constructor called" << std::endl;
}

// Constructor de copia
FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	*this = copy;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

// Operador de asignación
FragTrap	&FragTrap::operator=(const FragTrap &copy)
{
	if (this != &copy)
		ClapTrap::operator=(copy);
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	return (*this);
}

// Funciones miembro
void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " requests a positive high five!" << std::endl;
}
