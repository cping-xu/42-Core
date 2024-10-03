/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:20:34 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/03 17:35:54 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << "Call Cat default constructor" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Call Cat destructor" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Call Cat copy constructor" << std::endl;
	*this = other;
}

Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Call Cat operator=()" << std::endl;
	this->type = other.getType();
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
