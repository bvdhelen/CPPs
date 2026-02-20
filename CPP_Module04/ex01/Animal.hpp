/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:11:07 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/02/20 13:01:37 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal(const std::string &type);
		Animal();
		virtual ~Animal();
		Animal(const Animal &copy);
		Animal &operator=(const Animal &copy);

		std::string		getType() const;
		virtual void	makeSound() const;
};

#endif