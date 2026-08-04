/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 20:40:30 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/08/04 13:53:33 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <ctime>

int main(void)
{
    std::srand(std::time(NULL));

    Base *ptr = generate();

    std::cout << std::endl;
    
    std::cout << "identify (Base*): ";
    identify(ptr);

    std::cout << "identify (Base&): ";
    identify(*ptr);

    delete ptr;
    return (0);
}
