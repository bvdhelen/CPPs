/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 14:20:28 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/07/05 14:30:48 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>

class Bureaucrat
{
    private:
    	const std::string	_name;
    	int	_grade;
    public:
		// Constructor
        
		// Constructor por defecto
		Bureaucrat();
		// Destructor
        ~Bureaucrat();
		// Constructor de copia
		Bureaucrat(const Bureaucrat &copy);
		// Operador de asignación
		Bureaucrat &operator=(const Bureaucrat &copy);

		// Funciones miembro
		
};

#endif