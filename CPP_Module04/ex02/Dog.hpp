/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:11:17 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/02/08 21:08:05 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*brain;
	public:
		// Constructor (por defecto)
		Dog();
		// Destructor
		virtual ~Dog();
		// Constructor de copia
		Dog(const Dog &copy);
		// Operador de asignación
		Dog &operator=(const Dog &copy);
		
		// Funciones miembro
		void	makeSound() const;		
};

#endif