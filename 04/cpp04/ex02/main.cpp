/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:24:09 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/03 17:57:25 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "AAnimal.hpp"

#include "WrongCat.hpp"

int main( void )
{
    // std::cout << std::endl;
	// {
	// 	const AAnimal* i = new Cat();
	// 	std::cout << i->getType() << " " << std::endl;
	// 	i->makeSound(); //will output the cat sound!
	// 	delete i;
	// }
	// std::cout << std::endl;
	// {
	// 	const AAnimal* j = new Dog();
	// 	std::cout << j->getType() << " " << std::endl;
	// 	j->makeSound();
	// 	delete j;
	// }
	// std::cout << std::endl;
	//New main test
	// {
	// 	const AAnimal* j = new Dog();
	// 	delete j;//should not create a leak
	// 	std::cout << std::endl;
	// 	const AAnimal* i = new Cat();
	// 	delete i;
	// }
	// 	std::cout << std::endl;
	// 	//Test to access Brain class ideas
	// {
	// 	const Dog* j = new Dog();
	// 	std::cout << j->getType() << " " << std::endl;
	// 	for (int i = 0; i < 100; i++)
	// 		std::cout << j->get_brain()->get_idea(i) << " " << std::endl;
	// 	delete j;
	// }
		//Test a deep copy of dog
	{
		const Dog* j = new Dog();
		//const Dog k(*j);
		const Dog k = (*j);
		j->get_brain()->set_idea(0, "Fucking  brilliant idea!");
		std::cout << j->getType() << " " << std::endl;
		for (int i = 0; i < 5; i++)
			std::cout << j->get_brain()->get_idea(i)<< " " << std::endl;
		delete j;
		std::cout << k.getType() << " " << std::endl;
		for (int i = 0; i < 5; i++)
			std::cout << k.get_brain()->get_idea(i) << " " << std::endl;
	}
	std::cout << std::endl;
	{
		const AAnimal* a[100];
		for (int i = 0; i < 100; i++){

			if (i < 50)
				a[i] = new Dog();
			else
				a[i] = new Cat();
		}
		for (int i = 0; i < 100; i++){
			delete a[i];
		}
	}

    return (0);
}
