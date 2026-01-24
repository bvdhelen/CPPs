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

#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << "===== DIAMONDTRAP TEST =====" << std::endl;

	DiamondTrap	a("Diamond");
	a.attack("enemy");
	a.whoAmI();

	std::cout << "\n===== COPY TEST =====" << std::endl;
	DiamondTrap	b(a);

	std::cout << "\n===== ASSIGN TEST =====" << std::endl;
	DiamondTrap	c;
	c = b;

	std::cout << "\n===== END =====" << std::endl;
	return (0);
}
