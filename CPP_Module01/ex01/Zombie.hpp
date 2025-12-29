/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 17:05:10 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/12/26 17:05:10 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string> // std::string
#include <iostream> // std::cout

class Zombie
{
	private:
		std::string _name; // Atributo privado
	public:
		Zombie(); // Constructor por defecto
		~Zombie(); // Destructor

		void	setName(std::string name); // Inicializar zombie
		void	announce(void); // Función miembro de la clase
};

Zombie	*zombieHorde(int N, std::string name);

#endif