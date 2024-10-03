/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:32:33 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/19 19:02:02 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

#include <iostream>

int main(int argc, char *argv[]) {
	if (argc == 1)
	{
		std::cout << "Error: Invalid Input\n" << "./convert [input]" << std::endl;
		return 1;
	}
	Scalar::convert(argv[1]);

	return 0;
}
