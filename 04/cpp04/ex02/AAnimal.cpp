/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:20:27 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/03 17:43:56 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("AAnimal")
{
	std::cout << "Call AAnimal default constructor" << std::endl;
}

AAnimal::~AAnimal(void)
{
	std::cout << "Call AAnimal destructor" << std::endl;
}

AAnimal::AAnimal(AAnimal const &other) : type(other.type)
{
	std::cout << "Call AAnimal copy constructor" << std::endl;
}

AAnimal &AAnimal::operator=(AAnimal const &other)
{
	std::cout << "Call Aanimal operator=()" << std::endl;
	type = other.type;
	return (*this);
}

void	AAnimal::makeSound(void) const
{
	std::cout << "AAnimal Sound" << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (type);
}
