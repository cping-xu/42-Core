/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:20:37 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/03 17:49:12 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain *brain;
		
	public :
		Cat();
		virtual ~Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);

		virtual void	makeSound() const;
		Brain			*get_brain() const;
};

#endif
