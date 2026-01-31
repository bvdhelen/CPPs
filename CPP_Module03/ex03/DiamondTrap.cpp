/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:55:55 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/01/24 16:55:55 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Constructor
DiamondTrap::DiamondTrap(const std::string &name)
	: ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap()
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
	//this->hitPoints = FragTrap::hitPoints;
	//this->energyPoints = ScavTrap::energyPoints;
	//this->attackDamage = FragTrap::attackDamage;
	//std::cout << this->hitPoints << std::endl;
	//std::cout << this->energyPoints << std::endl;
	//std::cout << this->attackDamage << std::endl;

	std::cout << "DiamondTrap " << this->name << " has been created" << std::endl;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

// Constructor por defecto
DiamondTrap::DiamondTrap()
	: ClapTrap("default_clap_name"), FragTrap(), ScavTrap()
{
	this->name = "default";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
	//this->hitPoints = FragTrap::hitPoints;
	//this->energyPoints = ScavTrap::energyPoints;
	//this->attackDamage = FragTrap::attackDamage;
	//std::cout << this->hitPoints << std::endl;
	//std::cout << this->energyPoints << std::endl;
	//std::cout << this->attackDamage << std::endl;

	std::cout << "DiamondTrap default constructor called" << std::endl;
}

// Constructor de copia
DiamondTrap::DiamondTrap(const DiamondTrap &copy)
	: ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
	*this = copy;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

// Operador de asignación
DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &copy)
{
	if (this != &copy)
	{
		ClapTrap::operator=(copy);
		this->name = copy.name;
	}
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	return (*this);
}

// Funciones miembro
void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << this->name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}
