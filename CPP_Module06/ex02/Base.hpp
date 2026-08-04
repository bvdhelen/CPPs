/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 20:40:41 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/08/04 14:13:07 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib> //std::rand()
#include <typeinfo> //std::bad_cast

class Base
{
    public:
        //OCF
        Base();
        Base(const Base &other);
        Base &operator=(const Base &other);
        virtual ~Base();        
};
    
Base *generate(void);
void  identify(Base *p);
void  identify(Base &p);

#endif