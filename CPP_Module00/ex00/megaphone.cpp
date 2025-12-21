/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:06:14 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/12/19 22:42:52 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> //Para imprimir
#include <string> //Para manejar strings más fácil

int main(int argc, char **argv)
{
    int     i;
    size_t  j;

    i = 1;
    j = 0;
    std::string str;
    if (argc == 1)
    {
        std::cout << "\033[1;31m* LOUD AND UNBEREABLE FEEDBACK NOISE * \033[0m" << std::endl;
        return (0);
    }
    while (i < argc)
    {
        str = argv[i];
        while (j < str.length())
        {
            std::cout << (char)std::toupper(str[j]);
            j++;
        }
        j = 0;
        i++;
    }
    std::cout << std::endl;
    return (0);
}
