/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:03:40 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/12/29 15:03:40 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "\033[0;31mError\033[0m" << std::endl;
		std::cout << "Usage: ./harlFilter level" << std::endl;
		return (1);
	}
	Harl	harl;
	std::string	level = argv[1];
	harl.complain(level);
	return (0);
}
