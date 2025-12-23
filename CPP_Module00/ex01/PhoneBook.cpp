/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:41:36 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/12/20 22:41:36 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// constructor: inicializa la clase
PhoneBook::PhoneBook()
{
	count = 0;
	index = 0;
}

static std::string	formatField(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

static std::string	getInput(const std::string &prompt)
{
	std::string	input;

	while (input.empty())
	{
		std::cout << prompt;
		std::getline(std::cin, input);
	}
	return (input);
}

// LEER DEL USUARIO
// std::string input;
// std::getline(std::cin, input);

void	PhoneBook::addContact()
{
	contacts[index].setFirstName(getInput("First name: "));
	contacts[index].setLastName(getInput("Last Name: "));
	contacts[index].setNickname(getInput("Nickname: "));
	contacts[index].setPhoneNumber(getInput("Phone Number: "));
	contacts[index].setDarkestSecret(getInput("Darkest Secret: "));

	if (count < 8)
		count++;
	index = (index + 1) % 8;
}

void	PhoneBook::searchContacts() const
{
	int	i;

	i = 0;
	if (count == 0)
	{
		std::cout << "Phonebook is empty" << std::endl;
		return ;
	}
	// 1 )Imprimir cabecera
	std::cout	<< "|"
				<< std::setw(10) << "index" << "|"
				<< std::setw(10) << "first name" << "|"
				<< std::setw(10) << "last name" << "|"
				<< std::setw(10) << "nickname" << "|"
				<< std::endl;
	// 2) Imprimir TODOS los contactos
	while (i < count)
	{
		std::cout	<< "|"
					<< std::setw(10) << i << "|"
					<< std::setw(10) << formatField(contacts[i].getFirstName()) << "|"
					<< std::setw(10) << formatField(contacts[i].getLastName()) << "|"
					<< std::setw(10) << formatField(contacts[i].getNickname()) << "|"
					<< std::endl;
		i++;
	}
	// 3) Pedir índice al usuario
	std::string	input;
	int			idx;

	std::cout << "Enter index: ";
	std::getline(std::cin, input);
	// Validar si es un dígito valido (0-7)
	if (input.length() != 1 || input[0] < '0' || input[0] > '7')
	{
		std::cout << "Invalid index number" << std::endl;
		return ;
	}
	idx = input[0] - '0';
	// Comprobar que el índice existe (PhoneBook)
	if (idx < 0 || idx >= count)
	{
		std::cout << "Invalid index out of range" << std::endl;
		return ;
	}
	// 4) Mostrar contacto pedido completo
	std::cout << "First name: " << contacts[idx].getFirstName() << std::endl;
	std::cout << "Last name: " << contacts[idx].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[idx].getNickname() << std::endl;
}
