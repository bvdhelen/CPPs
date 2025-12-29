/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 19:09:31 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/12/26 19:09:31 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// LISTA DE INICIALIZACIÓN
// Inicializa los atributos ANTES de que el cuerpo del constructor se ejecute
	// : atributo(parámetro)

// Constructor
Weapon::Weapon(std::string type) : _type(type)
{
	//this->_type = type;
	//std::cout << _type << " built" << std::endl;
}

// Destructor
Weapon::~Weapon(void)
{
	//std::cout << _type << " destroyed" << std::endl;
}

// Función miembro getter
const std::string	&Weapon::getType(void) const
{
	return (this->_type);
}

// Función miembro setter
void	Weapon::setType(std::string type)
{
	this->_type = type;
}
