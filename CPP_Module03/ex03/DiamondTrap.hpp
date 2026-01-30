/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:55:57 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/01/24 16:55:57 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	name;
	public:
		// Constructor
		DiamondTrap(const std::string &name);
		// Destructor
		~DiamondTrap();
		// Constructor por defecto
		DiamondTrap();
		// Constructor de copia
		DiamondTrap(const DiamondTrap &copy);
		// Operador de asignación
		DiamondTrap &operator=(const DiamondTrap &copy);
		
		// Funciones miembro
		void	attack(const std::string &target);
		void	whoAmI();
};

#endif