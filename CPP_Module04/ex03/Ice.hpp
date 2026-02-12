/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:58:17 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/02/11 17:58:17 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		// Constructor
		Ice();
		// Destructor
		virtual ~Ice();
		// Constructor de copia
		Ice(const Ice &copy);
		// Operador de asignación
		Ice &operator=(const Ice &copy);
		
		// Funciones miembro
		AMateria	*clone() const;
		void		use(ICharacter &target);
};

#endif