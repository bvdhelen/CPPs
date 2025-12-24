/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:41:28 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/12/20 22:41:28 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// constructor
Contact::Contact()
{

}

// setters
void	Contact::setFirstName(std::string value)
{
	_firstName = value;
}

void	Contact::setLastName(std::string value)
{
	_lastName = value;
}

void	Contact::setNickname(std::string value)
{
	_nickname = value;
}

void	Contact::setPhoneNumber(std::string value)
{
	_phoneNumber = value;
}

void	Contact::setDarkestSecret(std::string value)
{
	_darkestSecret = value;
}

// getters
std::string Contact::getFirstName() const
{
	return _firstName;
}

std::string Contact::getLastName() const
{
	return _lastName;
}

std::string Contact::getNickname() const
{
	return _nickname;
}
