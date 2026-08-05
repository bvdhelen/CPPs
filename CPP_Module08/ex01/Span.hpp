/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 19:45:46 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/08/05 16:58:45 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <iostream>
#include <algorithm> //std::sort()
#include <iterator> //std::distance(begin, end)

class Span
{
    private:
        unsigned int _maxSize;
        std::vector<int> _numbers;
    public:
        //OCF
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        //member functions
        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;
        
        template <typename Iterator>
        void addRange(Iterator begin, Iterator end);

        //exceptions
        class FullSpanException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class NoSpanException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
    if (_numbers.size() + std::distance(begin, end) > _maxSize)
        throw FullSpanException();
    while (begin != end)
    {
        addNumber(*begin);
        ++begin;
    }
}

#endif