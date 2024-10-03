/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:57:19 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/24 13:52:15 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

int main(void)
{
	Base identifier;

	Base* f = identifier.generate();
	
	identifier.identify(f);
	identifier.identify(*f);
	delete f;
}
