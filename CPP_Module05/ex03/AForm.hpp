/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 13:09:21 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/07/23 13:18:58 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include <iostream>

class	Bureaucrat;

class	AForm
{
	private:
		const std::string	_name;
		bool			_isSigned;
		const int		_signGrade;
		const int		_executeGrade;
	protected:
		virtual void executeAction() const = 0;
	public:
    		void execute(Bureaucrat const &executor) const;
		//OCF
		AForm();
		AForm(const std::string &name, int signGrade, int executeGrade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

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
		
		class FormNotSignedException : public std::exception
		{
			public:
    				virtual const char *what() const throw();
		};

};

std::ostream	&operator<<(std::ostream &out, const AForm &form);

#endif