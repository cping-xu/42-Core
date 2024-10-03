/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:36:41 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/18 21:20:49 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

namespace {
	void checkGrade(int grade) {
		if (grade < Bureaucrat::kMaxGrade) throw Bureaucrat::GradeTooHighException();
		if (grade > Bureaucrat::kMinGrade) throw Bureaucrat::GradeTooLowException();
	}
}

Form::Form()
		: _signed(false),
		  name("form"),
		  signGrade(150),
		  executeGrade(150) {}

Form::Form(const std::string& name, int signGrade, int executeGrade)
		: _signed(false),
		  name(name),
		  signGrade(signGrade),
		  executeGrade(executeGrade) {
	checkGrade(signGrade);
	checkGrade(executeGrade);
	std::cout << "Form created" << std::endl;
}

Form::Form(const Form& other)
		: _signed(other._signed),
		  name(other.name),
		  signGrade(other.signGrade),
		  executeGrade(other.executeGrade) {
	std::cout << "Copy of form created" << std::endl;
}

Form::~Form() {
	std::cout << "Form destroyed" << std::endl;
}

Form& Form::operator=(const Form& other) {
	std::cout << "Form assignment operator" << std::endl;
	if (this == &other) return *this;
	return *this;
}

const std::string& Form::getName() const {
	return this->name;
}

bool Form::getSigned() const {
	return this->_signed;
}

int Form::getSignGrade() const {
	return this->signGrade;
}

int Form::getExecuteGrade() const {
	return this->executeGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->signGrade) {
		this->_signed = true;
		std::cout << bureaucrat.getName() << " has signed " << this->name << std::endl;
	} else {
		std::cout << bureaucrat.getName() << " can't sign " << this->name << std::endl;
		throw Form::GradeTooLowException();
	}
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Exception: grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Exception: grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& instance) {
	os << "Form " << instance.getName()
		<< ", status: " << (instance.getSigned() ? "signed" : "not signed")
		<< ", sign grade: " << instance.getSignGrade()
		<< ", execute grade: " << instance.getExecuteGrade()
		<< std::endl;
	return os;
}
