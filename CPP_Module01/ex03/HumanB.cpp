/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 19:09:23 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/12/26 19:09:23 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// Constructor
HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
	//this->_name = name;
	//this->_weapon = NULL;
	//std::cout << _name << " is alive" << std::endl;
}

// Destructor
HumanB::~HumanB()
{
	//std::cout << _name << " is dead" << std::endl;
}

// Función miembro setter
void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

// Puntero -> acceso directo con "->"
void	HumanB::attack(void) const
{
	if (_weapon)
	{
		std::cout	<< _name
					<< " attacks with their "
					<< _weapon->getType()
					<< std::endl;
	}
	else
	{
		std::cout	<< _name
					<< " has no weapon and can't attack"
					<< std::endl;
	}
}
