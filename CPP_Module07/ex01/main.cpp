/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:57:16 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/08/04 21:35:51 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void print(const T &value)
{
    std::cout << value << std::endl;
}

template <typename T>
void increment(T &value)
{
    value++;
}

int main(void)
{
    // INT
    int numbers[] = {1, 2, 3, 4, 5};

    std::cout << "Original int array:" << std::endl;
    iter(numbers, 5, print<int>);
    iter(numbers, 5, increment<int>);
    std::cout << "After increment:" << std::endl;
    iter(numbers, 5, print<int>);

    // FLOAT
    float decimals[] = {1.5f, 2.5f, 3.5f};

    std::cout << "Float array:" << std::endl;
    iter(decimals, 3, print<float>);

    // STRING
    std::string words[] = {"Hello", "42", "Templates"};

    std::cout << "String array:" << std::endl;
    iter(words, 3, print<std::string>);

    // CONST INT
    const int values[] = {10, 20, 30};

    std::cout << "Const int array:" << std::endl;
    iter(values, 3, print<int>);

    return (0);
}
