/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:17:10 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/03 18:08:23 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::get_first_name() const
{
	return (this->p_first_name);
}

std::string Contact::get_last_name() const
{
	return (this->p_last_name);
}

std::string Contact::get_nickname() const
{
	return (this->p_nickname);
}

std::string Contact::get_phone_number() const
{
	return (this->p_phone_number);
}

std::string Contact::get_darkest_secret() const
{
	return (this->p_darkest_secret);
}

std::string Contact::show_first_name() const
{
	return (this->s_first_name);
}

std::string Contact::show_last_name() const
{
	return (this->s_last_name);
}

std::string Contact::show_nickname() const
{
	return (this->s_nickname);
}

std::string Contact::show_phone_number() const
{
	return (this->s_phone_number);
}

std::string Contact::show_darkest_secret() const
{
	return (this->s_darkest_secret);
}

int	Contact::set_first_name(std::string first_name)
{
	size_t	s;
	size_t	i;

	s = 0;
	if (first_name == "")
		return (1);
	for (i = 0; i < first_name.size(); i++)
		if (!isalpha(first_name[i]))
		{
			if (isspace(first_name[i]))
			{
				s++;
				continue;
			}
			else
				return (1);
		}
	if (s == i)
		return (1);
	this->p_first_name = first_name;
	if (first_name.length() > 10)
	{
		first_name[9] = '.';
		first_name.erase(10, first_name.length() - 10);
	}
	this->s_first_name = first_name;
	return (0);
}

int	Contact::set_last_name(std::string last_name)
{
	size_t	s;
	size_t	i;

	s = 0;
	if (last_name == "")
		return (1);
	for (i = 0; i < last_name.size(); i++)
		if (!isalpha(last_name[i]))
		{
			if (isspace(last_name[i]))
			{
				s++;
				continue;
			}
			else
				return (1);
		}
	if (s == i)
		return (1);
	this->p_last_name = last_name;
	if (last_name.length() > 10)
	{
		last_name[9] = '.';
		last_name.erase(10, last_name.length() - 10);
	}
	this->s_last_name = last_name;
	return (0);
}

int	Contact::set_nickname(std::string nickname)
{
	size_t	s;
	size_t	i;

	s = 0;
	if (nickname == "")
		return (1);
	for (i = 0; i < nickname.size(); i++)
		if (!isalpha(nickname[i]))
		{
			if (isspace(nickname[i]))
			{
				s++;
				continue;
			}
			else
				return (1);
		}
	if (s == i)
		return (1);
	this->p_nickname = nickname;
	if (nickname.length() > 10)
	{
		nickname[9] = '.';
		nickname.erase(10, nickname.length() - 10);
	}
	this->s_nickname = nickname;
	return (0);
}

int	Contact::set_phone_number(std::string phone_number)
{
	size_t	s;
	size_t	i;

	s = 0;
	if (phone_number == "")
		return (1);
	for (i = 0; i < phone_number.size(); i++)
	{
		if (isspace(phone_number[i]))
		{
			s++;
			continue;
		}
		if (!isdigit(phone_number[i]))
			return (1);
	}
	if (s == i)
		return (1);
	this->p_phone_number = phone_number;
	if (phone_number.length() > 10)
	{
		phone_number[9] = '.';
		phone_number.erase(10, phone_number.length() - 10);
	}
	this->s_phone_number = phone_number;
	return (0);
}

int	Contact::set_darkest_secret(std::string darkest_secret)
{
	size_t	s;
	size_t	i;

	s = 0;
	if (darkest_secret == "")
		return (1);
	for (i = 0; i < darkest_secret.size(); i++)
	{
		if (isspace(darkest_secret[i]))
		{
			s++;
			continue;
		}
	}
	if (s == i)
		return (1);
	this->p_darkest_secret = darkest_secret;
	if (darkest_secret.length() > 10)
	{
		darkest_secret[9] = '.';
		darkest_secret.erase(10, darkest_secret.length() - 10);
	}
	this->s_darkest_secret = darkest_secret;
	return (0);
}
