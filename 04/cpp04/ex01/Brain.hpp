/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:23:45 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/03 17:33:48 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>
# include <cstring>

class Brain
{
	public :
		Brain();
		~Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);

		std::string	ideas[100];
		std::string get_idea(int i);
		// std::string* get_idea(void) { return ideas; }
		void set_idea(int i, std::string str);
};
 
#endif
