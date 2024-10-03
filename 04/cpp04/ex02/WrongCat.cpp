/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:21:31 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/03 16:29:51 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << "Passing through WrongCat default constructor" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Passing through WrongCat destructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "Passing through WrongCat copy constructor" << std::endl;
	*this = other;
}

WrongCat	&WrongCat::operator=(const WrongCat &other)
{
	std::cout << "Passing through WrongCat operator=()" << std::endl;
	this->type = other.getType();
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat ~ Meow" << std::endl;
}
