/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 20:40:30 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/07/27 20:54:52 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
    std::srand(std::time(NULL));

    Base *ptr = generate();

    std::cout << "identify (Base*): ";
    identify(ptr);

    std::cout << "identify (Base&): ";
    identify(*ptr);

    delete ptr;
    return (0);
}
