/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:38:02 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/17 15:40:18 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Error: Invalid number of arguments."
			  << "Usage: " << argv[0] << " INPUT_FILE\n";
		return 1;
	}

	BitcoinExchange exchange("data.csv");
	exchange.ProcessInput(argv[1]);

	return 0;
}
