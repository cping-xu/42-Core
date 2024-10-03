/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:20:56 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/25 12:03:32 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

#include <iostream>
#include <exception>

int main() {
	// normal test
	try {
		Span s(5);
		s.addNumber(2);
		s.addNumber(4);
		s.addNumber(6);
		s.addNumber(8);
		s.addNumber(10);
		std::cout << "shortest span: " << s.shortestSpan() << std::endl;
		std::cout << "longest span : " << s.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cerr << "EXCEPTION: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	// already full exception
	try {
		Span s(5);
		s.addNumber(2);
		s.addNumber(4);
		s.addNumber(6);
		s.addNumber(8);
		s.addNumber(10);
		s.addNumber(12);
		std::cout << "shortest span: " << s.shortestSpan() << std::endl;
		std::cout << "longest span : " << s.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cerr << "EXCEPTION: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	// too small exception
	try {
		Span s(5);
		s.addNumber(2);
		std::cout << "shortest span: " << s.shortestSpan() << std::endl;
		std::cout << "longest span : " << s.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cerr << "EXCEPTION: " << e.what() << std::endl;
	}
	try {
		Span s(1);
		s.addNumber(2);
		std::cout << "shortest span: " << s.shortestSpan() << std::endl;
		std::cout << "longest span : " << s.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cerr << "EXCEPTION: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	// bigger span
	std::vector<int> big(10000);
	for (int i = 0; i < 10000; ++i) big[i] = i;
	try {
		Span s(10000);
		s.addRange(big.begin(), big.end());
		std::cout << "shortest span: " << s.shortestSpan() << std::endl;
		std::cout << "longest span : " << s.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cerr << "EXCEPTION: " << e.what() << std::endl;
	}

	return 0;
}

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }
