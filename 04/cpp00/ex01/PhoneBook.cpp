/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:21:32 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/02 14:53:24 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Phonebook::Phonebook()
{
	this->p_index = 8;
	std::cout << "Phonebook Constructor called" << std::endl;
}

Phonebook::~Phonebook()
{
	std::cout << "Phonebook Destructor called" << std::endl;
}

void    Phonebook::enter(void) const {
    std::cout << std::endl;
    std::cout << "Welcome to Your Awesome PhoneBook" << std::endl;
    std::cout << std::endl;
    std::cout << "ADD\t: To add a contact." << std::endl;
    std::cout << "SEARCH\t: To search for a contact." << std::endl;
    std::cout << "EXIT\t: to quit the PhoneBook." << std::endl;
    std::cout << std::endl;
}

void	Phonebook::add_contact()
{
	int	flag = 0;
	std::string first_name = "";
	std::string last_name = "";
	std::string nickname = "";
	std::string phone_number = "";
	std::string darkest_secret = "";

	std::cin.ignore();
	while (std::cin.good() && (first_name.empty() || flag == 1))
	{
		flag = 0;
		std::cout << "First name = " << std::flush;
        std::getline(std::cin, first_name);
		if (first_name.empty())
			std::cout << "INVALID INPUT: please enter a name" << std::endl;
		else if (p_contact[p_index % 8].set_first_name(first_name) == 1)
		{
			std::cout << "INVALID INPUT: please enter a valid name" << std::endl;
			flag = 1;
		}
	}

	while (std::cin.good() && (last_name.empty() || flag == 1))
	{
		flag = 0;
		std::cout << "Last name = " << std::flush;
        std::getline(std::cin, last_name);
		if (last_name.empty())
			std::cout << "INVALID INPUT: please enter a name" << std::endl;
		else if (p_contact[p_index % 8].set_last_name(last_name) == 1)
		{
			std::cout << "INVALID INPUT: please enter a valid name" << std::endl;
			flag = 1;
		}
	}

	while (std::cin.good() && (nickname.empty() || flag == 1))
	{
		flag = 0;
		std::cout << "Nickname = " << std::flush;
        std::getline(std::cin, nickname);
		if (nickname.empty())
			std::cout << "INVALID INPUT: please enter a name" << std::endl;
		else if (p_contact[p_index % 8].set_nickname(nickname) == 1)
		{
			std::cout << "INVALID INPUT: please enter a valid name" << std::endl;
			flag = 1;
		}
	}

	while (std::cin.good() && (phone_number.empty() || flag == 1))
	{
		flag = 0;
		std::cout << "Phone number = " << std::flush;
        std::getline(std::cin, phone_number);
		if (phone_number.empty())
			std::cout << "INVALID INPUT: please enter a phone number" << std::endl;
		else if (p_contact[p_index % 8].set_phone_number(phone_number) == 1)
		{
			std::cout << "INVALID INPUT: please enter a valid phone number" << std::endl;
			flag = 1;
		}
	}

	while (std::cin.good() && (darkest_secret.empty() || flag == 1))
	{
		flag = 0;
		std::cout << "Darkest secret = " << std::flush;
        std::getline(std::cin, darkest_secret);
		if (darkest_secret.empty())
			std::cout << "INVALID INPUT: please enter something" << std::endl;
		(p_contact[p_index % 8].set_darkest_secret(darkest_secret));
	}

	this->p_index++;
	std::cout << "The contact has been successfully added" << std::endl;
	std::cin.clear();
}

void	Phonebook::search_contact()
{
	int	i = 0;
	std::string s;
	ft_display_contact();
	std::cout << "Enter the contact index: ";
	std::cin >> s;
	i = atoi(s.c_str());
	if (std::cin.fail() || i < 0 || i > 7 || s.length() > 1)
		std::cout << "Invalid Input" << std::endl;
	else
	{
		std::cout << "First name: " << p_contact[i].get_first_name() << std::endl;
		std::cout << "Last name: " << p_contact[i].get_last_name() << std::endl;
		std::cout << "Nickname: " << p_contact[i].get_nickname() << std::endl;
		std::cout << "Phone number: " << p_contact[i].get_phone_number() << std::endl;
		std::cout << "Darkest secret: " << p_contact[i].get_darkest_secret() << std::endl;
	}
	std::cin.clear();
	std::cin.ignore(100, '\n');
}

void	Phonebook::ft_display_contact() const
{
	std::cin.ignore();
	std::cout	<< "Contact Display: \n"
				<< "|   Index  |  F.Name  |  L.Name  | Nickname |\n";
	for (int i = 0; i < 8; i++)
	{
		std::cout << '|' << std::setw(10) << i << std::flush;
		std::cout << '|' << std::setw(10) << p_contact[i].show_first_name() << std::flush;
		std::cout << '|' << std::setw(10) << p_contact[i].show_last_name() << std::flush;
		std::cout << '|' << std::setw(10) << p_contact[i].show_nickname() << std::flush;
		std::cout << '|' << std::endl;
	}
}
