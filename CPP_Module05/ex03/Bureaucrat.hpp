/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 13:07:29 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/08/04 11:37:57 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class AForm;

class	Bureaucrat
{
	private:
		const std::string	_name;
		int			_grade;
	public:
		//OCF
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
		
		//getters
		const std::string &getName() const;
		int getGrade() const;
		
		//member functions
		void incrementGrade();
		void decrementGrade();

		//new member function ex01
		void signForm(AForm &form);
		
		//new member function ex02
		void executeForm(AForm const &form);

		//exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif