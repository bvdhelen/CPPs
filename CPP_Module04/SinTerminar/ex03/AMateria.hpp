/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:42:26 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/02/11 17:42:26 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class	ICharacter;

class AMateria
{
	protected:
		std::string	type;
	public:
		// Constructor
		AMateria(const std::string &type);
		// Constructor por defecto
		AMateria();
		// Destructor
		virtual ~AMateria();
		// Constructor de copia
		AMateria(const AMateria &copy);
		// Operador de asignación
		AMateria &operator=(const AMateria &copy);
		
		// Funciones miembro
		std::string const	&getType() const;
		
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);
};

#endif