/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:37:39 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/23 08:14:52 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
		: AForm("presidential pardon", "none", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
		: AForm("presidential pardon", target, 25, 5) {
	std::cout << "Presidential Pardon AForm created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
		: AForm(other.getName(), other.getTarget(), other.getSignGrade(), other.getExecuteGrade()) {
	*this = other;
	std::cout << "Copy of Presidential Pardon AForm created" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Presidential Pardon AForm destroyed" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << "Presidential Pardon AForm assignment operator" << std::endl;
	if (this == &other) return *this;
	return (*this);
}

void PresidentialPardonForm::executeAction() const {
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
