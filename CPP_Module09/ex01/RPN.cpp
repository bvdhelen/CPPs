/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 20:34:27 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/09/15 16:03:44 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &other)
    : _stack(other._stack)
{
    
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}

void    RPN::checkStack()
{
    if (_stack.size() < 2)
        throw std::runtime_error("Error");
}

void    RPN::add()
{
    int     right;
    int     left;
    int     result;
        
    checkStack();
    right = _stack.top();
    _stack.pop();
    left = _stack.top();
    _stack.pop();
    result = left + right;
    _stack.push(result);
}

void    RPN::subtract()
{
    int     right;
    int     left;
    int     result;
        
    checkStack();
    right = _stack.top();
    _stack.pop();
    left = _stack.top();
    _stack.pop();
    result = left - right;
    _stack.push(result);
}

void	RPN::multiply()
{
	int     right;
    int     left;
    int     result;
        
    checkStack();
    right = _stack.top();
    _stack.pop();
    left = _stack.top();
    _stack.pop();
    result = left * right;
    _stack.push(result);
}

void	RPN::divide()
{
	int     right;
    int     left;
    int     result;
        
    checkStack();
    right = _stack.top();
	if (right == 0)
		throw std::runtime_error("Error");
    _stack.pop();
    left = _stack.top();
    _stack.pop();
    result = left / right;
    _stack.push(result);
}

int RPN::calculate(const std::string &expression)
{
    size_t  i;

    i = 0;
    while (i < expression.length())
    {
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            _stack.push(expression[i] - '0');
        }
        else if (expression[i] == '+')
			add();
		else if (expression[i] == '-')
			subtract();
		else if (expression[i] == '*')
			multiply();
		else if (expression[i] == '/')
			divide();
		else if (expression[i] == ' ')
			;
		else
			throw std::runtime_error("Error");
        i++;
    }

    if (_stack.size() != 1)
		throw std::runtime_error("Error");

    return _stack.top();
}
