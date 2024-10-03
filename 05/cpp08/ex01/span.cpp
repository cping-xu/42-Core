/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:21:04 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/25 11:59:15 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

#include <algorithm>

Span::Span() {}

Span::Span(unsigned int n) : _size(n) {}

Span::Span(const Span& other) : vector(other.vector), _size(other._size) {
	*this = other;
}

Span::~Span() {}

Span& Span::operator=(const Span& other) {
	if (this == &other) 
		return (*this);

	this->_size = other._size;
	this->vector = other.vector;

	return (*this);
}

void Span::addNumber(int n) {
	if (this->vector.size() == this->_size) {
		throw (Span::SpanIsFullException());
	}
	this->vector.push_back(n);
}

void Span::addRange(ITER begin, ITER end) {
	if (this->vector.size() + std::distance(begin, end) > this->_size) {
		throw (Span::SpanIsFullException());
	}
	this->vector.insert(this->vector.end(), begin, end);
}

unsigned int Span::shortestSpan() const {
	if (this->_size < 2 || this->vector.size() < 2) 
		(throw Span::SizeTooSmallException());

	std::vector<int> copy(this->vector);
	std::sort(copy.begin(), copy.end());
	int ret = *(copy.begin() + 1) - *copy.begin();
	for (ITER iter = copy.begin(); iter != copy.end() - 1; ++iter) {
		if(*(iter + 1) - *iter < ret)
		{
			ret = *(iter+ 1) - *iter;
		}
	}
	return (ret);
}

unsigned int Span::longestSpan() const {
	if (this->_size < 2 || this->vector.size() < 2) throw (Span::SizeTooSmallException());
	return (*std::max_element(this->vector.begin(), this->vector.end()) - 
	*std::min_element(this->vector.begin(), this->vector.end()));
}

std::size_t Span::size() const {
	return (this->_size);
}

const char* Span::SpanIsFullException::what() const throw() {
	return ("Can't add another number, span is full");
}

const char* Span::SizeTooSmallException::what() const throw() {
	return ("Size of span is less or equal to 1, no span to find");
}
