/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:22:34 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/12/26 12:22:34 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Función ...
// MEMORIA HEAP
Zombie	*newZombie(std::string name)
{
	Zombie	*heap_zombie;

	heap_zombie = new Zombie(name);
	return (heap_zombie);
}
