/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:15:31 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/02 18:15:31 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
}

Fixed::Fixed (const int n)
{
    this->fixedPointValue = n << fractionalBits;
}

Fixed::Fixed (const float n)
{
    this->fixedPointValue = roundf(n * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &copy)
{
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    if (this != &copy)
        this->fixedPointValue = copy.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
}

bool    Fixed::operator>(const Fixed &copy) const
{
    return (this->getRawBits() > copy.getRawBits());
}

bool    Fixed::operator<(const Fixed &copy) const
{
    return (this->getRawBits() < copy.getRawBits());
}

bool    Fixed::operator>=(const Fixed &copy) const
{
    return (this->getRawBits() >= copy.getRawBits());
}

bool    Fixed::operator<=(const Fixed &copy) const
{
    return (this->getRawBits() <= copy.getRawBits());
}

bool    Fixed::operator!=(const Fixed &copy) const
{
    return (this->getRawBits() != copy.getRawBits());
}

bool    Fixed::operator==(const Fixed &copy) const
{
    return (this->getRawBits() == copy.getRawBits());
}

Fixed   Fixed::operator+(const Fixed &copy) const
{
    return (Fixed(this->toFloat() + copy.toFloat()));
}

Fixed   Fixed::operator-(const Fixed &copy) const
{
    return (Fixed(this->toFloat() - copy.toFloat()));
}

Fixed   Fixed::operator*(const Fixed &copy) const
{
    return (Fixed(this->toFloat() * copy.toFloat()));
}

Fixed   Fixed::operator/(const Fixed &copy) const
{
    return (Fixed(this->toFloat() / copy.toFloat()));
}

Fixed   &Fixed::operator++()
{
    this->fixedPointValue++;
    return (*this);
}

Fixed   &Fixed::operator--()
{
    this->fixedPointValue--;
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed temp(*this);
    temp.fixedPointValue = this->fixedPointValue++;
    return (temp);
}

Fixed   Fixed::operator--(int)
{
    Fixed temp(*this);
    temp.fixedPointValue = this->fixedPointValue--;
    return (temp);
}

int Fixed::getRawBits() const
{
    return (this->fixedPointValue);
}

void    Fixed::setRawBits(int const raw)
{
    this->fixedPointValue = raw;
}

float   Fixed::toFloat() const
{
    return ((float)this->fixedPointValue / (1 << fractionalBits));
}

int Fixed::toInt() const
{
    return ((int)this->fixedPointValue >> fractionalBits);
}

Fixed   &Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

Fixed   &Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

std::ostream &operator << (std::ostream &stream, const Fixed &copy)
{
    stream << copy.toFloat();
    return (stream);
}
