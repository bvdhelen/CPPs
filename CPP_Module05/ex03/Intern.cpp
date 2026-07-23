/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 13:19:35 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/07/23 13:19:43 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

//OCF

Intern::Intern()
{

}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
}

//funciones miembro y creadoras
static AForm *createShrubbery(const std::string &target)
{
    return (new ShrubberyCreationForm(target));
}

static AForm *createRobotomy(const std::string &target)
{
    return (new RobotomyRequestForm(target));
}

static AForm *createPresidential(const std::string &target)
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	std::string forms[3] =
	{
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};
	AForm *(*creators[3])(const std::string &) =
	{
		createShrubbery,
		createRobotomy,
		createPresidential
	};
	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return (creators[i](target));
		}
	}
	std::cout << "Intern couldn't create " << name << std::endl;
	return (NULL);
}
