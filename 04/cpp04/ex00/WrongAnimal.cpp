/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:21:17 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/03 17:36:12 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	std::cout << "Call WrongAnimal default constructor" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Call WrongAnimal destructor" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other)
{
	std::cout << "Call WrongAnimal copy constructor" << std::endl;
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other)
{
	std::cout << "Call WrongAnimal operator=()" << std::endl;
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
