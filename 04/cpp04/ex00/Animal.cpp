/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:20:27 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/03 17:35:44 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
	std::cout << "Call Animal default constructor" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Call Animal destructor" << std::endl;
}

Animal::Animal(Animal const &other) : type(other.type)
{
	std::cout << "Call Animal copy constructor" << std::endl;
}

Animal &Animal::operator=(Animal const &other)
{
	std::cout << "Call animal operator=()" << std::endl;
	type = other.type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal Sound" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (type);
}
