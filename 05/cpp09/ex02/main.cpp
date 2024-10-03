/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:09:42 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/19 18:36:06 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>

double processTime(clock_t start, clock_t end){
	double time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000000;	//devide by us
	return (time_taken);
}

int main(int argc, char **argv)
{
	if (argc < 3){
		std::cerr << "Error: Invalid Arguments." << std::endl;
		return 0;
	}
	try
	{
		PmergeMe merge;
		clock_t start, end;
		
		merge.ParseNumbers(++argv);
		std::cout << "Before: ";
		merge.PrintVector();
		if (merge.isSorted())
			throw (std::invalid_argument("Input is sorted"));
		std::ios_base::sync_with_stdio(false);
		start = clock();
		merge.MergeSort(merge.getVector(), 0, merge.getVector().size() - 1, 10);
		end = clock();
		start = clock();
		merge.MergeSort(merge.getDeque(), 0, merge.getDeque().size() - 1, 10);
		end = clock();
		std::cout << "After: ";
		merge.PrintVector();
		std::cout << "Time to process a range of " << merge.getVector().size() << " elements with std::vector<int> : " << processTime(start, end) <<  " us" << std::endl;
		std::cout << "Time to process a range of " << merge.getDeque().size() << " elements with std::deque<int> : " << processTime(start, end) << " us" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	catch(int myNum)
	{
		std::cerr << "Error: " << myNum << std::endl;
		return 1;
	}
}
