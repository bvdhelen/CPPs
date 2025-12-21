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
	firstName = value;
}

void	Contact::setLastName(std::string value)
{
	lastName = value;
}

void	Contact::setNickname(std::string value)
{
	nickname = value;
}

void	Contact::setPhoneNumber(std::string value)
{
	phoneNumber = value;
}

void	Contact::setDarkestSecret(std::string value)
{
	darkestSecret = value;
}

// getters
std::string Contact::getFirstName() const
{
	return firstName;
}

std::string Contact::getLastName() const
{
	return lastName;
}

std::string Contact::getNickname() const
{
	return nickname;
}
