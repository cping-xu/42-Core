/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:24:13 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/24 16:08:46 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void swap(T& a, T& b)
{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
const T& max(const T& x, const T& y)
{
	if (x > y) 
		return x;
	return y;
}

template<typename T>
const T& min(const T& x, const T& y)
{
	if (x < y)
		return x;
	return y;
}

#endif
