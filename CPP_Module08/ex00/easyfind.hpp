/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 18:51:00 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/07/31 19:01:00 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> //std::find(inicio, final, valor);
#include <exception> //throw

class ValueNotFoundException : public std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return ("Value not found in container");
        }
};

template <typename T>
void easyfind(T &container, int value)
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw ValueNotFoundException();
}

#endif