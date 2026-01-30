/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:06:02 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/01/24 16:06:02 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		// Constructor
		FragTrap(const std::string &name);
		// Destructor
		~FragTrap();
		// Constructor por defecto
		FragTrap();
		// Constructor de copia
		FragTrap(const FragTrap &copy);
		// Operador de asignación
		FragTrap &operator=(const FragTrap &copy);
		
		// Funciones miembro
		void	highFivesGuys(void);
};

#endif