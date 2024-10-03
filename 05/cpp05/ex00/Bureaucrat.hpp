/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:35:56 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/17 16:35:57 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP_
# define BUREAUCRAT_HPP_

# include <string>
# include <iostream>
# include <exception>

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
