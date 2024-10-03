/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:44:53 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/02 16:09:25 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *horde = zombieHorde(5, "Zombieee");
	int i = 0;
	while (i < 5)
	{
		horde[i].announce();
		i++;
	}
	delete []horde;
	return (0);
}
