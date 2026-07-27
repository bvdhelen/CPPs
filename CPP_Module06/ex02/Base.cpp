/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 20:40:56 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/07/27 20:52:29 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <typeinfo> //std::bad_cast

//OCF
Base::Base()
{
}

Base::Base(const Base &other)
{
	*this = other;
}

Base &Base::operator=(const Base &other)
{
	(void)other;
	return (*this);
}

Base::~Base()
{
}

//funciones auxiliares
Base *generate(void)
{
    int random = std::rand() % 3;

    switch (random)
    {
        case 0:
            std::cout << "Generated A" << std::endl;
            return new A();

        case 1:
            std::cout << "Generated B" << std::endl;
            return new B();

        default:
            std::cout << "Generated C" << std::endl;
            return new C();
    }
}

void  identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
}

void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    }
    catch (std::bad_cast &e){}
    try
    {
        B &b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    }
    catch (std::bad_cast &e){}
    try
    {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    }
    catch (std::bad_cast &e){}
}
