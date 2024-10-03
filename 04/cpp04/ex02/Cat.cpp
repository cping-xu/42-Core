/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:20:34 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/03 17:57:57 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Call Cat default constructor" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Call Cat destructor" << std::endl;
	delete(this->brain);
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
	std::cout << "Call Cat copy constructor" << std::endl;
	*this = other;
}

Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Call Cat operator=()" << std::endl;
	this->type = other.getType();
	if (this != &other)
	{
		this->brain = new Brain();
		for (unsigned i = 0; i < 100; i++)
			this->brain->set_idea(i, other.brain->get_idea(i));
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}

Brain*	Cat::get_brain(void) const
{
	return (this->brain);
}
