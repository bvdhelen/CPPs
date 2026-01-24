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

#include "FragTrap.hpp"

int	main(void)
{
	std::cout << "===== FRAGTRAP TEST =====" << std::endl;

	FragTrap	a("Fraggy");
	a.attack("Target");
	a.highFivesGuys();

	std::cout << "\n===== COPY TEST =====" << std::endl;
	FragTrap	b(a);

	std::cout << "\n===== ASSIGN TEST =====" << std::endl;
	FragTrap	c;
	c = b;

	std::cout << "\n===== END =====" << std::endl;
	return (0);
}
