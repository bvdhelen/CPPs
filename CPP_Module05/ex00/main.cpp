/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 12:51:47 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/08/04 10:57:36 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "========== VALID CONSTRUCTION ==========\n";
    try
    {
        Bureaucrat bob("Bob", 42);
        std::cout << bob << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== GRADE TOO HIGH ==========\n";
    try
    {
        Bureaucrat high("High", 0);
        std::cout << high << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== GRADE TOO LOW ==========\n";
    try
    {
        Bureaucrat low("Low", 151);
        std::cout << low << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== INCREMENT ==========\n";
    try
    {
        Bureaucrat alice("Alice", 2);

        std::cout << alice << std::endl;

        alice.incrementGrade();
        std::cout << "After increment: " << alice << std::endl;

        alice.incrementGrade();
        std::cout << alice << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== DECREMENT ==========\n";
    try
    {
        Bureaucrat john("John", 149);

        std::cout << john << std::endl;

        john.decrementGrade();
        std::cout << "After decrement: " << john << std::endl;

        john.decrementGrade();
        std::cout << john << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== COPY CONSTRUCTOR ==========\n";
    try
    {
        Bureaucrat original("Original", 50);
        Bureaucrat copy(original);

        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy:     " << copy << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== ASSIGNMENT OPERATOR ==========\n";
    try
    {
        Bureaucrat a("Alice", 10);
        Bureaucrat b("Bob", 100);

        std::cout << "Before assignment:" << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;

        b = a;

        std::cout << "\nAfter assignment:" << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}
