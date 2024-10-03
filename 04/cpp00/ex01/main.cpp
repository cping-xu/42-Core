/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:20:41 by cping-xu          #+#    #+#             */
/*   Updated: 2024/02/02 14:28:34 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <limits>
#include <iostream>

int main(void) {
    Phonebook pb;
    std::string input = "";
    pb.enter();
    while (input.compare("EXIT")) {
        if (input.compare("ADD") == 0)
            pb.add_contact();
        else if (input.compare("SEARCH") == 0) 
            pb.search_contact();
        std::cout << "Enter (EXIT / ADD / SEARCH) > " << std::flush;
        std::cin >> input;
        std::cout << std::endl;
    }
    return (0);
}
