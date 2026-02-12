/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 12:59:38 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/01/24 12:59:38 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructor
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;

	std::cout << "ScavTrap " << this->name << " has been created" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

// Constructor por defecto
ScavTrap::ScavTrap() : ClapTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;

	std::cout << "ScavTrap default constructor called" << std::endl;
}

// Constructor de copia
ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	*this = copy;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

// Operador de asignación
ScavTrap	&ScavTrap::operator=(const ScavTrap &copy)
{
	if (this != &copy)
		ClapTrap::operator=(copy);
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	return (*this);
}

// Funciones miembro
void	ScavTrap::attack(const std::string &target)
{
	if (this->hitPoints <= 0 || this->energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->name << " can't attack" << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout	<< "ScavTrap " << this->name
				<< " fiercely attacks " << target
				<< ", causing " << this->attackDamage
				<< " points of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout	<< "ScavTrap " << this->name
				<< " is now in Gate keeper mode" << std::endl;
}
