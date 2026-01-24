/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 12:59:40 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/01/24 12:59:40 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		// Constructor
		ScavTrap(const std::string &name);
		// Destructor
		~ScavTrap();
		// Constructor por defecto
		ScavTrap();
		//Constructor de copia
		ScavTrap(const ScavTrap &other);
		//Operador de asignación
		ScavTrap &operator=(const ScavTrap &other);
		
		// Funciones miembro
		void	attack(const std::string &target);
		void	guardGate();
};

#endif