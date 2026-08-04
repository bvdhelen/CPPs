/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 13:08:13 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/08/04 12:08:38 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <ctime>

int main()
{
    srand(time(NULL));

    Intern intern;
    Bureaucrat boss("Boss", 1);
    Bureaucrat worker("Worker", 50);
    Bureaucrat internGrade("Intern", 150);
    AForm *form;

    std::cout << "========== SHRUBBERY ==========\n";
    form = intern.makeForm("ShrubberyCreationForm", "home");
    if (form)
    {
        std::cout << *form << std::endl;

        internGrade.signForm(*form);
        worker.signForm(*form);

        internGrade.executeForm(*form);
        worker.executeForm(*form);

        delete form;
    }
    std::cout << "\n========== ROBOTOMY ==========\n";
    form = intern.makeForm("RobotomyRequestForm", "Bender");
    if (form)
    {
        std::cout << *form << std::endl;

        worker.signForm(*form);
        boss.signForm(*form);

        worker.executeForm(*form);

        std::cout << "\nTrying several robotomies:\n";

        for (int i = 0; i < 5; i++)
            boss.executeForm(*form);

        delete form;
    }
    std::cout << "\n========== PRESIDENTIAL ==========\n";
    form = intern.makeForm("PresidentialPardonForm", "Arthur Dent");
    if (form)
    {
        std::cout << *form << std::endl;

        worker.signForm(*form);
        boss.signForm(*form);

        worker.executeForm(*form);
        boss.executeForm(*form);

        delete form;
    }
    std::cout << "\n========== WRONG FORM ==========\n";
    form = intern.makeForm("pizza form", "Pepperoni");
    if (!form)
        std::cout << "Returned NULL correctly." << std::endl;
    std::cout << "========== EXCEPTIONS ==========\n";
    try
    {
        Bureaucrat test("TooHigh", 0);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat test("TooLow", 151);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return (0);
}
