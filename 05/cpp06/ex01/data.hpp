/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:35:25 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/19 18:48:28 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <cstdint>

struct Data 
{
	int n;
};

uintptr_t serialize(Data *ptr);

Data* deserialize(uintptr_t raw);

#endif
