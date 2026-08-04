/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:29:41 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/08/04 13:37:04 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

// Orthodox Canonical Form
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

// Member Functions
//reinterpret_cast<destination_type>(expression)
uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}
