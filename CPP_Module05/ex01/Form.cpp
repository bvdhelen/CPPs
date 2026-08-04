/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 13:04:14 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/08/04 11:34:00 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Orthodox Canonical Form
Form::Form()
    : _name("Default"),
      _isSigned(false),
      _signGrade(150),
      _executeGrade(150)
{
}

Form::Form(const std::string &name, int signGrade, int executeGrade)
    : _name(name),
      _isSigned(false),
      _signGrade(signGrade),
      _executeGrade(executeGrade)
{
    if (_signGrade < 1 || _executeGrade < 1)
        throw GradeTooHighException();
    if (_signGrade > 150 || _executeGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other)
    : _name(other._name),
      _isSigned(other._isSigned),
      _signGrade(other._signGrade),
      _executeGrade(other._executeGrade)
{
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    return (*this);
}

Form::~Form()
{
}

// Getters
const std::string &Form::getName() const
{
    return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecuteGrade() const
{
	return _executeGrade;
}

// Exception error messages
const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high.");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low.");
}

// Member function
void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

// Overload of the insertion operator <<
std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << form.getName() << " form is ";
    if (form.getIsSigned())
        out << "signed";
    else
        out << "not signed";
    out << "; sign grade " << form.getSignGrade();
    out << ", execute grade " << form.getExecuteGrade();
    out << ".";

    return out;
}
