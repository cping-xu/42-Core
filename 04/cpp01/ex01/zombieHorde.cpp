/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:20:06 by cping-xu          #+#    #+#             */
/*   Updated: 2023/08/31 17:33:01 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	int i;

	i = 0;
	Zombie *horde = new Zombie[N];
	while (i < N)
	{
		horde[i].setName(name);
		i++;
	}
	return (horde);
}
