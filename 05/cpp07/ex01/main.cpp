/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:24:05 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/19 19:04:04 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#include <iostream>

template<typename T>
void debug(const T& var) 
{
	std::cout << var << std::endl;
}

template<typename T>
void increment(const T& var) 
{
	++(const_cast<T&>(var));
}

int main() {
	int intArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::string strArray[4] = {"abc", "dfg", "hij", "klm"};

	std::cout << "INT ARRAY:\n" << std::endl;
	::iter(intArray, 10, &debug);

	std::cout << "\nINT ARRAY (after increment):\n" << std::endl;
	::iter(intArray, 10, &increment);
	::iter(intArray, 10, &debug);

	std::cout << "\nSTRING ARRAY:\n" << std::endl;
	::iter(strArray, 4, &debug);

	return 0;
}
