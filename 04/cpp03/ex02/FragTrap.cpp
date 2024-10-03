/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:32:50 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/02 18:32:51 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name1 ) : ClapTrap(name1)
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;

    std::cout << "| FragTrap | - " << this->name << " constructed." << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "| FragTrap | - " << this->name << " destructed." << std::endl;
}

void    FragTrap::highFive( void ) {
    if ( this->energyPoints <= 0 ) {
        std::cout << "| FragTrap | - " << this->name << " is out of energy." << std::endl;
        return;
    }
    std::cout << "| FragTrap | - " << this->name << " high fives everybody." << std::endl;
    this->energyPoints -= 1;
}
