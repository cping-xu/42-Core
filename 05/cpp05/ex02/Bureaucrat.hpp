/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:37:07 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/23 08:17:03 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "AForm.hpp"

# include <iostream>
# include <string>
# include <exception>

class AForm;

class Bureaucrat {
	public:
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& other);

		static const int kMinGrade = 150;
		static const int kMaxGrade = 1;

		const std::string& getName() const;
		int getGrade() const;

		void increment();
		void increment(int quantity);
		void decrement();
		void decrement(int quantity);

		void signForm(AForm& Aform) const;
		void executeForm(const AForm& Aform) const;

	private:
		Bureaucrat();

		const std::string name;
		int grade;

	public:
		class GradeTooHighException : public std::exception {
			public: const char* what() const throw ();
		};
		class GradeTooLowException : public std::exception {
			public: const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& instance);

#endif
