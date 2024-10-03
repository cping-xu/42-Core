/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:36:35 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/18 21:20:50 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class Form {
	public:
		Form(const std::string& name, int signGrade, int executeGrade);
		Form(const Form& form);
		~Form();
		Form& operator=(const Form& other);

		void beSigned(const Bureaucrat& bureaucrat);
		const std::string& getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

	private:
		Form();

		bool _signed;

		const std::string name;
		const int signGrade;
		const int executeGrade;

	public:
		class GradeTooHighException : public std::exception {
			public: const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public: const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& instance);

#endif
