/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:09:00 by cping-xu          #+#    #+#             */
/*   Updated: 2024/05/02 19:20:56 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
}

PmergeMe::~PmergeMe(){
}

PmergeMe::PmergeMe(PmergeMe const &other){
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other){
	if (this == &other)
		return (*this);
	return (*this);
}

bool is_digit(char *argv){
	int size = std::strlen(argv);
	for (int i = 0; i < size; i++){
		if (argv[i] == '-' || argv[i] == '+')
			continue ;
        if (!(argv[i] >= 48 && argv[i] <= 57)) {
            return false;
		}
	}
	return true;
}

void PmergeMe::ParseNumbers(char **argv){
	while (*argv != NULL){

		if (!is_digit(*argv))
			throw(std::invalid_argument("Input numeric values"));
		int num = std::atoi(*argv);
		if (num < 0)
			throw(std::invalid_argument("Input positive values"));
		this->deque.push_back(num);
		this->vector.push_back(num);
		argv++;		
	}
}

bool PmergeMe::isSorted(void) {
	if (vector.empty())
		return (false);
		
	for (size_t i = 0; i < vector.size() - 1; ++i)
		for (size_t j = i + 1; j < vector.size(); ++j)
			if (vector[i] > vector[j])
				return (false);

	return (true);
}

void PmergeMe::PrintVector(void){
	for (std::vector<int>::iterator iter = vector.begin(); iter != vector.end(); iter++){
		std::cout << *iter;
		if (iter != vector.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}
