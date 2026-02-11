/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:09:26 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/02/11 18:09:26 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

// Constructor
Cure::Cure() : AMateria("cure")
{

}

// Destructor
Cure::~Cure()
{

}

// Copy Constructor
Cure::Cure(const Cure &copy) : AMateria(copy)
{

}

// Operador de asignación
Cure	&Cure::operator=(const Cure &copy)
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
	std::cout	<< "* heals "
				<< target.getName()
				<< "'s wounds *" << std::endl;
}
