/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:45:41 by cping-xu          #+#    #+#             */
/*   Updated: 2023/08/31 17:33:06 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie{

private:
	std::string name;

public:
	Zombie();
	~Zombie();
	void	setName(std::string name);
	void	announce(void);
	Zombie	*zombieHorde(int N, std::string name);
};

Zombie	*zombieHorde(int N, std::string name);

#endif
