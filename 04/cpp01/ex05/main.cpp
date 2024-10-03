/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:26:39 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/02 18:12:16 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( void )
{

    std::string input;
    Harl        harl;

    do
    {
        std::cout << "( DEBUG / INFO / WARNING / ERROR )" << std::endl;
        std::cout << "Enter a level: ";
        std::cin >> input;
        harl.complain(input);
    } while (input.compare("EXIT"));

    return (0);
}
