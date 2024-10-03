/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:21:50 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/25 12:41:28 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "RPN.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Error: " << argv[0] << " \"[operation]\"\n";
		return 1;
	}
	
	try 
	{
		int res = RPN::ResolveExpression(argv[1]);
		std::cout << "Result: " << res << '\n';
	}
	catch (std::exception &e) 
	{
		std::cerr << "Exception: " << e.what() << '\n';
		return 1;
	}
	
	return 0;
}
