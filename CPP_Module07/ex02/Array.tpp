/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:15:45 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/07/29 12:11:34 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

//constructor por defecto (sin parámetros)
template <typename T>
Array<T>::Array() : _data(NULL), _size(0)
{
}
//constructor
template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    _data = new T[_size];
}

//destructor
template <typename T>
Array<T>::~Array()
{
    delete[] _data;
}

//constructor de copia
template <typename T>
Array<T>::Array(const Array<T> &other) : _size(other._size)
{
    unsigned int    i;

    i = 0;
    _data = new T[_size];
    while (i < _size)
    {
        _data[i] = other._data[i];
        i++;
    }
}

//operador de asignación (deep copy)
template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
    unsigned int    i;

    if (this != &other)
    {
        delete[] _data;
        _size = other._size;
        _data = new T[_size];
        i = 0;
        while (i < _size)
        {
            _data[i] = other._data[i];
            i++;
        }
    }
    return (*this);
}

//exception
template <typename T>
const char *Array<T>::IndexOutOfBoundsException::what() const throw()
{
    return ("Array index is out of bounds.");
}

//funciones miembro
template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw IndexOutOfBoundsException();
    return (_data[index]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw IndexOutOfBoundsException();
    return (_data[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (_size);
}
