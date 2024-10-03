/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:23:40 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/03 17:35:07 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() : ideas()
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "I have a great idea! " + std::to_string(i);
	std::cout << "Call Brain constructor" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Call Brain destructor" << std::endl;
}

Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << "Call Brain copy constructor" << std::endl;
}

Brain	&Brain::operator=(const Brain &other)
{
	std::cout << "Call Brain operator=()" << std::endl;
	// for (unsigned i = 0; i < 100; i++)
	// 	this->ideas[i] = other.ideas[i];
	if (this == &other)
		return (*this);
	return (*this);
}

void	Brain::set_idea(int i, std::string str)
{
	this->ideas[i] = str;
}

std::string	Brain::get_idea(int i)
{
	return (this->ideas[i]);
}
