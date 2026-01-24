/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:37:30 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/01/17 16:37:30 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	protected:
		std::string	name;
		int	hitPoints;
		int	energyPoints;
		int	attackDamage;

	public:
		// Constructor
		ClapTrap(const std::string &name);
		// Destructor
		~ClapTrap();
		// Constructor por defecto
		ClapTrap();
		//Constructor de copia
		ClapTrap(const ClapTrap &other);
		//Operador de asignación
		ClapTrap &operator=(const ClapTrap &other);

		// Funciones miembro
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif