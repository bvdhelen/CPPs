/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:34:07 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/07/28 12:55:27 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> //std::cout, std::endl
#include <string> //std::string
#include "whatever.hpp"

int main(void)
{
    int a = 2;
    int b = 3;

    ::swap(a,b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a,b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a,b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c,d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c,d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c,d) << std::endl;
    
    return 0;
}

/*
MÁS PRUEBAS
    char x = 'A';
    char y = 'Z';

    std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
    std::cout << "max(x, y) = " << ::max(x, y) << std::endl;

    float f1 = 2.5f;
    float f2 = 1.7f;

    std::cout << "min(f1, f2) = " << ::min(f1, f2) << std::endl;
    std::cout << "max(f1, f2) = " << ::max(f1, f2) << std::endl;

*/

/*
OUTPUT

a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2

*/