/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 13:08:51 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/07/23 13:16:01 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

void AForm::execute(const Bureaucrat &executor) const
{
    if (!getIsSigned())
        throw FormNotSignedException();

    if (executor.getGrade() > getExecuteGrade())
        throw GradeTooLowException();

    executeAction();
}

//OCF
AForm::AForm()
    : _name("Default"),
      _isSigned(false),
      _signGrade(150),
      _executeGrade(150)
{
}

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
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

AForm::AForm(const AForm &other)
    : _name(other._name),
      _isSigned(other._isSigned),
      _signGrade(other._signGrade),
      _executeGrade(other._executeGrade)
{
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    return (*this);
}

AForm::~AForm()
{
}

//getters
const std::string &AForm::getName() const
{
    return (_name);
}

bool AForm::getIsSigned() const
{
	return (_isSigned);
}

int AForm::getSignGrade() const
{
	return (_signGrade);
}

int AForm::getExecuteGrade() const
{
	return (_executeGrade);
}

//exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
    return ("grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("grade too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return ("form is not signed");
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << form.getName() << ", form is ";

    if (form.getIsSigned())
        out << "signed";
    else
        out << "not signed";

    out << ", sign grade " << form.getSignGrade();
    out << ", execute grade " << form.getExecuteGrade();
    out << ".";

    return (out);
}
