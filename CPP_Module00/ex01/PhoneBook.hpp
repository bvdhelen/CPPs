/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:41:40 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/12/20 22:41:40 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream> //Para imprimir
#include <iomanip> //Para formatear la salida por consola (setw(10))

#define SIZE_BOOK 8

class PhoneBook
{
private:
	Contact contacts[SIZE_BOOK];
	int		count;
	int		index;

public:
	PhoneBook();

	void	addContact();
	void	searchContacts() const;
};

#endif