/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:34:55 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/24 13:45:14 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>

struct Data {
	int n;
};

uintptr_t serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main()
{
	Data	*data;
	uintptr_t	rawData;
	Data	*retData;
	uintptr_t	seData;

	data = new Data;
	std::cout << "Data			: " << data << std::endl;
	rawData = serialize(data);
	std::cout << "Raw data		: " << rawData << std::endl;
	retData = deserialize(rawData);
	std::cout << "Deserialized data	: " << retData << std::endl;
	seData = serialize(data);
	std::cout << "Serialized data		: " << seData << std::endl;
	delete (data);
	
	return (0);
}
