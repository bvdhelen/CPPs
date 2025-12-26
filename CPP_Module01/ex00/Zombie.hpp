/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:22:42 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/12/26 12:22:42 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string> // std::string
#include <iostream> // std::cout

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie(std::string name);
		~Zombie();
		void	announce();
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif