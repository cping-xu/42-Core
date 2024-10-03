/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:14:44 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/02 18:14:44 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    private:
        int                 fixedPointValue;
        static const int    fractionalBits = 8;

    public:
        Fixed();
        Fixed(const Fixed &copy);
        Fixed &operator=(const Fixed &copy);
        ~Fixed();

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

#endif
