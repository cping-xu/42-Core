/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:21:08 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/17 16:21:08 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <cstddef>
# include <exception>

class Span {
	private:
		typedef std::vector<int>::iterator ITER;
	public:
		Span(unsigned int n);
		Span(const Span& other);
		~Span();

		Span& operator=(const Span& other);

		void addNumber(int n);
		void addRange(ITER begin, ITER end);

		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		std::size_t size() const;
	private:
		Span();

		std::vector<int> vector;
		std::size_t _size;
	public:
		class SpanIsFullException : public std::exception {
			public: virtual const char* what() const throw();
		};
		class SizeTooSmallException : public std::exception {
			public: virtual const char* what() const throw();
		};
};

#endif
