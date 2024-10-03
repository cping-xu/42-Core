/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:57:25 by cping-xu          #+#    #+#             */
/*   Updated: 2024/04/24 13:53:28 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include <ctime>

//Constructor and destructor
Base::Base(){
	std::cout << "Base constructor called" << std::endl;
}

Base::~Base(){
	std::cout << "Base Destructor called" << std::endl;
}

A::A(){
	std::cout << "A constructor called" << std::endl;
}

A::~A(){
	std::cout << "A Destructor called" << std::endl;
}

B::B(){
	std::cout << "B constructor called" << std::endl;
}

B::~B(){
	std::cout << "B Destructor called" << std::endl;
}

C::C(){
	std::cout << "C constructor called" << std::endl;
}

C::~C(){
	std::cout << "C Destructor called" << std::endl;
}

Base* Base::generate(void)
{
	std::time_t localTime = std::time(0);
	std::tm* ltm = std::localtime(&localTime);
	srand(ltm->tm_sec);
	int num = (rand() % 3);	//random generate num
	if (num == 0)
		return (new A);
	else if (num == 1)
		return (new B);
	else if (num == 2)
		return (new C);
	return (nullptr);	
}

void Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "From *: A!" << std::endl;
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "From *: B!" << std::endl;
	else
		std::cout << "From *: C!" << std::endl;
}

void Base::identify(Base& p)
{
	try
	{
    	A a = dynamic_cast<A&>(p);
		std::cout << "From &: A!" << std::endl;
	}
	catch (const std::bad_cast& e)
	{
		try
		{
			B b = dynamic_cast<B&>(p);
			std::cout << "From &: B!" << std::endl;
		}
		catch(const std::bad_cast& e)
		{
			std::cout << "From &: C!" << std::endl;
		}
	}
}
