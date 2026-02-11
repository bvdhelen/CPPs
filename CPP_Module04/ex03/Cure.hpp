/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:09:29 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/02/11 18:09:29 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		// Constructor
		Cure();
		// Destructor
		virtual ~Cure();
		// Constructor de copia
		Cure(const Cure &copy);
		// Operador de asignación
		Cure &operator=(const Cure &copy);
		
		// Funciones miembro
		AMateria	*clone() const;
		void		use(ICharacter &target);
};

#endif