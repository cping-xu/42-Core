/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:14:53 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/02 18:14:53 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : fixedPointValue(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (const int n) {
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = n << Fixed::fractionalBits;
}

Fixed::Fixed( const float n ) {
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(n * (1 << fractionalBits));
}

Fixed::Fixed( const Fixed &copy ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed& Fixed::operator=( const Fixed &copy ) {
    std::cout << "Copy assignment operator called" << std::endl;
    if ( this != &copy )
        this->fixedPointValue = copy.getRawBits();
    return *(this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    return (this->fixedPointValue);
}

void    Fixed::setRawBits( int const raw ) {
    this->fixedPointValue = raw;
}

float   Fixed::toFloat( void ) const {
    return (static_cast<float>( this->getRawBits() ) / ( 1 << fractionalBits ));
}

int     Fixed::toInt( void ) const {
    return (this->fixedPointValue >> fractionalBits);
}

std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
    o << i.toFloat();
    return (o);
}
