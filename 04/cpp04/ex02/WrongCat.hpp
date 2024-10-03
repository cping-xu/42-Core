/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:21:34 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/02 18:55:18 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public :
		WrongCat();
		virtual ~WrongCat();
		WrongCat(const WrongCat &other);
		WrongCat &operator=(const WrongCat &other);

		virtual void makeSound() const;
};

#endif
