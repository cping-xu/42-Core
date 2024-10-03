/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:20:44 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/03 17:49:14 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain *brain;
		
	public :
		Dog();
		virtual ~Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);

		virtual void	makeSound() const;
		Brain			*get_brain() const;
};

#endif
