/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:21:20 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/02 18:55:02 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	protected :
		std::string type;

	public :
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		virtual WrongAnimal &operator=(const WrongAnimal &other);
		void makeSound() const;

		std::string getType() const;
};

#endif
