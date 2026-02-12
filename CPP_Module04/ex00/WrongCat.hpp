/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:11:30 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/02/03 12:07:13 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		// Constructor (por defecto)
		WrongCat();
		// Destructor
		~WrongCat();
		// Constructor de copia
		WrongCat(const WrongCat &copy);
		// Operador de asignación
		WrongCat &operator=(const WrongCat &copy);

		// Funciones miembro
		void	makeSound() const;
};

#endif