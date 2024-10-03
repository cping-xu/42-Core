/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:20:47 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/03 16:32:22 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	std::cout << "-----Wrong Animal-----" << std::endl;
	const WrongAnimal* a = new WrongCat();
	const WrongAnimal* c = new WrongAnimal();
	std::cout << a->getType() << " " << std::endl;
	a->makeSound();
	std::cout << c->getType() << " " << std::endl;
	c->makeSound();
	WrongCat b;
	std::cout << b.getType() << " " << std::endl;
	b.makeSound();
	delete a;
	delete b;
	delete c;
	return (0);
}
