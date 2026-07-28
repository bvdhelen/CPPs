/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:57:18 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/07/28 14:08:35 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream> //std::cout, std::endl
#include <cstddef> //std::size_t

template <typename T>
void iter(T *array, const std::size_t len, void (*f)(T &element))
{
    std::size_t i;

    i = 0;
    while (i < len)
    {
        f(array[i]);
        i++;
    }
}

template <typename T>
void iter(const T *array, const std::size_t len, void (*f)(const T &element))
{
    std::size_t i;

    i = 0;
    while (i < len)
    {
        f(array[i]);
        i++;
    }
}

#endif