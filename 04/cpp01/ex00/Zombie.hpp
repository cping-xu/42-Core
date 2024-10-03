/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:07:52 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/02 16:05:36 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{  
    private:
        std::string name;

    public:
        Zombie( std::string name );
        ~Zombie();
        void    announce( void );
        Zombie* newZombie( std::string name );
        void    randomChump( std::string name );
};

Zombie  *newZombie( std::string name );
void    randomChump( std::string name );

#endif
