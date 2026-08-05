/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:37:23 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/08/05 17:41:42 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other) : std::stack<T>(other)
{
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other)
{
    std::stack<T>::operator=(other);
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}
