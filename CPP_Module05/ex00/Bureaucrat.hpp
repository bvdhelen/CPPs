/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 12:52:03 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/07/23 12:52:05 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class	Bureaucrat
{
	private:
		const std::string	_name;
		int			_grade;
	public:
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
		
		//getters
		const std::string &getName() const;
		int getGrade() const;
		
		//cambiar grade??
		void incrementGrade();
		void decrementGrade();

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

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif