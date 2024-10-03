/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:24:09 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/03 17:56:23 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

#include "WrongCat.hpp"

int main( void )
{
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();

	//New main test
	{
		const Animal* j = new Dog();
		delete j;//should not create a leak
		std::cout << std::endl;
		const Animal* i = new Cat();
		delete i;
	}
		std::cout << std::endl;
		//Test to access Brain class ideas
	{
		const Dog* j = new Dog();
		std::cout << j->getType() << " " << std::endl;
		for (int i = 0; i < 100; i++)
			std::cout << j->get_brain()->get_idea(i) << " " << std::endl;
		delete j;
	}
	
	//Test a deep copy of dog
	// const Dog* j = new Dog();
	// // const Dog k(*j);
	// // const Dog k = (*j);
	// j->get_brain()->set_idea(0, "Fucking  brilliant idea!");
	// std::cout << j->getType() << " " << std::endl;
	// for (int i = 0; i < 5; i++)
	// 	std::cout << j->get_brain()->get_idea(i) << " " << std::endl;
	// delete j;
	// std::cout << k.getType() << " " << std::endl;
	// for (int i = 0; i < 5; i++)
	// 	std::cout << k.get_brain()->get_idea(i) << " " << std::endl;
	
    // delete j;
    // delete i;

    // Dog basic;
    // {
    //     Dog tmp = basic;
    // }

    // const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
    // for ( int i = 0; i < 4; i++ ) {
    //     delete (animals[i]);
    // }

    return (0);
}
