/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:15:50 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/08/04 16:09:10 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

int main(void)
{
    std::cout << "DEFAULT CONSTRUCTOR" << std::endl;
    Array<int> empty;

    std::cout << "empty.size() = " << empty.size() << std::endl;

    std::cout << "\nCONSTRUCTOR WITH SIZE" << std::endl;
    Array<int> numbers(5);

    for (unsigned int i = 0; i < numbers.size(); i++)
        numbers[i] = i * 10;
    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;

    std::cout << "\nCOPY CONSTRUCTOR" << std::endl;

    Array<int> copy(numbers);

    copy[0] = 999;
    std::cout << "Original:" << std::endl;
    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    std::cout << "Copy:" << std::endl;
    for (unsigned int i = 0; i < copy.size(); i++)
        std::cout << copy[i] << " ";
    std::cout << std::endl;

    std::cout << "Deep copy OK? ";
    if (numbers[0] == 0 && copy[0] == 999)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;

    std::cout << "\nASSIGNMENT OPERATOR" << std::endl;

    Array<int> assign;

    assign = numbers;
    assign[1] = 555;
    std::cout << "Original:" << std::endl;
    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    std::cout << "Assigned:" << std::endl;
    for (unsigned int i = 0; i < assign.size(); i++)
        std::cout << assign[i] << " ";
    std::cout << std::endl;

    std::cout << "Deep copy OK? ";
    if (numbers[1] == 10 && assign[1] == 555)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;

    std::cout << "\nSTRING ARRAY" << std::endl;

    Array<std::string> words(3);

    words[0] = "Hello";
    words[1] = "42";
    words[2] = "Madrid";
    for (unsigned int i = 0; i < words.size(); i++)
        std::cout << words[i] << std::endl;

    std::cout << "\nOUT OF BOUNDS" << std::endl;
    try
    {
        numbers[10] = 100;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << numbers[42] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}
