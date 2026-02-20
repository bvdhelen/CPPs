/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:58:22 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/02/11 17:58:22 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

// Constructor
Ice::Ice() : AMateria("ice")
{

}

// Destructor
Ice::~Ice()
{

}

// Copy Constructor
Ice::Ice(const Ice &copy) : AMateria(copy)
{

}

// Operador de asignación
Ice	&Ice::operator=(const Ice &copy)
{
	AMateria::operator=(copy);
	return (*this);
}

// Funciones miembro
AMateria	*Ice::clone() const
{
	return new Ice(*this);
}

// Use
void	Ice::use(ICharacter &target)
{
	std::cout	<< "* shoots an ice bolt at "
				<< target.getName()
				<< " *" << std::endl;
}
