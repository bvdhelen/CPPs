/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 19:45:44 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/08/05 17:48:07 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Orthodox Canonical Form
Span::Span() : _maxSize(0)
{
}

Span::Span(unsigned int N) : _maxSize(N)
{
    
}

Span::Span(const Span &other)
{
    *this = other;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return (*this);
}

Span::~Span()
{
}

// Exceptions
const char *Span::FullSpanException::what() const throw()
{
    return ("Span is full.");
}

const char *Span::NoSpanException::what() const throw()
{
    return ("Not enough numbers to calculate a span.");
}

// Member functions
void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw FullSpanException();
    _numbers.push_back(number);
}

int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw NoSpanException();
    std::vector<int> sorted = _numbers;
    
    std::sort(sorted.begin(), sorted.end());
    std::vector<int>::iterator it;
    
    it = sorted.begin();
    ++it;
    int minSpan = *it - *(it - 1);
    ++it;
    while (it != sorted.end())
    {
        int diff = *it - *(it - 1);
        if (diff < minSpan)
            minSpan = diff;
        ++it;
    }
    return (minSpan);
}

//You can do it with max_element & min_element
int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw NoSpanException();
    std::vector<int> sorted = _numbers;

    std::sort(sorted.begin(), sorted.end());
    return (*(sorted.end() - 1) - *sorted.begin());
}
