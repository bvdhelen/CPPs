/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:11:07 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/02/03 11:29:11 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string	type;
	public:
		// Constructor
		Animal(const std::string &type);
		// Constructor por defecto
		Animal();
		// Destructor
		virtual ~Animal();
		// Constructor de copia
		Animal(const Animal &copy);
		// Operador de asignación
		Animal &operator=(const Animal &copy);
		
		// Funciones miembro
		std::string		getType() const;
		virtual void	makeSound() const;
};

#endif