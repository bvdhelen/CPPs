/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 13:08:13 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/07/23 13:08:16 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void)
{
    srand(time(NULL));

    std::cout << "========== CREATE BUREAUCRATS ==========\n";

    Bureaucrat boss("Boss", 1);
    Bureaucrat worker("Worker", 50);
    Bureaucrat intern("Intern", 150);

    std::cout << boss << std::endl;
    std::cout << worker << std::endl;
    std::cout << intern << std::endl;

    std::cout << "\n========== CREATE FORMS ==========\n";

    ShrubberyCreationForm shrub("garden");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    std::cout << shrub << std::endl;
    std::cout << robot << std::endl;
    std::cout << pardon << std::endl;

    std::cout << "\n========== EXECUTE WITHOUT SIGN ==========\n";

    boss.executeForm(shrub);
    boss.executeForm(robot);
    boss.executeForm(pardon);

    std::cout << "\n========== SIGN FORMS ==========\n";

    intern.signForm(shrub);
    worker.signForm(shrub);

    worker.signForm(robot);
    boss.signForm(robot);

    worker.signForm(pardon);
    boss.signForm(pardon);

    std::cout << "\n========== EXECUTE SHRUBBERY ==========\n";

    intern.executeForm(shrub);
    worker.executeForm(shrub);

    std::cout << "\n========== EXECUTE ROBOTOMY ==========\n";

    worker.executeForm(robot);

    std::cout << "\nTrying several robotomies:\n";

    for (int i = 0; i < 5; i++)
        boss.executeForm(robot);

    std::cout << "\n========== EXECUTE PRESIDENTIAL ==========\n";

    worker.executeForm(pardon);
    boss.executeForm(pardon);

    return (0);
}
