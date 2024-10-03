/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:24:10 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/19 19:04:08 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template<typename T>
void iter(T* array, std::size_t length, void (*f)(const T&)) 
{
	for (std::size_t i = 0; i < length; ++i) 
	{
		f(array[i]);
	}
}

#endif
