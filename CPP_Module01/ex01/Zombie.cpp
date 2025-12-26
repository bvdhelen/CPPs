/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 17:05:07 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/12/26 17:05:07 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor por defecto
Zombie::Zombie()
{

}

// Destructor
Zombie::~Zombie()
{
	std::cout << _name << " destroyed" << std::endl;
}

// Función para inicializar zombie
void	Zombie::setName(std::string name)
{
	this->_name = name;
}

// Función miembro (announce)
void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
