/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 19:45:38 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/08/05 17:07:10 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    return 0;
}

/*----------- OUTPUT -----------
    $> ./ex01
    2
    14
    $>
*/

/*----------- OTHER MAIN -----------
#include "Span.hpp"

int main(void)
{
    std::cout << "===== TEST 1: Ejemplo del enunciado =====" << std::endl;
    try
    {
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 2: Span lleno =====" << std::endl;
    try
    {
        Span sp(2);

        sp.addNumber(10);
        sp.addNumber(20);
        sp.addNumber(30);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 3: No hay suficientes números =====" << std::endl;
    try
    {
        Span sp(5);

        sp.addNumber(42);

        std::cout << sp.shortestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 4: longestSpan con un solo número =====" << std::endl;
    try
    {
        Span sp(5);

        sp.addNumber(42);

        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 5: addRange correcto =====" << std::endl;
    try
    {
        Span sp(5);

        std::vector<int> numbers;

        numbers.push_back(100);
        numbers.push_back(200);
        numbers.push_back(150);
        numbers.push_back(50);
        numbers.push_back(175);

        sp.addRange(numbers.begin(), numbers.end());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 6: addRange sin espacio suficiente =====" << std::endl;
    try
    {
        Span sp(3);

        std::vector<int> numbers;

        numbers.push_back(1);
        numbers.push_back(2);
        numbers.push_back(3);
        numbers.push_back(4);

        sp.addRange(numbers.begin(), numbers.end());
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "\n===== TEST 7: Números repetidos =====" << std::endl;
    try
    {
        Span sp(3);

        sp.addNumber(10);
        sp.addNumber(10);
        sp.addNumber(20);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
*/