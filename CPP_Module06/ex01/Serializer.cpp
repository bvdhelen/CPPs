/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:29:41 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/07/27 16:45:52 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

//OCF
Serializer::Serializer()
{
}
Serializer::Serializer(Serializer const &other)
{
	*this = other;
}

Serializer &Serializer::operator=(Serializer const &other)
{
	(void)other;
	return *this;
}

Serializer::~Serializer()
{
}

//funciones miembro
uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}
