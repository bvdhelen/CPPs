/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:15:55 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/08/04 16:02:54 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
    private:
        T               *_data;
        unsigned int    _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array<T> &other);
        Array<T> &operator=(const Array<T> &other);
        ~Array();
        
        T &operator[](unsigned int index);
        const T &operator[](unsigned int index) const;
        unsigned int size() const;

        class IndexOutOfBoundsException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

#include "Array.tpp"

#endif