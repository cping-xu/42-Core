/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:27:47 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/02 16:05:17 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// int main()
// {
// 	Zombie ZombieInStack("stack");
// 	ZombieInStack.announce();
// 	Zombie *ZombieInHeap = newZombie("heap");
// 	ZombieInHeap->announce();
// 	randomChump("rand");
// 	delete ZombieInHeap;
// 	return (0);
// }

int main( void ) {
    std::string name;

    std::cout << "Creating zombie on the stack." << std::endl;
    std::cout << "Zombie name: " << std::flush;
    std::cin >> name;

    Zombie zombie1(name);
    
    std::cout << "Creating zombie on the heap." << std::endl;
    std::cout << "Zombie name: " << std::flush;
    std::cin >> name;

    Zombie *zombie2 = newZombie(name);
    zombie2->announce();
    delete zombie2;

    std::cout << "Calling randomChump()." << std::endl;
    randomChump("randi");
    return 0;
}
