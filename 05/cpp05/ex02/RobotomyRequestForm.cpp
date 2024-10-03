/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:37:46 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/23 08:14:34 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
		: AForm("robotomy request", "none", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
		: AForm("robotomy request", target, 72, 45) {
	std::cout << "Robotomy Request AForm created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
		: AForm(other.getName(), other.getTarget(), other.getSignGrade(), other.getExecuteGrade()) {
	*this = other;
	std::cout << "Copy of Robotomy Request AForm created" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Robotomy Request AForm destroyed" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cout << "Robotomy Request AForm assignment operator" << std::endl;
	if (this == &other) return *this;
	return (*this);
}

void RobotomyRequestForm::executeAction() const {
	std::srand(std::time(NULL)); // use current time (seed) for random generator

	std::cout << "* SOME DRILLING NOISES *" << std::endl;
	if (std::rand() % 2 == 0) {
		std::cout << this->getTarget() << " has been robotomized succesfully" << std::endl;
	} else {
		std::cout << "Failed to robotomized " << this->getTarget() << std::endl;
	}
}
