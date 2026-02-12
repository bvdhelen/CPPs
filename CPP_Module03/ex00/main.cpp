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

#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << "===== CONSTRUCTOR TEST =====" << std::endl;
	ClapTrap	a("Alpha");
	ClapTrap	b("Bravo");
	ClapTrap	c;

	std::cout << "\n===== COPY CONSTRUCTOR TEST =====" << std::endl;
	ClapTrap	d(a);

	std::cout << "\n===== ASSIGNMENT OPERATOR TEST =====" << std::endl;
	c = b;

	std::cout << "\n===== BASIC ACTIONS TEST =====" << std::endl;
	a.attack("Target1");
	a.beRepaired(5);
	a.takeDamage(3);

	//a.attack("B");
	//b.takeDamage(5);
	//b.attack("A");
	//a.takeDamage(0);
	//a.beRepaired(5);
	
	std::cout << "\n===== ENERGY DRAIN TEST =====" << std::endl;
	for (int i = 0; i < 11; i++)
		b.attack("Target2");
	
	std::cout << "\n===== DEAD CLAPTRAP TEST =====" << std::endl;
	d.takeDamage(20);
	d.attack("Nobody");
	d.beRepaired(5);

	std::cout << "\n===== END =====" << std::endl;
	return (0);
}
