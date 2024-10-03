/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:20:41 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/03 17:39:03 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Call Dog default constructor" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Call Dog destructor" << std::endl;
	delete (this->brain);
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
	if (this != &other)
	{
		delete (this->brain);
		this->brain = new Brain();
		for (int i = 0; i < 100; i++)
			this->brain->set_idea(i, other.brain->get_idea(i));
	}
	std::cout << "Dog operator copy called" << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
}

Brain*	Dog::get_brain(void) const
{
	return (this->brain);
}
