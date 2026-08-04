/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 13:07:43 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/08/04 11:37:00 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Orthodox Canonical Form
Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

// Getters
const std::string &Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

// Member functions
void	Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

// Exception error messages
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low.";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high.";
}

// Overload of the insertion operator <<
std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName()
		<< ", bureaucrat grade "
		<< bureaucrat.getGrade()
		<< ".";
	return out;
}

// New member function ex01
void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << _name
                  << " couldn't sign "
                  << form.getName()
                  << " because "
                  << e.what()
                  << std::endl;
    }
}

// New member function ex02
void Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        form.execute(*this);
        std::cout << _name
                  << " executed "
                  << form.getName()
                  << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << _name
                  << " couldn't execute "
                  << form.getName()
                  << " because "
                  << e.what()
                  << std::endl;
    }
}
