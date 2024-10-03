/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:31:29 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/02 18:31:30 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name1 ) : name(name1), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " is born!" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap destructor called" << std::endl;
    return;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    *this = copy;
    std::cout << "ClapTrap copy constructor called" << std::endl;
    return;
}

ClapTrap&   ClapTrap::operator=( const ClapTrap& copy ) {
    this->name = copy.name;
    this->hitPoints = copy.hitPoints;
    this->energyPoints = copy.energyPoints;
    this->attackDamage = copy.attackDamage;
    return (*this);
}

void    ClapTrap::attack( std::string const& target )
{
    if (energyPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
    energyPoints -= 1;
}

void    ClapTrap::takeDamage( unsigned int amount )
{
    if (hitPoints <= amount)
    {
        std::cout << "ClapTrap " << name << " is dead!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " takes " << amount << " damage!" << std::endl;
    hitPoints -= amount;
}

void    ClapTrap::beRepaired( unsigned int amount )
{
    if (energyPoints <= amount)
    {
        std::cout << "ClapTrap " << name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " repairs itself for " << amount << " hit points!" << std::endl;
    energyPoints -= 1;
    hitPoints += amount;
}
