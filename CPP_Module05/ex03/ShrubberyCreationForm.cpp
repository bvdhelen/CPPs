/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 13:12:52 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/08/04 11:40:20 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Orthodox Canonical Form
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target)
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// Member function
void	ShrubberyCreationForm::executeAction() const
{
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file.is_open())
		return ;
	file << "       *\n";
	file << "      ***\n";
	file << "     *****\n";
	file << "    *******\n";
	file << "       ||\n";
	file << "       ||\n";
	file.close();
}	
