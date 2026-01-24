/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:37:27 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/01/17 16:37:27 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "===== SCAVTRAP TEST =====" << std::endl;

	ScavTrap	a("Guardian");
	a.attack("Intruder");
	a.guardGate();

	std::cout << "\n===== COPY TEST =====" << std::endl;
	ScavTrap	b(a);

	std::cout << "\n===== ASSIGN TEST =====" << std::endl;
	ScavTrap	c;
	c = b;

	std::cout << "\n===== END OF MAIN =====" << std::endl;
	return (0);
}
