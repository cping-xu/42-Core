/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:31:34 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/02 18:31:38 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
    private:
        std::string     name;
        unsigned int    hitPoints;
        unsigned int    energyPoints;
        unsigned int    attackDamage;

        ClapTrap();

    public:
        ClapTrap( std::string name );
        ~ClapTrap();
        ClapTrap(const ClapTrap &);
        ClapTrap &operator=(const ClapTrap& copy);

        void    attack(std::string const& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
};

#endif
