/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:32:33 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/02 18:32:35 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
        ScavTrap();

    public:
        ScavTrap( std::string name );
        ~ScavTrap();

        void    attack(std::string const& target);
        void    guardGate();
};

#endif
