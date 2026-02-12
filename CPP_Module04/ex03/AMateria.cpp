/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:42:28 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/02/11 17:42:28 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

// Constructor
AMateria::AMateria(std::string const &type) : type(type)
{

}

// Constructor por defecto
AMateria::AMateria() : type("Default")
{

}

// Destructor
AMateria::~AMateria()
{

}

// Copy Constructor
AMateria::AMateria(const AMateria &copy) : type(copy.type)
{

}

// Operador de asignación
AMateria	&AMateria::operator=(const AMateria &copy)
{
	if (this != &copy)
		type = copy.type;
	return (*this);
}

// Funciones miembro
std::string const	&AMateria::getType() const
{
	return (type);
}

// Default use (puede estar vacío)
void	AMateria::use(ICharacter &target)
{
	(void)target;
}
