/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:22:31 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/12/26 12:22:31 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*heapZombie;

	// Zombie en Memoria Heap
	heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete (heapZombie);
	
	// Zombie en Memoria Stack
	Zombie	stackZombie("StackZombie1");
	stackZombie.announce();

	// Zombie en Memoria Stack (llamada a función)
	randomChump("StackZombie2");
	
	return (0);
}
