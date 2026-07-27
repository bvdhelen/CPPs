/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:29:44 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/07/27 16:40:38 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h> //Es un entero capaz de almacenar una dirección de memoria.

class Data;

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer&);
        Serializer& operator=(const Serializer&);
        ~Serializer();
    public:
        static uintptr_t    serialize(Data *ptr);
        static Data         *deserialize(uintptr_t raw);
};

#endif