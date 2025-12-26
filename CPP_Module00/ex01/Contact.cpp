/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 11:35:26 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/12/26 11:35:26 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// constructor
Contact::Contact()
{

}

// setters
void	Contact::setFirstName(std::string firstName)
{
	_firstName = firstName;
}

void	Contact::setLastName(std::string lastName)
{
	_lastName = lastName;
}

void	Contact::setNickname(std::string nickname)
{
	_nickname = nickname;
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
	_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(std::string darkestSecret)
{
	_darkestSecret = darkestSecret;
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
