/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 13:03:32 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/07/23 13:03:35 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
    std::cout << "========== VALID CONSTRUCTION ==========\n";
    try
    {
        Bureaucrat alice("Alice", 20);
        Form contract("Contract", 50, 25);

        std::cout << alice << std::endl;
        std::cout << contract << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== FORM CONSTRUCTOR (GRADE TOO HIGH) ==========\n";
    try
    {
        Form f("High", 0, 50);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== FORM CONSTRUCTOR (GRADE TOO LOW) ==========\n";
    try
    {
        Form f("Low", 151, 50);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== SUCCESSFUL SIGN ==========\n";
    try
    {
        Bureaucrat alice("Alice", 20);
        Form contract("Contract", 50, 25);

        std::cout << contract << std::endl;
        alice.signForm(contract);
        std::cout << contract << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== FAILED SIGN ==========\n";
    try
    {
        Bureaucrat bob("Bob", 120);
        Form contract("Contract", 50, 25);

        std::cout << contract << std::endl;
        bob.signForm(contract);
        std::cout << contract << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== COPY CONSTRUCTOR ==========\n";
    try
    {
        Form original("Original", 30, 10);
        Form copy(original);

        std::cout << original << std::endl;
        std::cout << copy << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== ASSIGNMENT OPERATOR ==========\n";
    try
    {
        Form form1("Form1", 40, 20);
        Form form2("Form2", 100, 90);

        Bureaucrat alice("Alice", 20);
        alice.signForm(form1);

        std::cout << "Before assignment:" << std::endl;
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;

        form2 = form1;

        std::cout << "\nAfter assignment:" << std::endl;
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}
