/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:11:25 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/02/03 12:04:15 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		// Constructor
		WrongAnimal(const std::string &type);
		// Constructor por defecto
		WrongAnimal();
		// Destructor
		~WrongAnimal();
		// Constructor de copia
		WrongAnimal(const WrongAnimal &copy);
		// Operador de asignación
		WrongAnimal &operator=(const WrongAnimal &copy);
		
		// Funciones miembro
		std::string		getType() const;
		void			makeSound() const;
};

#endif