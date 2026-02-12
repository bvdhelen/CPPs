/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:11:12 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/02/08 21:07:53 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*brain;
	public:
		// Constructor (por defecto)
		Cat();
		// Destructor
		virtual ~Cat();
		// Constructor de copia
		Cat(const Cat &copy);
		// Operador de asignación
		Cat &operator=(const Cat &copy);

		// Funciones miembro
		void	makeSound() const;
};

#endif