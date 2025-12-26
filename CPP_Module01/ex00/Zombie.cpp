/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:22:40 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/12/26 12:22:40 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor
Zombie::Zombie(std::string name)
{
	this->_name = name;
}

// Destructor
Zombie::~Zombie()
{
	std::cout << _name << " destroyed" << std::endl;
}

// Función miembro (announce)
void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// NOTA:
// Uso this-> cuando ASIGNO variables
// y lo omito cuando LEO variables