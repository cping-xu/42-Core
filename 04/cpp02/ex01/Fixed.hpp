/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:15:05 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/02 18:15:05 by cping-xu         ###   ########.fr       */
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
        Fixed(const int n);
        Fixed(const float n);
        Fixed &operator=(const Fixed &copy);
        Fixed(const Fixed &copy);
        ~Fixed();
        
        int     getRawBits()const;
        void    setRawBits(int const raw);
        float   toFloat()const;
        int     toInt()const;
};

std::ostream &operator << (std::ostream &stream, const Fixed &copy);

#endif
