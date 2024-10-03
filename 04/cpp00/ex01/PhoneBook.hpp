/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:26:50 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/02 14:21:56 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# define MAX_CONTACT 8

class Phonebook{

private:
	Contact p_contact[8];
	int		p_index;

public:
	Phonebook();
	~Phonebook();
	void	add_contact();
	void	search_contact();
	void	ft_display_contact() const;
	void    enter(void) const;
};

#endif
