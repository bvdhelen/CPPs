/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:41:30 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/12/20 22:41:30 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;

public:
	Contact();

	void setFirstName(std::string value);
	void setLastName(std::string value);
	void setNickname(std::string value);
	void setPhoneNumber(std::string value);
	void setDarkestSecret(std::string value);

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
};

#endif