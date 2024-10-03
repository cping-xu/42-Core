/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:14:04 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/02 16:25:37 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : name(name), weapon(weapon) {
}

HumanA::~HumanA()
{
}

void    HumanA::attack( void ) const {
    if (this->weapon.getType() != "") {
        std::cout << name << " attacks with their " << this->weapon.getType() << std::endl;
    } else {
        std::cout << name << " doesn't have a weapon to attack." << std::endl;
    }
}
