/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:38:30 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/23 08:32:41 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern& other) {
	std::cout << "Copy of Intern created" << std::endl;
	*this = other;
}

Intern::~Intern() {
	std::cout << "Intern destroyed" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
	std::cout << "Intern assignment operator" << std::endl;
	if (this == &other) 
		return( *this);
	return (*this);
}

AForm* Intern::makeForm(std::string name, std::string target) {
	static const int NForms = 3;
	t_forms forms[NForms] = 
	{
		{ "shrubbery creation", new ShrubberyCreationForm(target) },
		{ "robotomy request", new RobotomyRequestForm(target) },
		{ "presidential pardon", new PresidentialPardonForm(target) }
	};

	AForm* ret = NULL;
	for (int i = 0; i < NForms; i++) 
	{
		if (forms[i].name == name) 
			ret = forms[i].formClass;
		else
			delete forms[i].formClass;
	}
	if (ret != NULL)
		std::cout << "Intern creates <form> " << name << std::endl;
	else
		std::cout << "Intern was not able to find the <form> " << name << std::endl;

	return (ret);
}
