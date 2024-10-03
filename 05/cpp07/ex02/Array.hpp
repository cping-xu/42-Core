/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:23:58 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/24 14:14:10 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <exception>

template <typename T>
class Array {
	public:
		Array() : head(NULL), _size(0) {}
		Array(unsigned int size) : head(new T[size]), _size(size) {}
		Array(const Array& other) :head(NULL) 
		{
			*this = other;
		}
		~Array() 
		{
			delete[] this->head;
		}

		Array& operator=(const Array& other) 
		{
			if (this == &other) return *this;
			if (this->_size != other._size) 
			{
				if (this->head != NULL) delete[] this->head;
				this->head = new T[other._size];
				this->_size = other.size();
			}
			for (std::size_t i = 0; i < this->_size; ++i) 
			{
				this->head[i] = other[i];
			}
			return (*this);
		}

		T& operator[](std::size_t index) 
		{
			if (index >= _size) 
				throw InvalidIndexException();
			else 
				return (head[index]);
		}
		const T& operator[](std::size_t index) const 
		{
			if (index >= _size)
				throw InvalidIndexException();
			else 
				return (head[index]);
		}

		std::size_t size() const {
			return (this->_size);
		}
		
	private:
		T* head;
		std::size_t _size;
		
	public:
		class InvalidIndexException : public std::exception 
		{
			public: virtual const char* what() const throw() 
			{
				return ("Invidalid index: index is either bigger than size or less than 0");
			}
		};
};

#endif
