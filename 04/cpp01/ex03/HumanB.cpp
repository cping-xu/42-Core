/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:14:12 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/02 16:14:13 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : name(name) {
    this->weapon = NULL;
}

HumanB::~HumanB()
{
}

void    HumanB::setWeapon( Weapon& weapon ) {
    this->weapon = &weapon;
}

void    HumanB::attack( void ) const {
    if (this->weapon != NULL && this->weapon->getType() != "") {
        std::cout << name << " attacks with their " << this->weapon->getType() << std::endl;
    } else {
        std::cout << name << " doesn't have a weapon to attack." << std::endl;
    }
}
