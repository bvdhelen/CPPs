/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:37:32 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/01/17 16:37:32 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructor
ClapTrap::ClapTrap(const std::string &name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;

	std::cout << "ClapTrap " << this->name << " has been created" << std::endl;
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " has been destroyed" << std::endl;
}

// Constructor por defecto
ClapTrap::ClapTrap()
{
	this->name = "Default";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;

	std::cout << "ClapTrap default constructor called" << std::endl;
}

// Constructor de copia
ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

// Operador de asignación
ClapTrap	&ClapTrap::operator=(const ClapTrap &copy)
{
	if (this != &copy)
	{
		this->name = copy.name;
		this->hitPoints = copy.hitPoints;
		this->energyPoints = copy.energyPoints;
		this->attackDamage = copy.attackDamage;
	}
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	return (*this);
}

// Funciones miembro
void	ClapTrap::attack(const std::string &target)
{
	if (this->hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead and can't attack" << std::endl;
		return ;
	}
	if (this->energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy left" << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout	<< "ClapTrap " << this->name
				<< " attacks " << target
				<< ", causing " << this->attackDamage
				<< " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->hitPoints -= amount;

	if (this->hitPoints < 0)
		this->hitPoints = 0;
	std::cout	<< "ClapTrap " << this->name
				<< " takes " << amount
				<< " points of damage! (HP: "
				<< this->hitPoints << ")" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead and can't be repaired" << std::endl;
		return ;
	}
	if (this->energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy left" << std::endl;
		return ;
	}
	this->energyPoints--;
	this->hitPoints += amount;

	std::cout	<< "ClapTrap " << this->name
				<< " repairs itself for "
				<< amount << " hit points! (HP: "
				<< this->hitPoints << ")" << std::endl;
}
