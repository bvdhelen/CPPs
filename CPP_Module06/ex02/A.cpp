/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 20:41:29 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/07/27 20:53:13 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"

A::A()
{
}

A::A(const A &other) : Base(other)
{
	*this = other;
}

A &A::operator=(const A &other)
{
	(void)other;
	return (*this);
}

A::~A()
{
}
