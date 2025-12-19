/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:06:14 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/12/09 17:14:40 by eldiaz-c         ###   ########.fr       */
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
/*
int main (int argc, char *argv[])
{
	int	x;
	int z;

	x = 0;
	z = 1;
	std::string	result;
	if (argc == 1)
	{
		std::cout << "\033[1;31m * LOUD AND UNBEARABLE FEEDBACK NOISE * \033[0m" << std::endl;
		return (0);
	}
	else
	{
		while(argv[z])
		{
			result = argv[z];
			while(result[x])
			{
				std::cout << "\033[1;31m" << char(toupper(result[x])) << "\033[0m";
				x++;
			}
			x = 0;
			z++;
		}
		std::cout << std::endl;
	}
	return (0);
}
*/