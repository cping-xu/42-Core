/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:14:08 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/02 16:14:09 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA
{
private:
    std::string name;
    Weapon&     weapon;
    HumanA();

public:
    HumanA( std::string name, Weapon& weapon );
    ~HumanA();

    void    attack( void ) const;
};
