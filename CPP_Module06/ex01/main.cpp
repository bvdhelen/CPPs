/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:29:36 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/07/27 16:48:35 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//reinterpret_cast<tipo_destino>(expresión)
#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
    Data data;
    
    data._name = "Elena";
    data._age = 26;
    
    Data *ptr = &data;
    uintptr_t raw = Serializer::serialize(ptr);
    Data *newPtr = Serializer::deserialize(raw);

    std::cout << "Original pointer     : " << ptr << std::endl;
    std::cout << "Serialized uintptr_t : " << raw << std::endl;
    std::cout << "Deserialized pointer : " << newPtr << std::endl;

    std::cout << std::endl;

    std::cout << "Name: " << newPtr->_name << std::endl;
    std::cout << "Age : " << newPtr->_age << std::endl;

    if (ptr == newPtr)
        std::cout << "\nPointers are identical!" << std::endl;
    else
        std::cout << "\nPointers are different!" << std::endl;

    return (0);
}
