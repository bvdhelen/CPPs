/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 19:09:16 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/12/26 19:09:16 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Una referencia debe inicializarse en el constructor
	// No puede cambiar
	// No puede ser NULL

// Constructor
HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	//std::cout << _name << " is alive" << std::endl;
}

// Destructor
HumanA::~HumanA()
{
	//std::cout << _name << " is dead" << std::endl;
}

// Referencia -> acceso directo con "."
void	HumanA::attack(void) const
{
	std::cout	<< _name
				<< " attacks with their "
				<< _weapon.getType()
				<< std::endl;
}
