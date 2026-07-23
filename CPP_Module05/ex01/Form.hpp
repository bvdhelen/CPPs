/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 13:03:11 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/07/23 13:03:14 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iostream>

class	Bureaucrat;

class	Form
{
	private:
		const std::string	_name;
		bool			_isSigned;
		const int		_signGrade;
		const int		_executeGrade;
	public:
		//OCF
		Form();
		Form(const std::string &name, int signGrade, int executeGrade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		//getters
		const	std::string &getName() const;
		bool	getIsSigned() const;
		int	getSignGrade() const;
		int	getExecuteGrade() const;

		void	beSigned(const Bureaucrat &bureaucrat);
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

std::ostream	&operator<<(std::ostream &out, const Form &form);

#endif