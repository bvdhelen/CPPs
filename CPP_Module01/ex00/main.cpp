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

	// Heap Zombie
	heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete (heapZombie);
	// Stack Zombie
	randomChump("StackZombie");
	return (0);
}
