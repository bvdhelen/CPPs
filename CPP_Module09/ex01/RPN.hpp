/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 20:34:30 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/09/15 15:12:54 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream> //cerr, cout
#include <stdexcept> //std::runtime_error
#include <string> //string
#include <stack> //stack

class RPN
{
    private:
        std::stack<int> _stack;

        //Member Private Functions
        void    checkStack();
        void    add();
        void    subtract();
        void    multiply();
        void    divide();

    public:
        //OCF
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        //Member Public Functions
        int calculate(const std::string &expression);

};

#endif
