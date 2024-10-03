/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:27:11 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/02 16:27:13 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class   Harl
{
    private:
        void    debug( void );
        void    info( void );
        void    warning( void );
        void    error( void );

    public:
        Harl();
        ~Harl();
        void    complain( std:: string level );
};

typedef void (Harl::*t_func) ( void );
