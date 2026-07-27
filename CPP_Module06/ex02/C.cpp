/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 20:44:17 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/07/27 20:53:36 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

C::C()
{
}

C::C(const C &other) : Base(other)
{
	*this = other;
}

C &C::operator=(const C &other)
{
	(void)other;
	return (*this);
}

C::~C()
{
}
