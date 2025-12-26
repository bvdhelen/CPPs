/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:06:14 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/12/26 11:54:58 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> //Para imprimir
#include <string> //Para manejar strings más fácil

int main(int argc, char **argv)
{
    int     i;
    int		j;
    
    if (argc == 1)
    {
		// cout: console out (escribir por terminal)
		std::string noise = "* LOUD AND UNBEAREABLE FEEDBACK NOISE *";
		std::cout << noise << std::endl;
        return (0);
    }
	i = 1;
    while (argv[i])
    {
		j = 0;
        while (argv[i][j])
        {
            std::cout << (char)std::toupper(argv[i][j]);
            j++;
        }
        i++;
    }
    std::cout << std::endl;
    return (0);
}
