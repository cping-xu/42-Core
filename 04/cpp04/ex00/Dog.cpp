/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:20:41 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/03 17:36:03 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << "Call Dog default constructor" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Call Dog destructor" << std::endl;
}

Dog::Dog(Dog const &other) : Animal(other)
{
	std::cout << "Call Dog copy constructor" << std::endl;
	*this = other;
}

Dog	&Dog::operator=(const Dog &other)
{
	std::cout << "Call Dog operator=()" << std::endl;
	this->type = other.getType();
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
}
