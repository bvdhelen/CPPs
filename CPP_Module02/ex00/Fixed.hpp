/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:54:47 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/01/04 17:54:47 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int	_value;
		static const int	_fractionalBits = 8;
	public:
		// constructor
		Fixed();
		// destructor
		~Fixed();
		// constructor de copia
		Fixed(const Fixed &copy);
		// operador de asignación
		Fixed	&operator=(const Fixed &copy);

		// funciones miembro
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif