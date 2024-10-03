/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:37:04 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/23 08:21:19 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

namespace {
	void checkGrade(int grade) {
		if (grade < Bureaucrat::kMaxGrade) throw Bureaucrat::GradeTooHighException();
		if (grade > Bureaucrat::kMinGrade) throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
		: name(name),
		  grade(grade) {
	checkGrade(grade);
	std::cout << "Bureaucrat created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
		: name(other.name) {
	*this = other;
	std::cout << "Copy of bureaucrat created" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destroyed" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	this->grade = other.grade;
	std::cout << "Assignment operator" << std::endl;
	return (*this);
}

const std::string& Bureaucrat::getName() const {
	return (this->name);
}

int Bureaucrat::getGrade() const {
	return (this->grade);
}

void Bureaucrat::increment() {
	std::cout << "Incrementing grade by 1" << std::endl;
	checkGrade(this->grade - 1);
	--this->grade;
}

void Bureaucrat::increment(int quantity) {
	std::cout << "Incrementing grade by " << quantity << std::endl;
	checkGrade(this->grade - quantity);
	this->grade = this->grade - quantity;
}

void Bureaucrat::decrement() {
	std::cout << "Decrementing grade by 1" << std::endl;
	checkGrade(this->grade + 1);
	++this->grade;
}

void Bureaucrat::decrement(int quantity) {
	std::cout << "Decrementing grade by " << quantity << std::endl;
	checkGrade(this->grade + quantity);
	this->grade = this->grade + quantity;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Exception: grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Exception: grade too low");
}

void Bureaucrat::signForm(AForm& Aform) const {
	Aform.beSigned(*this);
}

void Bureaucrat::executeForm(const AForm& Aform) const {
	try 
	{
		Aform.beExecuted(*this);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& instance) {
	os << instance.getName() << ", bureaucrat grade " << instance.getGrade();
	return (os);
}
