/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:22:37 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/12/26 12:22:37 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Función ...
// MEMORIA STACK
void	randomChump(std::string name)
{
	Zombie	stack_zombie(name);

	stack_zombie.announce();
}
