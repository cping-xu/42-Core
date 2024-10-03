/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:20:46 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/24 14:25:34 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main() {
	std::vector<int> v;
	std::vector<int>::iterator iter;

	for (int i = 0; i < 10; ++i) {
		v.push_back(i * i);
	}
	std::cout << "Vector:" << std::endl;
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i) 
	{
		std::cout << *i << std::endl;
	}
	std::cout << std::endl;

	iter = easyfind(v, -3);
	if (iter == v.end()) 
		std::cout << "Not found" << std::endl;
	else 
		std::cout << "iterator: " << *iter << std::endl;

	iter = easyfind(v, 2);
	if (iter == v.end()) 
		std::cout << "Not found" << std::endl;
	else 
		std::cout << "iterator: " << *iter << std::endl;

	iter = easyfind(v, 25);
	if (iter == v.end()) 
		std::cout << "Not found" << std::endl;
	else 
		std::cout << "iterator: " << *iter << std::endl;

	iter = easyfind(v, 81);
	if (iter == v.end()) 
		std::cout << "Not found" << std::endl;
	else 
		std::cout << "iterator: " << *iter << std::endl;

	return 0;
}
