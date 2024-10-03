/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:20:31 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/03 17:44:00 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
	protected :
		std::string type;

	public :
		AAnimal();
		virtual ~AAnimal();
		AAnimal(const AAnimal &other);
		virtual AAnimal &operator=(const AAnimal &other);
		virtual void makeSound() const = 0;

		std::string getType() const;
};

#endif
