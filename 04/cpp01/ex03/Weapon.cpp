/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:14:31 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/02 16:14:32 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type) {
    this->setType(type);
}

Weapon::~Weapon() {
}

const   std::string& Weapon::getType( void ) {
    return (this->type);
}

void    Weapon::setType( std::string newType ) {
    this->type = newType;
}
