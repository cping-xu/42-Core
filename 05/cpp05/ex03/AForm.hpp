/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:38:27 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/23 08:26:06 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm {
	public:
		AForm(const std::string& name, const std::string& target, int signGrade, int executeGrade);
		AForm(const AForm& Aform);
		virtual ~AForm();

		AForm& operator=(const AForm& other);

		void beSigned(const Bureaucrat& bureaucrat);
		void beExecuted(const Bureaucrat& bureaucrat) const;

		virtual void executeAction() const = 0;

		const std::string& getName() const;
		const std::string& getTarget() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
	private:
		AForm();

		bool	_signed;

		const std::string	name;
		const std::string	target;
		const int	signGrade;
		const int	executeGrade;
	public:
		class GradeTooHighException : public std::exception {
			public: const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public: const char* what() const throw();
		};
		class NotSigned : public std::exception {
			public: const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& instance);

#endif
