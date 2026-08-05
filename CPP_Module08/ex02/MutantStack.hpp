/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:12:19 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/08/05 17:43:07 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        //OCF
        MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack &operator=(const MutantStack &other);
        ~MutantStack();
    
        // Alias del iterador del contenedor interno
        //non-const
        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin()
        {
            return (this->c.begin());
        }
        iterator end()
        {
            return (this->c.end());
        }
        //const
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        
        const_iterator begin() const
        {
            return (this->c.begin());
        }
        const_iterator end() const
        {
            return (this->c.end());
        }
};

#include "MutantStack.tpp"

#endif