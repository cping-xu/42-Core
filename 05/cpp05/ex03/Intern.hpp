/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:38:33 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/23 08:31:19 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

# include <string>

class Intern {
	public:
		Intern();
		Intern(const Intern& other);
		~Intern();

		Intern& operator=(const Intern& other);

		AForm* makeForm(std::string name, std::string target);
	
	private:
		typedef struct s_forms {
			std::string name;
			AForm *formClass;
		} t_forms;
};

#endif
