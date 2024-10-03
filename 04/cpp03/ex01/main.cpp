/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:32:18 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/02 18:32:18 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap ash( "Ash" );
    ScavTrap ash2( ash );

    ash.attack( "the air" );
    ash.takeDamage( 10 );
    ash.beRepaired( 10 );
    ash.guardGate();

    return (0);
}
