/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:37:19 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/23 08:24:45 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"

namespace {
	void checkGrade(int grade) {
		if (grade < Bureaucrat::kMaxGrade) throw Bureaucrat::GradeTooHighException();
		if (grade > Bureaucrat::kMinGrade) throw Bureaucrat::GradeTooLowException();
	}
}

AForm::AForm()
		: _signed(false),
		  name("Aform"),
		  target("none"),
		  signGrade(150),
		  executeGrade(150) {}

AForm::AForm(const std::string& name, const std::string& target, int signGrade, int executeGrade)
		: _signed(false),
		  name(name),
		  target(target),
		  signGrade(signGrade),
		  executeGrade(executeGrade) {
	checkGrade(signGrade);
	checkGrade(executeGrade);
	std::cout << "AForm created" << std::endl;
}

AForm::AForm(const AForm& other)
		: _signed(other._signed),
		  name(other.name),
		  target(other.target),
		  signGrade(other.signGrade),
		  executeGrade(other.executeGrade) {
	std::cout << "Copy of AForm created" << std::endl;
}

AForm::~AForm() {
	std::cout << "AForm destroyed" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	std::cout << "AForm assignment operator" << std::endl;
	if (this == &other) return *this;
	return *this;
}

const std::string& AForm::getName() const {
	return this->name;
}

const std::string& AForm::getTarget() const {
	return this->target;
}

bool AForm::getSigned() const {
	return this->_signed;
}

int AForm::getSignGrade() const {
	return this->signGrade;
}

int AForm::getExecuteGrade() const {
	return this->executeGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->signGrade) {
		this->_signed = true;
		std::cout << bureaucrat.getName() << " has signed " << this->name << std::endl;
	} else {
		std::cout << bureaucrat.getName() << " can't sign " << this->name << std::endl;
		throw AForm::GradeTooLowException();
	}
}

void AForm::beExecuted(const Bureaucrat& bureaucrat) const {
	if (this->_signed == false) {
		std::cout << bureaucrat.getName() << " can't execute " << this->name << std::endl;
		throw AForm::NotSigned();
	}
	if (bureaucrat.getGrade() > this->executeGrade) {
		std::cout << bureaucrat.getName() << " can't execute " << this->name << std::endl;
		throw AForm::GradeTooLowException();
	}

	std::cout << bureaucrat.getName() << " executed " << this->name << std::endl;
	this->executeAction();
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Exception: grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Exception: grade too low";
}

const char* AForm::NotSigned::what() const throw() {
	return "Exception: Aform is not _signed so it can't be executed";
}

std::ostream& operator<<(std::ostream& os, const AForm& instance) {
	os << "AForm " << instance.getName()
		<< ", status: " << (instance.getSigned() ? "signed" : "not _signed")
		<< ", sign grade: " << instance.getSignGrade()
		<< ", execute grade: " << instance.getExecuteGrade();
	return os;
}
