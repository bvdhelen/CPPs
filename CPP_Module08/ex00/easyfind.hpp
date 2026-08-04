/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 18:51:00 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/08/04 19:43:20 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> //std::find(begin, end, value);
#include <exception> //throw

class ValueNotFoundException : public std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return ("Value not found in container.");
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