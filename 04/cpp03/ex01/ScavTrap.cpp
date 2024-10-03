/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:32:27 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/02 18:33:41 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name1 ) : ClapTrap(name1)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;

    std::cout << "< ScavTrap > - " << this->name << " constructed." << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "< ScavTrap > - " << this->name << " destructed." << std::endl;
}

void    ScavTrap::attack( std::string const& target ) {
    if ( this->energyPoints <= 0 ) {
        std::cout << "< ScavTrap > - " << this->name << " is out of energy." << std::endl;
        return;
    }
    std::cout << "< ScavTrap > - " << this->name << " attacks " << target << " at range, causing " << this->attackDamage << " points of damage !" << std::endl;
    this->energyPoints -= 1;
}

void    ScavTrap::guardGate() {
    std::cout << "< ScavTrap > - " << this->name << " is now in Gate keeper mode." << std::endl;
}
