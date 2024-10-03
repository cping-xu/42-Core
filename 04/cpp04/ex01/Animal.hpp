/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:20:31 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/02 18:57:57 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected :
		std::string type;

	public :
		Animal();
		virtual ~Animal();
		Animal(const Animal &other);
		virtual Animal &operator=(const Animal &other);
		virtual void makeSound() const;

		std::string getType() const;
};

#endif
