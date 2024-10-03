/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:20:41 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/25 11:58:06 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template<typename T>
typename T::iterator easyfind(T& container, int occurrence) {
	typename T::iterator iter = std::find(container.begin(), container.end(), occurrence);
	return (iter); // it will be container.end() if occurrence can't be found
}

#endif
