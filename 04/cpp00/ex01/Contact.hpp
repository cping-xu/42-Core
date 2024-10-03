/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:06:40 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/02 14:52:43 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <iomanip>

class Contact {

private:
	std::string p_first_name;
	std::string p_last_name;
	std::string p_nickname;
	std::string p_phone_number;
	std::string p_darkest_secret;
	
	std::string s_first_name;
	std::string s_last_name;
	std::string s_nickname;
	std::string s_phone_number;
	std::string s_darkest_secret;

public:
	Contact();
	~Contact();

	std::string get_first_name() const;
	std::string get_last_name() const;
	std::string get_nickname() const;
	std::string get_phone_number() const;
	std::string get_darkest_secret() const;

	std::string show_first_name() const;
	std::string show_last_name() const;
	std::string show_nickname() const;
	std::string show_phone_number() const;
	std::string show_darkest_secret() const;

	int	set_first_name(std::string first_name);
	int	set_last_name(std::string last_name);
	int	set_nickname(std::string nickname);
	int	set_phone_number(std::string phone_number);
	int	set_darkest_secret(std::string darkest_secret);
};

#endif
