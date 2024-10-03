/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:21:17 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/03 16:29:56 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	std::cout << "Passing through WrongAnimal default constructor" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Passing through WrongAnimal destructor" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other)
{
	std::cout << "Passing through WrongAnimal copy constructor" << std::endl;
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other)
{
	std::cout << "Passing through WrongAnimal operator=()" << std::endl;
	this->type = other.getType();
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Wrong Animal ~ Sound" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}
