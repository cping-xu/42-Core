/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:39:01 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/23 08:28:35 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
		: AForm("shrubbery creation", "none", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
		: AForm("shrubbery creation", target, 145, 137) {
	std::cout << "Shrubbery Creation AForm created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
		: AForm(other.getName(), other.getTarget(), other.getSignGrade(), other.getExecuteGrade()) {
	*this = other;
	std::cout << "Copy of Shrubbery Creation AForm created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Shrubbery Creation AForm destroyed" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "Shrubbery Creation AForm assignment operator" << std::endl;
	if (this == &other) return *this;
	return *this;
}

void ShrubberyCreationForm::executeAction() const {
	std::ofstream out;

	out.open((this->getTarget() + "_shrubbery").c_str(), std::ofstream::in | std::ofstream::trunc);

	out << std::endl;
	out << "               ,@@@@@@@,                  " << std::endl;
	out << "       ,,,.   ,@@@@@@/@@,  .oo8888o.      " << std::endl;
	out << "    ,&&%&%&&%,@@@@@/@@@@@@,8888|88/8o     " << std::endl;
	out << "   ,%&|%&&%&&%,@@@|@@@/@@@88|88888/88'    " << std::endl;
	out << "   %&&%&%&/%&&%@@|@@/ /@@@88888|88888'    " << std::endl;
	out << "   %&&%/ %&&%&&@@| V /@@' `88|8 `/88'     " << std::endl;
	out << "   `&%| ` /%&'    |.|        | '|8'       " << std::endl;
	out << "       |o|        | |         | |         " << std::endl;
	out << "       |.|        | |         | |         " << std::endl;
	out << "    ||/ ._|//_/__/  ,|_//__||/.  |_//__/_ " << std::endl;
}
