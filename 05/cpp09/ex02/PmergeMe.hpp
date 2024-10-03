/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:08:43 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/25 21:28:56 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <time.h>
#include <deque>
#include <vector>

class PmergeMe
{
	private:
		std::deque<int> deque;
		std::vector<int> vector;
		
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const &other);
		PmergeMe& operator=(const PmergeMe &other);
		void ParseNumbers(char **argv);
		bool isSorted(void);
		// void PrintDeque(void);
		void PrintVector(void);
		
		template<typename Container>
		void InsertionSort(Container& array, int left, int right)
		{
			for (int i = left + 1; i <= right; i++)
			{
				int tmp = array[i];
				int j = i - 1;
				while ((j >= left) && (array[j] > tmp)) {
					array[j + 1] = array[j];
					j--;
				}
				array[j + 1] = tmp;
			}
		}
		
			// // for (size_t i = 0; i < array.size() - 1; ++i)
			// 	std::cout << "val: " ;
			// 	for (size_t j = 0; j < array.size(); ++j)
			// 		std::cout << array[j] ;
			// 	std::cout << std::endl;
		template<typename Container>
		void MergeSort(Container& array, int left, int right, int size)
		{
			if (right - left <= 1)
			{
				InsertionSort(array, left, right);
			}
			else
			{
				int middle = left + (right - left) / 2;
				MergeSort(array, left, middle, size);
				MergeSort(array, middle + 1, right, size);
				Merge(array, left, right, middle);
			}
		}
		
		template<typename Container>
		void Merge(Container& array, int left, int right, int middle)
		{
			int i = 0, j = 0, k = left;

			int s1 = (middle - left) + 1;	//get size for left chunk
			int s2 = (right - middle);		//get size for right chunk
			
			Container ArrayL(s1);
			Container ArrayR(s2);

			for (i = 0; i < s1; ++i)
				ArrayL[i] = array[left + i];
			for (j = 0; j < s2; ++j)
				ArrayR[j] = array[middle + 1 + j];

			i = 0, j = 0;
			while (i < s1 && j < s2) 
			{
				if (ArrayL[i] <= ArrayR[j]) 
				{
					array[k++] = ArrayL[i++];
				}
				else 
				{
					array[k++] = ArrayR[j++];
				}
			}
			while (i < s1) {
				array[k++] = ArrayL[i++];
			}
			while (j < s2) {
				array[k++] = ArrayR[j++];
			}
		}
		
		std::vector<int>& getVector(void) {return vector;} 
		std::deque<int>& getDeque(void) {return deque;}
};
