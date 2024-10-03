/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:14:16 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/02 16:16:14 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon*     weapon;

	public:
		HumanB( std::string name );
		~HumanB();

		void    attack( void ) const;
		void    setWeapon( Weapon& weapon );
};

