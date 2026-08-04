/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 20:43:52 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/08/04 13:47:10 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

// Orthodox Canonical Form
B::B()
{
}

B::B(const B &other) : Base(other)
{
	*this = other;
}

B &B::operator=(const B &other)
{
	(void)other;
	return (*this);
}

B::~B()
{
}
