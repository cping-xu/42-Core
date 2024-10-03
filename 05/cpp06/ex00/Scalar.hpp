/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:33:34 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/23 14:38:27 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <string>

class Scalar {
	public:
		~Scalar();

		static void convert(const std::string& literal);

	private:
		Scalar();
		Scalar(const Scalar& other);
		Scalar& operator=(const Scalar& other);
};

#endif
