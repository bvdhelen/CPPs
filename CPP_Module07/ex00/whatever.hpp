/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:39:05 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/08/04 14:16:18 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream> //std::cout, std::endl
#include <string> //std::string

template <typename T>
void    swap(T &a, T &b)
{
    T temp;

    temp = b;
    b = a;
    a = temp;
}

template <typename T>
T   min(const T &a, const T &b)
{
    if (a < b)
        return a;
    return b;
}

template <typename T>
T   max(const T &a, const T &b)
{
    if (a > b)
        return a;
    return b;
}

#endif